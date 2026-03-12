/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

#pragma once

#include <sick_perception_sdk/common/export.hpp>
#include <sick_perception_sdk/common/quantities/Timestamp.hpp>
#include <sick_perception_sdk/compact_format/PointCloud/MultiEchoPointCloud.hpp>
#include <sick_perception_sdk/compact_format/PointCloud/PointCloudConfiguration.hpp>

#include <cassert>
#include <cstdint>
#include <cstring>
#include <limits>
#include <stdexcept>
#include <vector>

namespace sick {

/**
 * @brief A builder class for constructing point clouds with RAII design.
 *
 * All configuration happens at construction time. The builder pre-allocates memory
 * for the maximum number of points (width × height) and provides methods to write
 * point data sequentially.
 * 
 * @warning The builder's API relies on the data order of the underlying MultiEchoPointCloud. 
 * It is the caller's responsibility to write fields in the correct order.
 *
 * Usage:
 * @code
 * OrganizedPointCloudBuilder builder(layout);
 * for (each point) {
 *   if (point is valid) {
 *     builder.beginPoint();
 *     builder.write(x);
 *     builder.write(y);
 *     builder.write(z);
 *     // ... write remaining fields in order
 *   } else {
 *     builder.writeInvalidPoint();
 *   }
 * }
 * auto cloud = builder.build();
 * @endcode
 */
class SDK_EXPORT OrganizedPointCloudBuilder
{
public:
  /**
 * @brief Describe the structure and metadata of a point cloud to be built.
 */
  struct SDK_EXPORT Layout
  {
    std::size_t width                 = 0; ///< numberOfColumns (organized) or maxPoints (unorganized)
    std::size_t height                = 0; ///< number of rows (organized) or 1 (unorganized)
    std::size_t numberOfEchoesPerBeam = 0; ///< number of echoes per beam (organized) or 1 (unorganized)
    std::vector<MultiEchoPointCloud::PointField> fields;
    std::uint32_t pointSizeBytes = 0; ///< Total size of one point in bytes
  };

  explicit OrganizedPointCloudBuilder(Timestamp pointCloudTimestamp, Layout const& layout);

  /**
   * @brief Begin writing a new valid point. Must be called before write() calls.
   */
  void beginPoint();

  /**
   * @brief Write a value to the current point. Values must be written in field order and order the point cloud expects it.
   *
   * In debug builds, asserts that writes don't exceed the point size.
   */
  template <typename T>
  void write(T value)
  {
    assert(m_writePosition + sizeof(T) <= m_pointCloud.m_data.cend() && "Write exceeds allocated buffer");

    m_numberOfBytesWrittenInCurrentPoint += sizeof(T);
    assert(m_numberOfBytesWrittenInCurrentPoint <= m_pointCloud.pointSizeBytes() && "Write exceeds point size");

    std::memcpy(&*m_writePosition, &value, sizeof(T));
    m_writePosition += sizeof(T);
  }

  /**
   * @brief Write an invalid point with NaN for floats and 0 for integers.
   *
   * Use this for organized point clouds when a point is filtered out but
   * the grid structure must be preserved.
   */
  void writeInvalidPoint();

  /**
   * @brief Finalize and returns the built point cloud. Moves ownership to caller.
   *
   * After calling build(), the builder is in an unspecified state and should not be used.
   */
  auto build() -> MultiEchoPointCloud;

  /**
   * @brief Create a Layout from a configuration and dimensional parameters.
   *
   * This helper builds the field list based on the configuration flags (enableCartesian,
   * enableIntensity, etc.) and calculates the point size.
   *
   * @param config The point cloud configuration specifying which fields to include
   * @param width The width of the point cloud
   * @param height The height of the point cloud
   * @param echoesPerBeam Number of echoes per beam
   * @return A fully configured Layout ready for OrganizedPointCloudBuilder construction
   */
  static auto buildLayout(PointCloudConfiguration const& config, std::size_t width, std::size_t height, std::size_t echoesPerBeam) -> Layout;

private:
  MultiEchoPointCloud m_pointCloud;
  std::size_t m_numberOfAddedPoints = 0;
  std::vector<std::uint8_t>::iterator m_writePosition;
  std::size_t m_numberOfBytesWrittenInCurrentPoint = 0;
};

} // namespace sick
