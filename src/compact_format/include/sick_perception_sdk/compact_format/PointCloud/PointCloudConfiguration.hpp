/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

#pragma once

// NOLINTBEGIN(misc-non-private-member-variables-in-classes)

#include <sick_perception_sdk/common/export.hpp>
#include <sick_perception_sdk/common/quantities/Angle.hpp>
#include <sick_perception_sdk/common/quantities/Distance.hpp>
#include <sick_perception_sdk/compact_format/PointCloud/MultiEchoPointCloud.hpp>

#include <cstdint>
#include <optional>
#include <set>
#include <string>

namespace sick {

/**
 * @brief A class that represents an interval. A value can be checked if it is in the interval with isInRange().
 */
template <typename T>
struct Interval
{
  Interval()
    : min(std::nullopt)
    , max(std::nullopt)
  { }

  std::optional<T> min;
  std::optional<T> max;
  bool invert {false};

  /**
   * @brief Checks if a value is in the range [min, max]. If min or max is not set, that side is unbounded.
   * If invert is true, the result is inverted.
   */
  auto contains(T value) const -> bool
  {
    bool const inRange = (min.has_value() ? value >= min.value() : true) && (max.has_value() ? value <= max.value() : true);
    return invert ? !inRange : inRange;
  }

  /**
   * @brief Checks if the range is empty, i.e. there is a value that can be in the range.
   * 
   * If the range is not configured (both min and max are not set), it is considered empty.
   */
  auto isEmpty() const -> bool
  {
    if (min.has_value() && max.has_value())
    {
      return min.value() > max.value();
    }
    return true;
  }

  auto toString() const -> std::string
  {
    std::string result = (invert ? "not " : "") + std::string("[");
    result += (min.has_value() ? std::to_string(*min) : "-inf") + ", ";
    result += (max.has_value() ? std::to_string(*max) : "inf") + "]";
    return result;
  }
};

struct SDK_EXPORT PointCloudConfiguration
{
  struct Fields
  {
    bool enableCartesian   = true;
    bool enableSpherical   = false;
    bool enableIntensity   = false;
    bool enableTimeOffset  = false;
    bool enableRing        = false;
    bool enableLayer       = false;
    bool enableEcho        = false;
    bool enableIsReflector = false;
    bool enableHasBlooming = false;
    bool enablePulseWidth  = false;

    auto toString() const -> std::string;
  };

  struct Filters
  {
    /**
     * @brief The indices of the echos that shall be included in the point cloud. The first echo has index 0.
     * If not set, all echos are included.
     */
    std::optional<std::set<std::size_t>> selectedEchos;

    /**
     * @brief The indices of the layers that shall be included in the point cloud. The first layer has index 1.
     * If not set, all layers are included. The layer selection filter is applied in addition to the vertical angle
     * filter. A layer is included in the point cloud if it is selected by the layer filter and angle range filter.
     */
    std::optional<std::set<std::uint32_t>> selectedLayers;

    /**
     * @brief A filter for the vertical angle of the points in the point cloud. The angle is in radians. The vertical
     * angle filter is applied in addition to the layer selection filter. A layer is included in the point cloud if it
     * is selected by the layer filter and angle range filter.
     */
    Interval<Angle> azimuth;

    /**
     * @brief A filter for the horizontal angle of the points in the point cloud. The angle is in radians.
     */
    Interval<Angle> elevation;

    /**
     * @brief A filter for the range of the points in the point cloud. The filter is applied before multiplying with
     * the range scaling factor.
     */
    Interval<Distance> range;
    Interval<float> intensity;

    /**
     * @brief Set to true to only include points that are marked as reflector in the point cloud. Set to false to only
     * include points that are not marked as reflector. Set to nullopt to include all points
     */
    std::optional<bool> requiredReflectorFlag;

    /** @brief Set to true to only include points that are marked as blooming in the point cloud. Set to false to only
     * include points that are not marked as blooming. Set to nullopt to include all points
     */
    std::optional<bool> requiredBloomingFlag;

    auto toString() const -> std::string;
  };

  Fields fields;

  /**
   * @brief A scaling factor that is applied to the distance values in the scan data before they are used to calculate
   * the point cloud coordinates. For example set this to 1'000.0f to convert the distance values from meters to millimeters.
   * The default value is 1.0f, the distance values are in meters.
   */
  float distanceScalingFactor = 1.0f;

  Filters filters;

  MultiEchoPointCloud::Organization organization = MultiEchoPointCloud::Organization::Unorganized;

  auto toString() const -> std::string;
};

// NOLINTEND(misc-non-private-member-variables-in-classes)

} // namespace sick
