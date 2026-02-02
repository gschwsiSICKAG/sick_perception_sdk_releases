/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

#pragma once

#include <sick_perception_sdk/common/export.hpp>
#include <sick_perception_sdk/compact_receiver/PointCloud.hpp>
#include <sick_perception_sdk/compact_receiver/PointCloudCollector.hpp>
#include <sick_perception_sdk/compact_receiver/ScanData.hpp>

#include <cstdint>
#include <optional>
#include <set>

namespace sick::compact {

class SDK_EXPORT PointCloudConverter
{
public:
  PointCloudConverter();
  explicit PointCloudConverter(PointCloudConfiguration configuration);

  /**
   * @brief Converts the scan data into a point cloud.
   */
  auto convert(scan_data::ScanData const& scanData) -> PointCloud;

  /**
   * @brief Sets the indices of the echos that shall be included in the point cloud. The first echo has index 0.
   * If not set, all echos are included.
   */
  void setSelectedEchos(std::set<std::size_t> const& echoIndices);

  /**
   * @brief Sets the indices of the layers that shall be included in the point cloud. The first layer has index 1.
   * If not set, all layers are included.
   * @details The layer selection filter is applied in addition to the vertical angle filter.
   * A layer is included in the point cloud if it is selected by the layer filter and angle range filter.
   */
  void setSelectedLayers(std::set<std::uint32_t> const& layerIndices);

  /**
   * @brief Sets a filter for the vertical angle of the points in the point cloud. The angle is in radians.
   * @details The vertical angle filter is applied in addition to the layer selection filter.
   * A layer is included in the point cloud if it is selected by the layer filter and angle range filter.
   */
  void setVerticalAngleRangeRadFilter(Interval<float> interval);

  /**
   * @brief Sets a filter for the horizontal angle of the points in the point cloud. The angle is in radians.
   */
  void setHorizontalAngleRangeRadFilter(Interval<float> interval);

  /**
   * @brief Sets a scaling factor that is applied to the range values in the scan data before they are used to calculate
   * the point coordinates.
   * @details For example set this to 0.001f to convert the range values from mm to m.
   * The default value is 1.0f, i.e. no scaling.
   */
  void setRangeScalingFactor(float scalingFactor);

  /**
   * @brief Sets a filter for the range of the points in the point cloud. The filter is applied before multiplying with
   * the range scaling factor.
   */
  void setRangeFilter(Interval<float> interval);

  void setRssiFilter(Interval<float> interval);

  /**
   * @brief Set to true to only include points that are marked as reflector in the point cloud. Set to false to only
   * include points that are not marked as reflector. Set to nullopt to include all points
   */
  void setRequiredReflectorFlag(std::optional<bool> requiredReflectorFlag);

  /** @brief Set to true to only include points that are marked as blooming in the point cloud. Set to false to only
   * include points that are not marked as blooming. Set to nullopt to include all points
   */
  void setRequiredBloomingFlag(std::optional<bool> requiredBloomingFlag);

  /**
   * @brief Enables or disables the inclusion of Cartesian fields (x, y, z) in the point cloud.
   */
  void setCartesianFieldsEnabled(bool enabled);

  /**
   * @brief Enables or disables the inclusion of Spherical fields (range, azimuth = theta, elevation = phi) in the point cloud.
   */
  void setSphericalFieldsEnabled(bool enabled);

  /** @brief Enables or disables the inclusion of the RSSI field in the point cloud. */
  void setRssiFieldEnabled(bool enabled);

  /** @brief Enables or disables the inclusion of the time offset in nanoseconds field (t) in the point cloud. */
  void setTimeOffsetNanosecondsFieldEnabled(bool enabled);

  /** @brief Enables or disables the inclusion of the time offset in seconds field (ts) in the point cloud. */
  void setTimeOffsetSecondsFieldEnabled(bool enabled);

  /** @brief Enables or disables the inclusion of the ring field in the point cloud. This field contains the layerId.
   * This field has the same contents as the layer field. */
  void setRingFieldEnabled(bool enabled);

  /** @brief Enables or disables the inclusion of the layer field in the point cloud. This field contains the layerId.
   * This field has the same contents as the ring field. */
  void setLayerFieldEnabled(bool enabled);

  /** @brief Enables or disables the inclusion of the echo field in the point cloud. This field contains the index of
   * the echo from which this point originates. */
  void setEchoFieldEnabled(bool enabled);

  /** @brief Enables or disables the inclusion of the isReflector field in the point cloud. This field is true if the
   * point is marked as reflector, false otherwise. */
  void setIsReflectorFieldEnabled(bool enabled);

  /** @brief Enables or disables the inclusion of the hasBlooming field in the point cloud. This field is true if the
   * point is marked as blooming, false otherwise. */
  void setHasBloomingFieldEnabled(bool enabled);

private:
  PointCloudCollector m_collector;
};

} // namespace sick::compact
