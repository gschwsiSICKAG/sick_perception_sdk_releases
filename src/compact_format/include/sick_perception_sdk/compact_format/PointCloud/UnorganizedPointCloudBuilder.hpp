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
 * UnorganizedPointCloudBuilder builder(timestamp, configuration);
 * for (each point) {
 *   if (point is valid) {
 *     builder.beginPoint();
 *     builder.write(x);
 *     builder.write(y);
 *     builder.write(z);
 *     // ... write remaining fields in order
 *   }
 * }
 * auto cloud = builder.build();
 * @endcode
 */
class SDK_EXPORT UnorganizedPointCloudBuilder
{
public:
  /**
   * @brief Construct a builder for an unorganized point cloud with the given configuration and maximum number of points.
   * 
   * The maximum number of points is necessary to pre-allocate memory for the point cloud. The point cloud's memory will be shrunk
   * to the actual number of points when build() is called.
   */
  explicit UnorganizedPointCloudBuilder(Timestamp pointCloudTimestamp, PointCloudConfiguration const& configuration, std::size_t maxNumberOfPoints);

  /**
   * @brief Grow the point cloud by the given number of points.
   * 
   * This function can be called to increase the maximum number of points. It will potentially reallocate memory.
   */
  void growBy(std::size_t numberOfPoints);

  /**
   * @brief Begins writing a new valid point. Must be called before write() calls.
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
    assert(m_writePositionIndex + sizeof(T) <= m_pointCloud.m_data.size() && "Write exceeds allocated buffer");

    m_numberOfBytesWrittenInCurrentPoint += sizeof(T);
    assert(m_numberOfBytesWrittenInCurrentPoint <= m_pointCloud.pointSizeBytes() && "Write exceeds point size");

    std::memcpy(&m_pointCloud.m_data[m_writePositionIndex], &value, sizeof(T));
    m_writePositionIndex += sizeof(T);
  }

  /**
   * @brief Finalize and returns the built point cloud. Moves ownership to caller.
   *
   * @warning After calling build(), the builder is in an unspecified state. 
   *          The caller must not call any other methods on the builder after calling build().
   */
  auto build() -> MultiEchoPointCloud;

  void setPointCloudTimestamp(Timestamp timestamp)
  {
    m_pointCloud.m_timestamp = timestamp;
  }

private:
  MultiEchoPointCloud m_pointCloud;
  std::size_t m_maximumNumberOfPoints;
  std::size_t m_writePositionIndex;
  std::size_t m_numberOfBytesWrittenInCurrentPoint;

  void initFields(PointCloudConfiguration const& config);
};

} // namespace sick
