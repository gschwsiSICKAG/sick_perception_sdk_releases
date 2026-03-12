/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

#include <sick_perception_sdk/compact_format/PointCloud/MultiEchoPointCloud.hpp>

#include <sick_perception_sdk/common/quantities/Timestamp.hpp>

#include <cstddef>
#include <cstdint>
#include <stdexcept>
#include <utility>
#include <vector>

namespace sick {

MultiEchoPointCloud::MultiEchoPointCloud(
  Timestamp timestamp,
  std::size_t width,
  std::size_t height,
  std::size_t numberOfEchoesPerBeam,
  Organization organization,
  Density density,
  std::vector<PointField> fields,
  std::uint32_t pointSizeBytes
)
  : m_timestamp(timestamp)
  , m_width(width)
  , m_height(height)
  , m_numberOfEchoesPerBeam(numberOfEchoesPerBeam)
  , m_organization(organization)
  , m_density(density)
  , m_fields(std::move(fields))
  , m_pointSizeBytes(pointSizeBytes)
{
  if (m_organization == Organization::Unorganized)
  {
    if (m_height != 1)
    {
      throw std::invalid_argument("Unorganized point clouds must have height == 1");
    }
    if (m_numberOfEchoesPerBeam != 1)
    {
      throw std::invalid_argument("Unorganized point clouds must have numberOfEchoesPerBeam == 1");
    }
  }
}

auto MultiEchoPointCloud::pointIndex(std::size_t column, std::size_t row, std::size_t echoIndex) const -> std::size_t
{
  if (m_organization == Organization::Unorganized)
  {
    throw std::logic_error("Cannot use grid access on unorganized point cloud");
  }
  auto const numberOfColumns = m_width / m_numberOfEchoesPerBeam;
  if (column >= numberOfColumns || row >= m_height || echoIndex >= m_numberOfEchoesPerBeam)
  {
    throw std::out_of_range("Grid coordinates out of range");
  }
  // Row-major: row * width + (column * numberOfEchoesPerBeam + echoIndex)
  return row * m_width + column * m_numberOfEchoesPerBeam + echoIndex;
}

} // namespace sick
