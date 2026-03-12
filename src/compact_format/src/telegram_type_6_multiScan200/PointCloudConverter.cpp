/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

#include <sick_perception_sdk/compact_format/telegram_type_6_multiScan200/PointCloudConverter.hpp>

#include <sick_perception_sdk/common/quantities/Angle.hpp>
#include <sick_perception_sdk/common/quantities/Timestamp.hpp>
#include <sick_perception_sdk/compact_format/PointCloud/MultiEchoPointCloud.hpp>
#include <sick_perception_sdk/compact_format/PointCloud/OrganizedPointCloudBuilder.hpp>
#include <sick_perception_sdk/compact_format/PointCloud/PointCloudConfiguration.hpp>
#include <sick_perception_sdk/compact_format/PointCloud/UnorganizedPointCloudBuilder.hpp>
#include <sick_perception_sdk/compact_format/telegram_type_6_multiScan200/MultiScan200Data.hpp>

#include <algorithm>
#include <cstddef>
#include <cstdint>
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

auto computeFilterIndices(PointCloudConfiguration const& configuration, MultiScan200Data const& data) -> FilterIndices
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

template <typename BuilderT>
auto createBuilder(PointCloudConfiguration const& configuration, Timestamp timestamp, MultiScan200Data const& data) -> BuilderT;

template <>
auto createBuilder<OrganizedPointCloudBuilder>(PointCloudConfiguration const& configuration, Timestamp timestamp, MultiScan200Data const& data)
  -> OrganizedPointCloudBuilder
{
  auto const numberOfEchoes = static_cast<std::size_t>(data.segmentMetaData.numberOfEchoes);
  auto const width          = static_cast<std::size_t>(data.segmentMetaData.numberOfColumnsInSegment);
  auto const height         = static_cast<std::size_t>(data.segmentMetaData.numberOfRows);
  auto const layout         = OrganizedPointCloudBuilder::buildLayout(configuration, width, height, numberOfEchoes);
  return OrganizedPointCloudBuilder(timestamp, layout);
}

template <>
auto createBuilder<UnorganizedPointCloudBuilder>(PointCloudConfiguration const& configuration, Timestamp timestamp, MultiScan200Data const& data)
  -> UnorganizedPointCloudBuilder
{
  auto const numberOfEchoes    = static_cast<std::size_t>(data.segmentMetaData.numberOfEchoes);
  auto const width             = static_cast<std::size_t>(data.segmentMetaData.numberOfColumnsInSegment);
  auto const height            = static_cast<std::size_t>(data.segmentMetaData.numberOfRows);
  auto const maxNumberOfPoints = width * height * numberOfEchoes;
  return UnorganizedPointCloudBuilder(timestamp, configuration, maxNumberOfPoints);
}

