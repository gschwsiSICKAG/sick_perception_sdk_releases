/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

#include <sick_perception_sdk/compact_format/PointCloud/OrganizedPointCloudBuilder.hpp>

#include "PointCloudBuilder.hpp"
#include <sick_perception_sdk/common/quantities/Timestamp.hpp>
#include <sick_perception_sdk/compact_format/PointCloud/MultiEchoPointCloud.hpp>
#include <sick_perception_sdk/compact_format/PointCloud/PointCloudConfiguration.hpp>

#include <cstddef>
#include <cstdint>
#include <limits>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

namespace sick {

using PointField = MultiEchoPointCloud::PointField;

OrganizedPointCloudBuilder::OrganizedPointCloudBuilder(Timestamp pointCloudTimestamp, Layout const& layout)
  : m_pointCloud(
      pointCloudTimestamp,
      layout.width,
      layout.height,
      layout.numberOfEchoesPerBeam,
      MultiEchoPointCloud::Organization::Organized,
      MultiEchoPointCloud::Density::AllPointsValid, // Initially assume all points are valid; will be updated if writeInvalidPoint() is called
      layout.fields,
      layout.pointSizeBytes
    )
{
  auto const maxNumberOfPoints = layout.width * layout.height * layout.numberOfEchoesPerBeam;

  m_pointCloud.m_data.resize(maxNumberOfPoints * layout.pointSizeBytes);
  m_writePosition = m_pointCloud.m_data.begin();
}

void OrganizedPointCloudBuilder::beginPoint()
{
  if (m_numberOfAddedPoints >= m_pointCloud.numberOfPoints()) // FIXME Is this too slow?
  {
    throw std::out_of_range("Exceeded maximum number of points in point cloud");
  }

  m_numberOfBytesWrittenInCurrentPoint = 0;
  m_numberOfAddedPoints++;
}

void OrganizedPointCloudBuilder::writeInvalidPoint()
{
  beginPoint();

  // From now on the point cloud is marked as containing invalid points because there is a least one invalid point.
  m_pointCloud.m_density = MultiEchoPointCloud::Density::InvalidPointsContained;

  for (auto const& field : m_pointCloud.m_fields)
  {
    switch (field.dataType)
    {
    case PointField::DataType::Float32:
      write(std::numeric_limits<float>::quiet_NaN());
      break;
    case PointField::DataType::Float64:
      write(std::numeric_limits<double>::quiet_NaN());
      break;
    case PointField::DataType::Int8:
      write(static_cast<std::int8_t>(0));
      break;
    case PointField::DataType::Uint8:
    case PointField::DataType::Bool:
      write(static_cast<std::uint8_t>(0));
      break;
    case PointField::DataType::Int16:
      write(static_cast<std::int16_t>(0));
      break;
    case PointField::DataType::Uint16:
      write(static_cast<std::uint16_t>(0));
      break;
    case PointField::DataType::Int32:
      write(static_cast<std::int32_t>(0));
      break;
    case PointField::DataType::Uint32:
      write(static_cast<std::uint32_t>(0));
      break;
    case PointField::DataType::Int64:
      write(static_cast<std::int64_t>(0));
      break;
    case PointField::DataType::Uint64:
      write(static_cast<std::uint64_t>(0));
      break;
    }
  }
}

auto OrganizedPointCloudBuilder::build() -> MultiEchoPointCloud
{
  if (m_numberOfAddedPoints != m_pointCloud.numberOfPoints())
  {
    throw std::runtime_error(
      "Number of added points (" + std::to_string(m_numberOfAddedPoints) + ") does not match expected number of points based on layout (" +
      std::to_string(m_pointCloud.numberOfPoints()) + ")."
    );
  }

  return std::move(m_pointCloud);
}

auto OrganizedPointCloudBuilder::buildLayout(PointCloudConfiguration const& config, std::size_t width, std::size_t height, std::size_t echoesPerBeam) -> Layout
{
  if (config.organization != MultiEchoPointCloud::Organization::Organized)
  {
    throw std::invalid_argument("Only organized point clouds are supported by OrganizedPointCloudBuilder");
  }

  Layout layout;
  layout.width                 = width;
  layout.height                = height;
  layout.numberOfEchoesPerBeam = echoesPerBeam;

  auto const addField = [&layout](PointField::FieldType fieldType, PointField::DataType dataType, std::uint32_t fieldOffsetBytes) -> void {
    layout.fields.emplace_back(PointField {fieldType, fieldOffsetBytes, dataType});
  };

  auto const pointSizeBytes = addFields(config, addField);

  layout.pointSizeBytes = pointSizeBytes;
  return layout;
}

} // namespace sick
