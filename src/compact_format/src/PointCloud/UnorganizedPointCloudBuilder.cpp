/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

#include <sick_perception_sdk/compact_format/PointCloud/UnorganizedPointCloudBuilder.hpp>

#include "PointCloudBuilder.hpp"
#include <sick_perception_sdk/common/quantities/Timestamp.hpp>
#include <sick_perception_sdk/compact_format/PointCloud/MultiEchoPointCloud.hpp>
#include <sick_perception_sdk/compact_format/PointCloud/PointCloudConfiguration.hpp>

#include <cstddef>
#include <cstdint>
#include <limits>
#include <stdexcept>
#include <utility>
#include <vector>

namespace sick {

using PointField = MultiEchoPointCloud::PointField;

UnorganizedPointCloudBuilder::UnorganizedPointCloudBuilder(
  Timestamp pointCloudTimestamp,
  PointCloudConfiguration const& configuration,
  std::size_t maxNumberOfPoints
)
  : m_pointCloud()
  , m_maximumNumberOfPoints {maxNumberOfPoints}
  , m_writePositionIndex {0}
  , m_numberOfBytesWrittenInCurrentPoint {0}
{
  if (configuration.organization != MultiEchoPointCloud::Organization::Unorganized)
  {
    throw std::invalid_argument("Only unorganized point clouds are supported");
  }

  m_pointCloud.m_timestamp             = pointCloudTimestamp;
  m_pointCloud.m_width                 = 0; // Will be updated as points are added
  m_pointCloud.m_height                = 1; // Constant for unordered point clouds
  m_pointCloud.m_numberOfEchoesPerBeam = 1; // Constant for unordered point clouds
  m_pointCloud.m_density               = MultiEchoPointCloud::Density::AllPointsValid;
  m_pointCloud.m_organization          = MultiEchoPointCloud::Organization::Unorganized;

  initFields(configuration);

  m_pointCloud.m_data.resize(maxNumberOfPoints * m_pointCloud.pointSizeBytes());
}

void UnorganizedPointCloudBuilder::growBy(std::size_t numberOfPoints)
{
  // It is ok to compute the growth from the actual width of the point cloud so we don't waste too much memory.
  // It is the caller's intention to grow from the point cloud's current size, not from the maximum number of
  // points that was set at construction time or after.
  auto const newMaximumNumberOfPoints = m_pointCloud.m_width + numberOfPoints;
  if (newMaximumNumberOfPoints > (std::numeric_limits<std::size_t>::max() / m_pointCloud.pointSizeBytes()))
  {
    throw std::overflow_error("Cannot grow point cloud because it would exceed maximum size");
  }
  m_maximumNumberOfPoints = newMaximumNumberOfPoints;
  // m_maximumNumberOfPoints will always grow so there's no danger of destroying existing data when resizing the vector.
  m_pointCloud.m_data.resize(newMaximumNumberOfPoints * m_pointCloud.pointSizeBytes());
}

void UnorganizedPointCloudBuilder::beginPoint()
{
  if (m_pointCloud.m_width >= m_maximumNumberOfPoints)
  {
    throw std::runtime_error("Cannot begin point because it would exceed the maximum number of points");
  }

  m_numberOfBytesWrittenInCurrentPoint = 0;
  m_pointCloud.m_width++;
}

auto UnorganizedPointCloudBuilder::build() -> MultiEchoPointCloud
{
  // Shrink data vector to actual size
  m_pointCloud.m_data.resize(m_pointCloud.m_width * m_pointCloud.pointSizeBytes());
  return std::move(m_pointCloud);
}

void UnorganizedPointCloudBuilder::initFields(PointCloudConfiguration const& config)
{
  auto const addField = [this](PointField::FieldType fieldType, PointField::DataType dataType, std::uint32_t fieldOffsetBytes) -> void {
    m_pointCloud.m_fields.emplace_back(PointField {fieldType, fieldOffsetBytes, dataType});
  };

  auto const pointSizeBytes = addFields(config, addField);

  m_pointCloud.m_pointSizeBytes = pointSizeBytes;
}

} // namespace sick
