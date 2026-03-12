/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

#include <sick_perception_sdk/compact_format/telegram_type_1_scan_data/PointCloudConverter.hpp>

#include <sick_perception_sdk/compact_format/PointCloud/MultiEchoPointCloud.hpp>
#include <sick_perception_sdk/compact_format/PointCloud/PointCloudConfiguration.hpp>
#include <sick_perception_sdk/compact_format/telegram_type_1_scan_data/ScanData.hpp>

#include <utility>

namespace sick::compact::scan_data {

PointCloudConverter::PointCloudConverter()
  : m_collector(PointCloudConfiguration())
{ }

PointCloudConverter::PointCloudConverter(PointCloudConfiguration configuration)
  : m_collector(std::move(configuration))
{ }

auto PointCloudConverter::convert(ScanData const& scanData) -> MultiEchoPointCloud
{
  m_collector.reset();
  m_collector.collect(scanData);
  return m_collector.getPointCloud();
}

} // namespace sick::compact::scan_data