template <typename BuilderT>
auto convertSpecific(PointCloudConfiguration const& configuration, MultiScan200Data const& data) -> MultiEchoPointCloud
{
  // Make sure the geometries in the input data are valid.
  if (data.geometry.azimuths.size() < static_cast<std::size_t>(data.segmentMetaData.numberOfColumnsInSegment) //
      || data.geometry.elevations.size() < static_cast<std::size_t>(data.segmentMetaData.numberOfRows)        //
      || data.geometry.relativeTimeStamps.size() < static_cast<std::size_t>(data.segmentMetaData.numberOfColumnsInSegment))
  {
    throw std::runtime_error("Input data geometry size is smaller than expected based on segment metadata");
  }

  auto const filterIndices  = computeFilterIndices(configuration, data);
  auto const numberOfEchoes = static_cast<std::size_t>(data.segmentMetaData.numberOfEchoes);

  // Handle empty point cloud case early (before accessing geometry)
  auto const isEmpty = data.segmentMetaData.numberOfColumnsInSegment == 0 //
                       || data.segmentMetaData.numberOfRows == 0          //
                       || data.segmentMetaData.numberOfEchoes == 0;
  if (isEmpty)
  {
    auto builder = createBuilder<BuilderT>(configuration, Timestamp::fromMicrosecondsSinceEpoch(0), data);
    return builder.build();
  }

  // Calculate timestamp (safe now that we know we have data)
  auto const firstDelta = data.geometry.relativeTimeStamps[0];
  auto const timestamp  = data.segmentMetaData.frameTimestamp + firstDelta;

  auto builder = createBuilder<BuilderT>(configuration, timestamp, data);

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
      auto const& scanColumn      = data.scanData[columnIndex];

      for (auto echoIndex : filterIndices.echoIndicesToCopy)
      {
        auto const& beam = scanColumn[rowIndex];

        // Handle beams with fewer echoes than expected (e.g., corrupted data)
        if (echoIndex >= beam.echoes.size())
        {
          if constexpr (std::is_same_v<BuilderT, OrganizedPointCloudBuilder>)
          {
            builder.writeInvalidPoint();
          }
          continue;
        }

        auto const& echo = beam.echoes[echoIndex];

        bool const isFiltered = !configuration.filters.range.contains(echo.distance) ||
                                (echo.intensity.has_value() && !configuration.filters.intensity.contains(echo.intensity.value()));

        // FIXME Apply filtering for blooming and reflector flags once we have the mapping.

        if (isFiltered)
        {
          if constexpr (std::is_same_v<BuilderT, OrganizedPointCloudBuilder>)
          {
            builder.writeInvalidPoint();
          }
          continue;
        }

        builder.beginPoint();

        float const distanceScaled = echo.distance.meters() * configuration.distanceScalingFactor;

        if (configuration.fields.enableCartesian)
        {
          float const x = cosElevation * cosAzimuth * distanceScaled; // NOLINT(readability-identifier-length)
          float const y = cosElevation * sinAzimuth * distanceScaled; // NOLINT(readability-identifier-length)
          float const z = -sinElevation * distanceScaled;             // NOLINT(readability-identifier-length)

          builder.write(x);
          builder.write(y);
          builder.write(z);
        }

        if (configuration.fields.enableSpherical)
        {
          builder.write(distanceScaled);
          builder.write(azimuth.radians());
          builder.write(elevation.radians());
        }

        if (configuration.fields.enableIntensity)
        {
          builder.write(echo.intensity.has_value() ? echo.intensity.value() : std::numeric_limits<float>::quiet_NaN());
        }

        if (configuration.fields.enableTimeOffset)
        {
          auto const [seconds, nanoseconds] = columnTimeOffset.secondsAndNanoseconds();
          builder.write(nanoseconds);
          builder.write(seconds);
        }

        if (configuration.fields.enableRing)
        {
          builder.write(static_cast<std::uint8_t>(rowIndex));
        }

        if (configuration.fields.enableLayer)
        {
          builder.write(static_cast<std::uint8_t>(rowIndex));
        }

        if (configuration.fields.enableEcho)
        {
          auto const echoId = static_cast<std::uint8_t>(echoIndex);
          builder.write(echoId);
        }

        if (configuration.fields.enableIsReflector)
        {
          std::uint8_t const isReflector = 0; // FIXME We don't have the properties mapping yet;
          builder.write(isReflector);
        }

        if (configuration.fields.enableHasBlooming)
        {
          std::uint8_t const hasBlooming = 0; // FIXME We don't have the properties mapping yet;
          builder.write(hasBlooming);
        }

        if (configuration.fields.enablePulseWidth)
        {
          float const pulseWidth = echo.pulseWidth.has_value() ? static_cast<float>(echo.pulseWidth->nanoseconds()) : std::numeric_limits<float>::quiet_NaN();
          builder.write(pulseWidth);
        }
      }
    }
  }

  return builder.build();
}

} // namespace

PointCloudConverter::PointCloudConverter(PointCloudConfiguration configuration)
  : m_configuration(std::move(configuration))
{ }

auto PointCloudConverter::convert(MultiScan200Data const& data) const -> MultiEchoPointCloud
{
  if (m_configuration.organization == MultiEchoPointCloud::Organization::Organized)
  {
    return convertSpecific<OrganizedPointCloudBuilder>(m_configuration, data);
  }
  return convertSpecific<UnorganizedPointCloudBuilder>(m_configuration, data);
}

} // namespace sick::compact::multiscan200
