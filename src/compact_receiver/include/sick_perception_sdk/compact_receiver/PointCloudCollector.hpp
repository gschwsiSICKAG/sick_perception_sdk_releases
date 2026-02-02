/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

#pragma once

#include <sick_perception_sdk/common/export.hpp>
#include <sick_perception_sdk/common/quantities/Angle.hpp>
#include <sick_perception_sdk/common/quantities/Duration.hpp>
#include <sick_perception_sdk/compact_receiver/PointCloud.hpp>
#include <sick_perception_sdk/compact_receiver/PointCloudConfiguration.hpp>
#include <sick_perception_sdk/compact_receiver/ScanData.hpp>

#include <chrono>
#include <cstdint>
#include <iterator>
#include <limits>
#include <map>
#include <optional>
#include <set>
#include <vector>

namespace sick::compact {

/**
 * @brief Information about a layer that is used during point cloud collection.
 */
struct SDK_EXPORT LayerInfo
{
  std::int8_t id {-1};
  bool isInPointCloud {false};
  float sinElevation {std::numeric_limits<float>::quiet_NaN()};
  float cosElevation {std::numeric_limits<float>::quiet_NaN()};
  Duration firstBeamTimestampOffset;
  Duration timestampIncrementPerBeam;
  Angle azimuthIncrementPerBeam;
};

/**
 * @brief A class that collects point cloud data from scan data messages.
 * @details Call collect() for each scan data message that shall be in one point cloud, then call getPointCloud() to get
 * all points collected so far. Call reset() to start a new point cloud.
 */
class SDK_EXPORT PointCloudCollector
{
public:
  PointCloudCollector();
  explicit PointCloudCollector(PointCloudConfiguration configuration);

  /**
   * @brief Collects the scan data into the point cloud.
   */
  void collect(scan_data::ScanData const& scanData);

  /**
   * @brief Resets the collector to start a new point cloud.
   */
  void reset();

  /**
   * @brief Returns a copy of the collected point cloud.
   */
  auto getPointCloud() -> PointCloud;

private:
  /**
   * @brief Resizes the point cloud data buffer to fit all points that will be added from the given scan data.
   */
  void resizePointCloudDataBuffer(scan_data::ScanData const& scanData);

  auto calculateLayerInfo(
    scan_data::Module::MetaData const& moduleMetaData,
    std::map<Angle, std::int8_t> const& elevationToLayerIdMapping,
    bool useAzimuthFromHeader
  ) const -> std::vector<LayerInfo>;

  void writeEcho(
    scan_data::Echo const& echo,
    float cosAzimuth,
    float sinAzimuth,
    Angle elevation,
    Angle azimuth,
    LayerInfo const& layerInfo,
    std::uint32_t beamTimestampOffsetNanoseconds,
    std::uint32_t beamTimestampOffsetSeconds,
    std::size_t echoIndex,
    bool isAReflector,
    bool hasBlooming
  );

  auto skipEcho(scan_data::Beam const& beam, scan_data::Echo const& echo, std::size_t echoIndex, bool echoIsTheLastValidEcho) const -> bool;

  PointCloudConfiguration m_configuration;

  std::vector<PointField> m_fields;
  std::uint32_t m_nextPointFieldOffset; // in bytes, increases with each added field

  scan_data::BeamContent m_requiredBeamContent;
  scan_data::EchoContent m_requiredEchoContent;

  PointCloud m_pointCloud;
  std::vector<std::uint8_t>::iterator m_pointCloudDataWritePosition;
};

} // namespace sick::compact
