/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

#include <sick_perception_sdk/compact_format/telegram_type_6_multiScan200/PointCloudConverter.hpp>

#include <sick_perception_sdk/common/quantities/Angle.hpp>
#include <sick_perception_sdk/common/quantities/Timestamp.hpp>
#include <sick_perception_sdk/compact_format/PointCloud/OrganizedPointCloud.hpp>
#include <sick_perception_sdk/compact_format/PointCloud/OrganizedPointCloudBuilder.hpp>
#include <sick_perception_sdk/compact_format/PointCloud/PointCloudConfiguration.hpp>
#include <sick_perception_sdk/compact_format/PointCloud/UnorganizedPointCloudBuilder.hpp>
#include <sick_perception_sdk/compact_format/telegram_type_6_multiScan200/MultiScan200Data.hpp>

#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <functional>
#include <iterator>
#include <limits>
#include <numeric>
#include <stdexcept>
#include <type_traits>
#include <utility>
#include <vector>

namespace sick::compact::multiscan200 {

namespace {

struct FilterIndices
{
  std::vector<std::size_t> echoIndicesToCopy;
  std::vector<std::size_t> rowIndicesToCopy;
  std::vector<std::size_t> columnIndexesToCopy;
};

struct AccessFunctions
{
  std::function<float(MultiScan200Data const&, std::size_t)> getIntensityOrNan = [](MultiScan200Data const&, std::size_t) -> float {
    return std::numeric_limits<float>::quiet_NaN();
  };
  std::function<float(MultiScan200Data const&, std::size_t)> getPulseWidthOrNan = [](MultiScan200Data const&, std::size_t) -> float {
    return std::numeric_limits<float>::quiet_NaN();
  };
  std::function<BitField<EchoProperties>(MultiScan200Data const&, std::size_t)> getEchoPropertiesOrReserved =
    [](MultiScan200Data const&, std::size_t) -> BitField<EchoProperties> {
    return BitField<EchoProperties> {EchoProperties::Reserved};
  };
  std::function<bool(MultiScan200Data const&, std::size_t)> isFilteredOutDueToReflector = [](MultiScan200Data const&, std::size_t) -> bool {
    return false;
  };
  std::function<bool(MultiScan200Data const&, std::size_t)> isFilteredOutDueToBlooming = [](MultiScan200Data const&, std::size_t) -> bool {
    return false;
  };
};

auto getAccessFunctions(point_cloud::PointCloudConfiguration const& configuration, MultiScan200Data const& data) -> AccessFunctions
{
  AccessFunctions accessFunctions;

  // Intensity access
  if (!data.intensities.empty())
  {
    accessFunctions.getIntensityOrNan = [](MultiScan200Data const& data, std::size_t index) -> float {
      return data.intensities[index];
    };
  }

  // Pulse width access
  if (!data.pulseWidths.empty())
  {
    accessFunctions.getPulseWidthOrNan = [](MultiScan200Data const& data, std::size_t index) -> float {
      return data.pulseWidths[index].nanoseconds();
    };
  }

  // Properties access
  if (!data.echoProperties.empty())
  {
    accessFunctions.getEchoPropertiesOrReserved = [](MultiScan200Data const& data, std::size_t index) -> BitField<EchoProperties> {
      return data.echoProperties[index];
    };
  }

  // Reflector flag filter
  if (configuration.filters.requiredReflectorFlag.has_value() && !data.echoProperties.empty())
  {
    accessFunctions.isFilteredOutDueToReflector = [configuration](MultiScan200Data const& data, std::size_t index) -> bool {
      auto const isFlagSet = data.echoProperties[index].isSet(EchoProperties::IsReflector);
      return configuration.filters.requiredReflectorFlag.value() != isFlagSet;
    };
  }

  // Blooming flag filter
  if (configuration.filters.requiredBloomingFlag.has_value() && !data.echoProperties.empty())
  {
    accessFunctions.isFilteredOutDueToBlooming = [configuration](MultiScan200Data const& data, std::size_t index) -> bool {
      auto const isFlagSet = data.echoProperties[index].isSet(EchoProperties::IsBlooming);
      return configuration.filters.requiredBloomingFlag.value() != isFlagSet;
    };
  }

  return accessFunctions;
}

auto computeFilterIndices(point_cloud::PointCloudConfiguration const& configuration, MultiScan200Data const& data) -> FilterIndices
{
  FilterIndices indices;
  auto const numberOfEchoes = static_cast<std::size_t>(data.segmentMetaData.numberOfEchoes);
  auto const numberOfRows   = static_cast<std::size_t>(data.segmentMetaData.numberOfRows);

  // Echo index filter
  if (configuration.filters.selectedEchos.has_value())
  {
    // Only include echo indices that are within valid range
    for (auto echoIndex : *configuration.filters.selectedEchos)
    {
      if (echoIndex < numberOfEchoes)
      {
        indices.echoIndicesToCopy.push_back(echoIndex);
      }
    }
  }
  else
  {
    indices.echoIndicesToCopy.resize(numberOfEchoes);
    std::iota(indices.echoIndicesToCopy.begin(), indices.echoIndicesToCopy.end(), 0u);
  }

  // Elevation filter
  if (configuration.filters.selectedLayers.has_value())
  {
    // Only include row indices that are within valid range
    for (auto layerIndex : *configuration.filters.selectedLayers)
    {
      if (layerIndex >= numberOfRows)
      {
        continue;
      }
      auto const elevation = data.geometry.elevations[layerIndex];
      if (!configuration.filters.elevation.contains(elevation))
      {
        continue;
      }
      indices.rowIndicesToCopy.push_back(layerIndex);
    }
  }
  else
  {
    for (std::size_t rowIndex = 0; rowIndex < numberOfRows; ++rowIndex)
    {
      auto const elevation = data.geometry.elevations[rowIndex];
      if (!configuration.filters.elevation.contains(elevation))
      {
        continue;
      }
      indices.rowIndicesToCopy.push_back(rowIndex);
    }
  }

  // Azimuth filter
  if (configuration.filters.azimuth.isEmpty())
  {
    // If there are no angle filters, we can include all columns without checking the geometry
    indices.columnIndexesToCopy.resize(data.segmentMetaData.numberOfColumnsInSegment);
    std::iota(indices.columnIndexesToCopy.begin(), indices.columnIndexesToCopy.end(), 0u);
  }
  else
  {
    for (std::size_t columnIndex = 0; columnIndex < static_cast<std::size_t>(data.segmentMetaData.numberOfColumnsInSegment); ++columnIndex)
    {
      auto const azimuth = data.geometry.azimuths[columnIndex];
      if (configuration.filters.azimuth.contains(azimuth))
      {
        indices.columnIndexesToCopy.push_back(columnIndex);
      }
    }
  }

  return indices;
}

auto getAvailableFields(MultiScan200Data const& data) -> std::set<point_cloud::PointField::FieldType>
{
  using FieldType = point_cloud::PointField::FieldType;

  std::set<FieldType> availableFields = {
    FieldType::X,
    FieldType::Y,
    FieldType::Z,
    FieldType::Range,
    FieldType::Azimuth,
    FieldType::Elevation,
    // Intensity is optional
    FieldType::TimeOffsetNanoseconds,
    FieldType::TimeOffsetSeconds,
    FieldType::Ring,
    FieldType::LayerId,
    FieldType::EchoIndex,
    // IsReflector and HasBlooming are optional and only available if echo properties are present
  };

  if (!data.intensities.empty())
  {
    availableFields.insert(FieldType::Intensity);
  }
  if (!data.pulseWidths.empty())
  {
    availableFields.insert(FieldType::PulseWidth);
  }
  if (!data.echoProperties.empty())
  {
    // If echo properties are available, we can provide IsReflector and HasBlooming fields based on the EchoProperties bits
    availableFields.insert(FieldType::IsReflector);
    availableFields.insert(FieldType::HasBlooming);
  }

  return availableFields;
}

template <typename BuilderT>
auto createBuilder(typename BuilderT::FieldConfig const& fieldConfig, Timestamp timestamp, MultiScan200Data const& data) -> BuilderT;

template <>
auto createBuilder<point_cloud::OrganizedPointCloudBuilder>(
  point_cloud::OrganizedPointCloudBuilder::FieldConfig const& fieldConfig,
  Timestamp timestamp,
  MultiScan200Data const& data
) -> point_cloud::OrganizedPointCloudBuilder
{
  auto const numberOfEchoes = static_cast<std::size_t>(data.segmentMetaData.numberOfEchoes);
  auto const width          = static_cast<std::size_t>(data.segmentMetaData.numberOfColumnsInSegment);
  auto const height         = static_cast<std::size_t>(data.segmentMetaData.numberOfRows);
  return point_cloud::OrganizedPointCloudBuilder(fieldConfig, timestamp, width, height, numberOfEchoes);
}

template <>
auto createBuilder<point_cloud::UnorganizedPointCloudBuilder>(
  point_cloud::UnorganizedPointCloudBuilder::FieldConfig const& fieldConfig,
  Timestamp timestamp,
  MultiScan200Data const& data
) -> point_cloud::UnorganizedPointCloudBuilder
{
  auto const numberOfEchoes    = static_cast<std::size_t>(data.segmentMetaData.numberOfEchoes);
  auto const width             = static_cast<std::size_t>(data.segmentMetaData.numberOfColumnsInSegment);
  auto const height            = static_cast<std::size_t>(data.segmentMetaData.numberOfRows);
  auto const maxNumberOfPoints = width * height * numberOfEchoes;
  return point_cloud::UnorganizedPointCloudBuilder(fieldConfig, timestamp, maxNumberOfPoints);
}

template <typename BuilderT, typename PointCloudT>
auto convertSpecific(
  point_cloud::PointCloudConfiguration const& configuration,
  std::set<point_cloud::PointField::FieldType> const& desiredFields,
  MultiScan200Data const& data
) -> PointCloudT
{
  using FieldType = point_cloud::PointField::FieldType;

  // Make sure the geometries in the input data are valid.
  if (data.geometry.azimuths.size() < static_cast<std::size_t>(data.segmentMetaData.numberOfColumnsInSegment) //
      || data.geometry.elevations.size() < static_cast<std::size_t>(data.segmentMetaData.numberOfRows)        //
      || data.geometry.relativeTimeStamps.size() < static_cast<std::size_t>(data.segmentMetaData.numberOfColumnsInSegment))
  {
    throw std::runtime_error("Input data geometry size is smaller than expected based on segment metadata");
  }

  typename BuilderT::FieldConfig fieldConfig {desiredFields, getAvailableFields(data)};

  // Handle empty point cloud case early (before accessing geometry)
  auto const pointCloudIsEmpty =
    data.segmentMetaData.numberOfColumnsInSegment == 0 //
    || data.segmentMetaData.numberOfRows == 0          //
    || data.segmentMetaData.numberOfEchoes == 0;
  if (pointCloudIsEmpty)
  {
    auto builder = createBuilder<BuilderT>(fieldConfig, Timestamp::fromMicrosecondsSinceEpoch(0), data);
    return builder.build();
  }

  // Make sure all data vectors are large enough
  auto const numberOfEchoes         = static_cast<std::size_t>(data.segmentMetaData.numberOfEchoes);
  auto const numberOfRows           = static_cast<std::size_t>(data.segmentMetaData.numberOfRows);
  auto const numberOfColumns        = static_cast<std::size_t>(data.segmentMetaData.numberOfColumnsInSegment);
  auto const expectedNumberOfPoints = numberOfEchoes * numberOfRows * numberOfColumns;
  if (data.distances.size() < expectedNumberOfPoints)
  {
    throw std::runtime_error("Too few distance values in input data");
  }

  if (data.echoProperties.size() > 0 && data.echoProperties.size() < expectedNumberOfPoints)
  {
    throw std::runtime_error("Too few echo property values in input data");
  }

  if (data.intensities.size() > 0 && data.intensities.size() < expectedNumberOfPoints)
  {
    throw std::runtime_error("Too few intensity values in input data");
  }

  if (data.pulseWidths.size() > 0 && data.pulseWidths.size() < expectedNumberOfPoints)
  {
    throw std::runtime_error("Too few pulse width values in input data");
  }

  auto const accessFunctions = getAccessFunctions(configuration, data);

  // Compute the filter indices. They will be used to select the points according to their echo, row, and column index.
  auto const filterIndices = computeFilterIndices(configuration, data);

  // Calculate timestamp (safe now that we know we have data)
  auto const firstDelta = data.geometry.relativeTimeStamps[0];
  auto const timestamp  = data.segmentMetaData.frameTimestamp + firstDelta;

  auto builder = createBuilder<BuilderT>(fieldConfig, timestamp, data);

  // Compute the time offsets for each column relative to the start of the segment.
  std::vector<Duration> segmentColumnTimeOffsets;
  segmentColumnTimeOffsets.reserve(data.geometry.relativeTimeStamps.size());
  std::transform(
    data.geometry.relativeTimeStamps.begin(),
    data.geometry.relativeTimeStamps.end(),
    std::back_inserter(segmentColumnTimeOffsets),
    [firstDelta](Duration const& offset) -> Duration {
      return offset - firstDelta;
    }
  );

  // Convert points in row-major order
  for (auto rowIndex : filterIndices.rowIndicesToCopy)
  {
    auto const elevation    = data.geometry.elevations[rowIndex];
    auto const sinElevation = sin(elevation);
    auto const cosElevation = cos(elevation);

    for (auto columnIndex : filterIndices.columnIndexesToCopy)
    {
      auto const azimuth          = data.geometry.azimuths[columnIndex];
      auto const sinAzimuth       = sin(azimuth);
      auto const cosAzimuth       = cos(azimuth);
      auto const columnTimeOffset = segmentColumnTimeOffsets[columnIndex];

      for (auto echoIndex : filterIndices.echoIndicesToCopy)
      {
        auto const dataIndex = data.computeIndex(echoIndex, columnIndex, rowIndex);
        auto const distance  = data.distances[dataIndex];
        auto const intensity = accessFunctions.getIntensityOrNan(data, dataIndex);

        // If the interval is empty all values including nan will be considered inside the interval.
        // If the interval is not empty, nan values will be considered outside the interval, i.e. all values where no measurement exists
        // will be filtered out if there is an active filter setting.
        bool const isFilteredOut =
          !configuration.filters.range.contains(distance)                 //
          || !configuration.filters.intensity.contains(intensity)         //
          || accessFunctions.isFilteredOutDueToReflector(data, dataIndex) //
          || accessFunctions.isFilteredOutDueToBlooming(data, dataIndex);

        if (isFilteredOut)
        {
          if constexpr (std::is_same_v<BuilderT, point_cloud::OrganizedPointCloudBuilder>)
          {
            builder.writeInvalidPoint();
          }
          continue;
        }

        builder.beginPoint();

        float const distanceScaled = distance.meters() * configuration.distanceScalingFactor;

        if (configuration.fields.enableCartesian)
        {
          float const xDistance = cosElevation * cosAzimuth * distanceScaled;
          float const yDistance = cosElevation * sinAzimuth * distanceScaled;
          float const zDistance = -sinElevation * distanceScaled;

          builder.writeNextFieldValueOrIgnore(FieldType::X, xDistance);
          builder.writeNextFieldValueOrIgnore(FieldType::Y, yDistance);
          builder.writeNextFieldValueOrIgnore(FieldType::Z, zDistance);
        }

        if (configuration.fields.enableSpherical)
        {
          builder.writeNextFieldValueOrIgnore(FieldType::Range, distanceScaled);
          builder.writeNextFieldValueOrIgnore(FieldType::Azimuth, azimuth.radians());
          builder.writeNextFieldValueOrIgnore(FieldType::Elevation, elevation.radians());
        }

        if (configuration.fields.enableIntensity)
        {
          builder.writeNextFieldValueOrIgnore(FieldType::Intensity, intensity);
        }

        if (configuration.fields.enableTimeOffset)
        {
          auto const [seconds, nanoseconds] = columnTimeOffset.secondsAndNanoseconds();
          builder.writeNextFieldValueOrIgnore(FieldType::TimeOffsetNanoseconds, nanoseconds);
          builder.writeNextFieldValueOrIgnore(FieldType::TimeOffsetSeconds, seconds);
        }

        if (configuration.fields.enableRing)
        {
          builder.writeNextFieldValueOrIgnore(FieldType::Ring, static_cast<std::uint8_t>(rowIndex));
        }

        if (configuration.fields.enableLayer)
        {
          builder.writeNextFieldValueOrIgnore(FieldType::LayerId, static_cast<std::uint8_t>(rowIndex));
        }

        if (configuration.fields.enableEcho)
        {
          auto const echoId = static_cast<std::uint8_t>(echoIndex);
          builder.writeNextFieldValueOrIgnore(FieldType::EchoIndex, echoId);
        }

        if (configuration.fields.enableIsReflector)
        {
          auto const echoProperties      = accessFunctions.getEchoPropertiesOrReserved(data, dataIndex);
          std::uint8_t const isReflector = echoProperties.isSet(EchoProperties::IsReflector) ? 1 : 0;
          builder.writeNextFieldValueOrIgnore(FieldType::IsReflector, isReflector);
        }

        if (configuration.fields.enableHasBlooming)
        {
          auto const echoProperties      = accessFunctions.getEchoPropertiesOrReserved(data, dataIndex);
          std::uint8_t const hasBlooming = echoProperties.isSet(EchoProperties::IsBlooming) ? 1 : 0;
          builder.writeNextFieldValueOrIgnore(FieldType::HasBlooming, hasBlooming);
        }

        if (configuration.fields.enablePulseWidth)
        {
          auto const pulseWidth = accessFunctions.getPulseWidthOrNan(data, dataIndex);
          builder.writeNextFieldValueOrIgnore(FieldType::PulseWidth, pulseWidth);
        }
      }
    }
  }

  return builder.build();
}

} // namespace

PointCloudConverter::PointCloudConverter(point_cloud::PointCloudConfiguration configuration)
  : m_configuration(std::move(configuration))
  , m_desiredFields(m_configuration.fields.toSet())
{ }

auto PointCloudConverter::convertToOrganized(MultiScan200Data const& data) const -> point_cloud::OrganizedPointCloud
{
  return convertSpecific<point_cloud::OrganizedPointCloudBuilder, point_cloud::OrganizedPointCloud>(m_configuration, m_desiredFields, data);
}

auto PointCloudConverter::convertToUnorganized(MultiScan200Data const& data) const -> point_cloud::UnorganizedPointCloud
{
  return convertSpecific<point_cloud::UnorganizedPointCloudBuilder, point_cloud::UnorganizedPointCloud>(m_configuration, m_desiredFields, data);
}

} // namespace sick::compact::multiscan200
