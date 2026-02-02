/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

#pragma once

// NOLINTBEGIN(misc-non-private-member-variables-in-classes)

#include <sick_perception_sdk/common/export.hpp>
#include <sick_perception_sdk/common/quantities/Angle.hpp>
#include <sick_perception_sdk/common/quantities/Distance.hpp>

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
   */
  auto isEmpty() const -> bool
  {
    return min && max && *min > *max && !invert;
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
    /**
     * @brief Enables or disables the inclusion of Cartesian fields (x, y, z) in the point cloud.
     */
    bool enableCartesian = true;

    /**
     * @brief Enables or disables the inclusion of Spherical fields (range, azimuth = theta, elevation = phi) in the point cloud.
     */
    bool enableSpherical = false;

    /** @brief Enables or disables the inclusion of the intensity (RSSI) field in the point cloud. */
    bool enableIntensity = false;

    /** @brief Enables or disables the inclusion of the time offset in nanoseconds field (t) in the point cloud. */
    bool enableTimeOffsetNanoseconds = false;

    /** @brief Enables or disables the inclusion of the time offset in seconds field (ts) in the point cloud. */
    bool enableTimeOffsetSeconds = false;

    /** @brief Enables or disables the inclusion of the ring field in the point cloud. This field contains the layerId.
     * This field has the same contents as the layer field. */
    bool enableRing = false;

    /** @brief Enables or disables the inclusion of the layer field in the point cloud. This field contains the layerId.
     * This field has the same contents as the ring field. */
    bool enableLayer = false;

    /** @brief Enables or disables the inclusion of the echo field in the point cloud. This field contains the index of
     * the echo from which this point originates. */
    bool enableEcho = false;

    /** @brief Enables or disables the inclusion of the isReflector field in the point cloud. This field is true if the
     * point is marked as reflector, false otherwise. */
    bool enableIsReflector = false;

    /** @brief Enables or disables the inclusion of the hasBlooming field in the point cloud. This field is true if the
     * point is marked as blooming, false otherwise. */
    bool enableHasBlooming = false;

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

  auto toString() const -> std::string;
};

// NOLINTEND(misc-non-private-member-variables-in-classes)

} // namespace sick
