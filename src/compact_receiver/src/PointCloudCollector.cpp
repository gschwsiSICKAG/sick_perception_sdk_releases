/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

#include <sick_perception_sdk/compact_receiver/PointCloudCollector.hpp>

#include <sick_perception_sdk/common/logging/logging.hpp>
#include <sick_perception_sdk/common/quantities/Angle.hpp>
#include <sick_perception_sdk/common/quantities/Duration.hpp>
#include <sick_perception_sdk/common/quantities/Timestamp.hpp>
#include <sick_perception_sdk/compact_receiver/PointCloud.hpp>
#include <sick_perception_sdk/compact_receiver/ScanData.hpp>

#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <cstring> // for std::memcpy
#include <functional>
#include <iterator>
#include <limits>
#include <map>
#include <stdexcept>
#include <utility>
#include <vector>

namespace sick::compact {

namespace {

auto bloomingMask(std::size_t echoIndex) -> std::uint8_t
{
  // bits 5 = Echo 0 has blooming, 6 = Echo 1 has blooming, 7 = Echo 2 has blooming
  constexpr std::size_t maskOffset = 5;
  return 0x01 << (maskOffset + echoIndex);
}

/**
 * @brief Validates that the module meta data contains the required beam content.
 * @throws std::runtime_error if the module does not contain the required beam content.
 */
void validateBeamContent(scan_data::Module::MetaData const& moduleMetaData, scan_data::BeamContent requiredBeamContent)
{
  if ((moduleMetaData.beamContent & requiredBeamContent) != requiredBeamContent)
  {
    if ((requiredBeamContent & scan_data::BeamContent::Azimuth) == scan_data::BeamContent::Azimuth)
    {
      if (moduleMetaData.numberOfRows != moduleMetaData.rowMetaData.size())
      {
        throw std::runtime_error("Module does not contain the required beam content. The module does not provide meta data for each row."
                                 "The beam azimuth cannot be replaced by the row azimuth.");
      }
    }
    else
    {
      throw std::runtime_error("Module does not contain the required beam content.");
    }
  }
}

/**
 * @brief Validates that the module meta data contains the required echo content.
 * @throws std::runtime_error if the module does not contain the required echo content.
 */
void validateEchoContent(scan_data::Module::MetaData const& moduleMetaData, scan_data::EchoContent requiredEchoContent)
{
  if ((moduleMetaData.echoContent & requiredEchoContent) != requiredEchoContent)
  {
    throw std::runtime_error("Module does not contain the required echo content.");
  }
}

/**
 * @brief Validates that the module meta data contains consistent number of rows.
 * @throws std::runtime_error if the module meta data contains inconsistent number of rows.
 */
void validateNumberOfRows(scan_data::Module::MetaData const& moduleMetaData)
{
  if (moduleMetaData.numberOfRows != moduleMetaData.rowMetaData.size())
  {
    throw std::runtime_error("Module meta data has inconsistent number of rows.");
  }
}

void validateScanData(scan_data::ScanData const& scanData, scan_data::BeamContent requiredBeamContent, scan_data::EchoContent requiredEchoContent)
{
  for (auto const& module : scanData.modules)
  {
    validateBeamContent(module.metaData, requiredBeamContent);
    validateEchoContent(module.metaData, requiredEchoContent);
    validateNumberOfRows(module.metaData);
  }
}

/**
 * @brief Computes the layer id from the elevation angles.
 * @details The compact format does not contain layer ids. However, layer ids are used in filtering and can be added as
 * an additional field to the point cloud. CAUTION: LayerIds computed here might not correspond to the layers in the
 * sensor GUI if some layers are deactivated. This is because layer which are deactivated in the GUI are not sent in the
 * scan data at all. Layer IDs are descending with ascending elevation angle. LayerIds start at 1.
 */
auto getElevationToLayerIdMapping(scan_data::ScanData const& scanData) -> std::map<Angle, std::int8_t>
{
  std::vector<Angle> allElevations;
  for (auto const& module : scanData.modules)
  {
    std::transform(
      module.metaData.rowMetaData.cbegin(),
      module.metaData.rowMetaData.cend(),
      std::back_inserter(allElevations),
      [](scan_data::Module::RowMetaData const& rowMetaData) -> Angle {
        return rowMetaData.elevation;
      }
    );
  }

  std::map<Angle, std::int8_t> elevationToLayerIdMapping;
  std::sort(allElevations.begin(), allElevations.end(), std::greater<>());
  for (std::size_t i = 1; i <= allElevations.size(); ++i)
  {
    elevationToLayerIdMapping[allElevations[i - 1]] = static_cast<std::int8_t>(i);
  }
  return elevationToLayerIdMapping;
}

/**
 * @brief Computes the maximum number of points that can be added to the point cloud from the given scan data.
 * @details The actual number of points which are added depends on the filter settings and the contents of the scan
 * data.
 */
auto getMaximumNumberOfPoints(scan_data::ScanData const& scanData) -> std::size_t
{
  std::size_t maximumNumberOfNewPoints = 0;
  for (auto const& module : scanData.modules)
  {
    maximumNumberOfNewPoints += static_cast<std::size_t>(module.metaData.numberOfRows) * static_cast<std::size_t>(module.metaData.numberOfColumns) *
                                static_cast<std::size_t>(module.metaData.numberOfEchoesPerBeam);
  }
  return maximumNumberOfNewPoints;
}

/**
 * @brief Computes the smallest start timestamp in the scan data.
 * @throws std::runtime_error if a timestamp smaller than the point cloud timestamp is encountered.
 */
auto getSmallestStartTimestamp(scan_data::ScanData const& scanData, PointCloud const& pointCloud) -> Timestamp
{
  auto smallestTimestampInScanData = Timestamp::fromMicrosecondsSinceEpoch(std::numeric_limits<std::uint64_t>::max());
  for (auto const& module : scanData.modules)
  {
    for (auto const& row : module.metaData.rowMetaData)
    {
      smallestTimestampInScanData = std::min(smallestTimestampInScanData, row.firstBeamTimestamp);
    }
  }

  if (pointCloud.numberOfPoints > 0 && smallestTimestampInScanData < pointCloud.header.timestamp)
  {
    throw std::runtime_error("Encountered a smaller timestamp than the one in the point cloud.");
  }

  return smallestTimestampInScanData;
}

template <typename ValueT>
auto writeValueToPointCloudData(std::vector<std::uint8_t>::iterator const& pointCloudDataWritePosition, ValueT const& value)
  -> std::vector<std::uint8_t>::iterator
{
  std::memcpy(&*(pointCloudDataWritePosition), &value, sizeof(ValueT));
  return pointCloudDataWritePosition + sizeof(ValueT);
}

auto getBeamAzimuth(
  scan_data::Module::MetaData const& moduleMetaData,
  scan_data::Beam const& beam,
  std::size_t layerIndex,
  std::size_t columnIndex,
  bool useAzimuthFromHeader,
  LayerInfo const& layerInfo
) -> Angle
{
  return useAzimuthFromHeader ? moduleMetaData.rowMetaData[layerIndex].firstBeamAzimuth + layerInfo.azimuthIncrementPerBeam * columnIndex : beam.azimuth;
}

} // namespace

PointCloudCollector::PointCloudCollector()
  : PointCloudCollector(PointCloudConfiguration())
{ }

PointCloudCollector::PointCloudCollector(PointCloudConfiguration configuration)
  : m_requiredBeamContent(scan_data::BeamContent::None)
  , m_requiredEchoContent(scan_data::EchoContent::None)
  , m_nextPointFieldOffset(0)
  , m_configuration(std::move(configuration))
{
  LOG_INFO("PointCloudCollector") << "Creating PointCloudCollector with configuration:\n" << m_configuration.toString();
  if (!m_configuration.filters.azimuth.isEmpty())
  {
    m_requiredBeamContent = m_requiredBeamContent | scan_data::BeamContent::Azimuth;
  }

  if (!m_configuration.filters.range.isEmpty())
  {
    m_requiredEchoContent = m_requiredEchoContent | scan_data::EchoContent::Distance;
  }

  if (!m_configuration.filters.intensity.isEmpty())
  {
    m_requiredEchoContent = m_requiredEchoContent | scan_data::EchoContent::Intensity;
  }

  if (m_configuration.filters.requiredReflectorFlag)
  {
    m_requiredBeamContent = m_requiredBeamContent | scan_data::BeamContent::Properties;
  }

  if (m_configuration.filters.requiredBloomingFlag)
  {
    m_requiredBeamContent = m_requiredBeamContent | scan_data::BeamContent::Properties;
  }

  if (m_configuration.fields.enableCartesian)
  {
    m_fields.push_back(PointField {"x", m_nextPointFieldOffset, PointField::Datatype::FLOAT32, 1});
    m_nextPointFieldOffset += sizeof(float);
    m_fields.push_back(PointField {"y", m_nextPointFieldOffset, PointField::Datatype::FLOAT32, 1});
    m_nextPointFieldOffset += sizeof(float);
    m_fields.push_back(PointField {"z", m_nextPointFieldOffset, PointField::Datatype::FLOAT32, 1});
    m_nextPointFieldOffset += sizeof(float);

    m_requiredBeamContent = m_requiredBeamContent | scan_data::BeamContent::Azimuth;
    m_requiredEchoContent = m_requiredEchoContent | scan_data::EchoContent::Distance;
  }

  if (m_configuration.fields.enableSpherical)
  {
    m_fields.push_back(PointField {"range", m_nextPointFieldOffset, PointField::Datatype::FLOAT32, 1});
    m_nextPointFieldOffset += sizeof(float);
    m_fields.push_back(PointField {"azimuth", m_nextPointFieldOffset, PointField::Datatype::FLOAT32, 1});
    m_nextPointFieldOffset += sizeof(float);
    m_fields.push_back(PointField {"elevation", m_nextPointFieldOffset, PointField::Datatype::FLOAT32, 1});
    m_nextPointFieldOffset += sizeof(float);

    m_requiredBeamContent = m_requiredBeamContent | scan_data::BeamContent::Azimuth;
    m_requiredEchoContent = m_requiredEchoContent | scan_data::EchoContent::Distance;
  }

  if (m_configuration.fields.enableIntensity)
  {
    m_fields.push_back(PointField {"intensity", m_nextPointFieldOffset, PointField::Datatype::FLOAT32, 1});
    m_nextPointFieldOffset += sizeof(float);

    m_requiredEchoContent = m_requiredEchoContent | scan_data::EchoContent::Intensity;
  }

  if (m_configuration.fields.enableTimeOffsetNanoseconds)
  {
    m_fields.push_back(PointField {"t", m_nextPointFieldOffset, PointField::Datatype::UINT32, 1});
    m_nextPointFieldOffset += sizeof(std::uint32_t);
  }

  if (m_configuration.fields.enableTimeOffsetSeconds)
  {
    m_fields.push_back(PointField {"ts", m_nextPointFieldOffset, PointField::Datatype::FLOAT32, 1});
    m_nextPointFieldOffset += sizeof(float);
  }

  if (m_configuration.fields.enableRing)
  {
    m_fields.push_back(PointField {"ring", m_nextPointFieldOffset, PointField::Datatype::INT8, 1});
    m_nextPointFieldOffset += sizeof(std::int8_t);
  }

  if (m_configuration.fields.enableLayer)
  {
    m_fields.push_back(PointField {"layer", m_nextPointFieldOffset, PointField::Datatype::INT8, 1});
    m_nextPointFieldOffset += sizeof(std::int8_t);
  }

  if (m_configuration.fields.enableEcho)
  {
    m_fields.push_back(PointField {"echo", m_nextPointFieldOffset, PointField::Datatype::INT8, 1});
    m_nextPointFieldOffset += sizeof(std::int8_t);
  }

  if (m_configuration.fields.enableIsReflector)
  {
    m_fields.push_back(PointField {"isReflector", m_nextPointFieldOffset, PointField::Datatype::UINT8, 1});
    m_nextPointFieldOffset += sizeof(std::uint8_t);

    m_requiredBeamContent = m_requiredBeamContent | scan_data::BeamContent::Properties;
  }

  if (m_configuration.fields.enableHasBlooming)
  {
    m_fields.push_back(PointField {"hasBlooming", m_nextPointFieldOffset, PointField::Datatype::UINT8, 1});
    m_nextPointFieldOffset += sizeof(std::uint8_t);

    m_requiredBeamContent = m_requiredBeamContent | scan_data::BeamContent::Properties;
  }

  reset();
}

void PointCloudCollector::resizePointCloudDataBuffer(scan_data::ScanData const& scanData)
{
  auto const newMaximumNumberOfPoints = m_pointCloud.numberOfPoints + getMaximumNumberOfPoints(scanData);
  LOG_FAST_LOOP_INFO("PointCloudCollector") << "Resizing point cloud data buffer to fit " << newMaximumNumberOfPoints << " points.";
  auto const numberOfBytesWritten = std::distance(m_pointCloud.data.begin(), m_pointCloudDataWritePosition);
  m_pointCloud.data.resize(newMaximumNumberOfPoints * m_pointCloud.pointStep);
  m_pointCloudDataWritePosition = m_pointCloud.data.begin() + numberOfBytesWritten;
}

auto PointCloudCollector::calculateLayerInfo(
  scan_data::Module::MetaData const& moduleMetaData,
  std::map<Angle, std::int8_t> const& elevationToLayerIdMapping,
  bool useAzimuthFromHeader
) const -> std::vector<LayerInfo>
{
  using namespace sick::literals; // NOLINT(google-build-using-namespace)
  std::vector<LayerInfo> layerInfos = std::vector<LayerInfo>(moduleMetaData.numberOfRows, {0, false, 0.0f, 0.0f, 0_ms, 0_ms, 0_rad});

  for (std::size_t layerIndex = 0; layerIndex < moduleMetaData.numberOfRows; layerIndex++)
  {
    auto const elevation = moduleMetaData.rowMetaData[layerIndex].elevation;
    auto const layerIdIt = elevationToLayerIdMapping.find(elevation);
    assert(layerIdIt != elevationToLayerIdMapping.end());

    std::int8_t const layerId = layerIdIt->second;

    layerInfos[layerIndex].id = layerId;
  }

  for (std::size_t layerIndex = 0; layerIndex < moduleMetaData.numberOfRows; layerIndex++)
  {
    if (m_configuration.filters.selectedLayers.has_value() &&
        m_configuration.filters.selectedLayers->find(static_cast<std::uint32_t>(layerInfos[layerIndex].id)) == m_configuration.filters.selectedLayers->end())
    {
      continue;
    }

    if (!m_configuration.filters.elevation.contains(moduleMetaData.rowMetaData[layerIndex].elevation))
    {
      continue;
    }

    layerInfos[layerIndex].isInPointCloud = true;
  }

  if (m_configuration.fields.enableCartesian)
  {
    for (std::size_t layerIndex = 0; layerIndex < moduleMetaData.numberOfRows; layerIndex++)
    {
      layerInfos[layerIndex].sinElevation = std::sin(moduleMetaData.rowMetaData[layerIndex].elevation.radians());
      layerInfos[layerIndex].cosElevation = std::cos(moduleMetaData.rowMetaData[layerIndex].elevation.radians());
    }
  }

  if (m_configuration.fields.enableTimeOffsetNanoseconds || m_configuration.fields.enableTimeOffsetSeconds)
  {
    for (std::size_t layerIndex = 0; layerIndex < moduleMetaData.numberOfRows; layerIndex++)
    {
      auto const firstBeamTimestampOffset              = moduleMetaData.rowMetaData[layerIndex].firstBeamTimestamp - m_pointCloud.header.timestamp;
      layerInfos[layerIndex].firstBeamTimestampOffset  = firstBeamTimestampOffset;
      auto const layerStopOffset                       = moduleMetaData.rowMetaData[layerIndex].lastBeamTimestamp - m_pointCloud.header.timestamp;
      layerInfos[layerIndex].timestampIncrementPerBeam = (layerStopOffset - firstBeamTimestampOffset) / std::max(1u, moduleMetaData.numberOfColumns - 1);
    }
  }

  if (useAzimuthFromHeader)
  {
    for (std::size_t layerIndex = 0; layerIndex < moduleMetaData.numberOfRows; layerIndex++)
    {
      layerInfos[layerIndex].azimuthIncrementPerBeam =
        (moduleMetaData.rowMetaData[layerIndex].lastBeamAzimuth - moduleMetaData.rowMetaData[layerIndex].firstBeamAzimuth) /
        std::max(1u, moduleMetaData.numberOfColumns - 1);
    }
  }

  return layerInfos;
}

void PointCloudCollector::writeEcho(
  scan_data::Echo const& echo,
  float cosAzimuth,
  float sinAzimuth,
  Angle elevation,
  Angle azimuth,
  LayerInfo const& layerInfo,
  std::uint32_t beamTimestampOffsetNanoseconds,
  std::uint32_t beamTimestampOffsetSeconds,
  std::size_t echoIndex,
  bool isAReflector,
  bool hasBlooming
)
{
  float const distanceScaled = echo.distance.meters() * m_configuration.distanceScalingFactor;
  if (m_configuration.fields.enableCartesian)
  {
    if (echo.distance.meters() < 0.0f)
    {
      return;
    }

    float const x = layerInfo.cosElevation * cosAzimuth * distanceScaled; // NOLINT(readability-identifier-length)
    float const y = layerInfo.cosElevation * sinAzimuth * distanceScaled; // NOLINT(readability-identifier-length)
    float const z = -layerInfo.sinElevation * distanceScaled;             // NOLINT(readability-identifier-length)

    m_pointCloudDataWritePosition = writeValueToPointCloudData(m_pointCloudDataWritePosition, x);
    m_pointCloudDataWritePosition = writeValueToPointCloudData(m_pointCloudDataWritePosition, y);
    m_pointCloudDataWritePosition = writeValueToPointCloudData(m_pointCloudDataWritePosition, z);
  }

  if (m_configuration.fields.enableSpherical)
  {
    if (echo.distance.meters() < 0.0f)
    {
      return;
    }

    m_pointCloudDataWritePosition = writeValueToPointCloudData(m_pointCloudDataWritePosition, distanceScaled);
    m_pointCloudDataWritePosition = writeValueToPointCloudData(m_pointCloudDataWritePosition, azimuth);
    m_pointCloudDataWritePosition = writeValueToPointCloudData(m_pointCloudDataWritePosition, elevation);
  }

  if (m_configuration.fields.enableIntensity)
  {
    m_pointCloudDataWritePosition = writeValueToPointCloudData(m_pointCloudDataWritePosition, echo.intensity);
  }

  if (m_configuration.fields.enableTimeOffsetNanoseconds)
  {
    m_pointCloudDataWritePosition = writeValueToPointCloudData(m_pointCloudDataWritePosition, beamTimestampOffsetNanoseconds);
  }

  if (m_configuration.fields.enableTimeOffsetSeconds)
  {
    m_pointCloudDataWritePosition = writeValueToPointCloudData(m_pointCloudDataWritePosition, beamTimestampOffsetSeconds);
  }

  if (m_configuration.fields.enableRing)
  {
    m_pointCloudDataWritePosition = writeValueToPointCloudData(m_pointCloudDataWritePosition, layerInfo.id);
  }

  if (m_configuration.fields.enableLayer)
  {
    m_pointCloudDataWritePosition = writeValueToPointCloudData(m_pointCloudDataWritePosition, layerInfo.id);
  }

  if (m_configuration.fields.enableEcho)
  {
    auto const echoId             = static_cast<std::int8_t>(echoIndex);
    m_pointCloudDataWritePosition = writeValueToPointCloudData(m_pointCloudDataWritePosition, echoId);
  }

  if (m_configuration.fields.enableIsReflector)
  {
    std::int8_t const isReflector = isAReflector ? 1 : 0;
    m_pointCloudDataWritePosition = writeValueToPointCloudData(m_pointCloudDataWritePosition, isReflector);
  }

  if (m_configuration.fields.enableHasBlooming)
  {
    std::int8_t const hasBloomingInt8 = hasBlooming ? 1 : 0;
    m_pointCloudDataWritePosition     = writeValueToPointCloudData(m_pointCloudDataWritePosition, hasBloomingInt8);
  }
}

auto PointCloudCollector::skipEcho(scan_data::Beam const& beam, scan_data::Echo const& echo, std::size_t echoIndex, bool echoIsTheLastValidEcho) const -> bool
{
  if (m_configuration.filters.selectedEchos.has_value() &&
      m_configuration.filters.selectedEchos->find(echoIndex) == m_configuration.filters.selectedEchos->end())
  {
    return true;
  }

  if (!m_configuration.filters.range.contains(echo.distance))
  {
    return true;
  }

  if (!m_configuration.filters.intensity.contains(echo.intensity))
  {
    return true;
  }

  // Filter reflectors, bit 0 = Reflector
  bool const thisEchoIsAReflector = echoIsTheLastValidEcho && (beam.properties & 0x01) != 0;
  if (m_configuration.filters.requiredReflectorFlag.has_value() && *m_configuration.filters.requiredReflectorFlag != thisEchoIsAReflector)
  {
    return true;
  }

  // Filter blooming
  bool const echoHasBlooming = (beam.properties & bloomingMask(echoIndex)) != 0;
  return m_configuration.filters.requiredBloomingFlag.has_value() && *m_configuration.filters.requiredBloomingFlag != echoHasBlooming;
}

void PointCloudCollector::collect(scan_data::ScanData const& scanData)
{
  validateScanData(scanData, m_requiredBeamContent, m_requiredEchoContent);

  resizePointCloudDataBuffer(scanData);

  m_pointCloud.header.timestamp = getSmallestStartTimestamp(scanData, m_pointCloud);

  auto const elevationToLayerIdMapping = getElevationToLayerIdMapping(scanData);

  auto const pointCloudDataWritePositionBefore = m_pointCloudDataWritePosition;

  for (auto const& module : scanData.modules)
  {
    // True if the azimuth angles are required but not provided as part of the beam data.
    bool const useAzimuthFromHeader = (module.metaData.beamContent & scan_data::BeamContent::Azimuth) == scan_data::BeamContent::None &&
                                      (m_requiredBeamContent & scan_data::BeamContent::Azimuth) == scan_data::BeamContent::Azimuth;

    auto const layerInfos = calculateLayerInfo(module.metaData, elevationToLayerIdMapping, useAzimuthFromHeader);

    for (std::size_t columnIndex = 0; columnIndex < module.columns.size(); columnIndex++)
    {
      auto const& column = module.columns[columnIndex];
      for (std::size_t layerIndex = 0; layerIndex < column.size(); layerIndex++)
      {
        auto const& layerInfo = layerInfos[layerIndex];
        if (!layerInfo.isInPointCloud)
        {
          continue;
        }

        auto const& beam       = column[layerIndex];
        auto const beamAzimuth = getBeamAzimuth(module.metaData, beam, layerIndex, columnIndex, useAzimuthFromHeader, layerInfo);

        // Filter by azimuth
        if (!m_configuration.filters.azimuth.contains(beamAzimuth))
        {
          continue;
        }

        float sinAzimuth = 0.0f;
        float cosAzimuth = 0.0f;
        if (m_configuration.fields.enableCartesian)
        {
          sinAzimuth = std::sin(beamAzimuth.radians());
          cosAzimuth = std::cos(beamAzimuth.radians());
        }

        auto const beamTimestampOffset            = layerInfo.firstBeamTimestampOffset + layerInfo.timestampIncrementPerBeam * columnIndex;
        auto const beamTimestampOffsetNanoseconds = static_cast<std::uint32_t>(beamTimestampOffset.nanoseconds());
        auto const beamTimestampOffsetSeconds     = static_cast<std::uint32_t>(beamTimestampOffset.seconds());

        bool foundValidEcho = false;
        for (auto echoIt = beam.echoes.rbegin(); echoIt != beam.echoes.rend(); ++echoIt)
        {
          std::size_t const echoIndex = std::distance(beam.echoes.begin(), echoIt.base()) - 1;

          bool echoIsTheLastValidEcho                = false;
          sick::compact::scan_data::Echo const& echo = beam.echoes[echoIndex];
          if (!foundValidEcho && echo.distance.meters() > 0.0f)
          {
            foundValidEcho         = true;
            echoIsTheLastValidEcho = true;
          }

          if (skipEcho(beam, echo, echoIndex, echoIsTheLastValidEcho))
          {
            continue;
          }

          writeEcho(
            echo,
            cosAzimuth,
            sinAzimuth,
            module.metaData.rowMetaData[layerIndex].elevation,
            beamAzimuth,
            layerInfo,
            beamTimestampOffsetNanoseconds,
            beamTimestampOffsetSeconds,
            echoIndex,
            echoIsTheLastValidEcho && (beam.properties & 0x01) != 0,
            (beam.properties & bloomingMask(echoIndex)) != 0
          );
        }
      }
    }
  }
  assert(std::distance(pointCloudDataWritePositionBefore, m_pointCloudDataWritePosition) >= 0);
  m_pointCloud.numberOfPoints +=
    static_cast<std::size_t>(std::distance(pointCloudDataWritePositionBefore, m_pointCloudDataWritePosition)) / m_pointCloud.pointStep;
}

void PointCloudCollector::reset()
{
  m_pointCloud.header.timestamp = Timestamp::fromMicrosecondsSinceEpoch(0);
  m_pointCloud.numberOfPoints   = 0;
  m_pointCloud.fields           = m_fields; // keep the fields
  m_pointCloud.pointStep        = m_nextPointFieldOffset;
  m_pointCloudDataWritePosition = m_pointCloud.data.begin();
}

auto PointCloudCollector::getPointCloud() -> PointCloud
{
  m_pointCloud.data.resize(m_pointCloud.numberOfPoints * m_pointCloud.pointStep);
  return m_pointCloud;
}

} // namespace sick::compact
