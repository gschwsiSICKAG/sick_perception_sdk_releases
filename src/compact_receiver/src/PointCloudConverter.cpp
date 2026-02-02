/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

#include <sick_perception_sdk/compact_receiver/PointCloudConverter.hpp>

#include <sick_perception_sdk/compact_receiver/PointCloud.hpp>
#include <sick_perception_sdk/compact_receiver/PointCloudConfiguration.hpp>
#include <sick_perception_sdk/compact_receiver/ScanData.hpp>

#include <utility>

namespace sick::compact {

PointCloudConverter::PointCloudConverter()
  : m_collector(PointCloudConfiguration())
{ }

PointCloudConverter::PointCloudConverter(PointCloudConfiguration configuration)
  : m_collector(std::move(configuration))
{ }

auto PointCloudConverter::convert(scan_data::ScanData const& scanData) -> PointCloud
{
  m_collector.reset();
  m_collector.collect(scanData);
  return m_collector.getPointCloud();
}

} // namespace sick::compact
