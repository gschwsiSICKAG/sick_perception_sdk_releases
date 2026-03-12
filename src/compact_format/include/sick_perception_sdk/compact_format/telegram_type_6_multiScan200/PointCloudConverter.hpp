/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

#pragma once

#include <sick_perception_sdk/common/export.hpp>
#include <sick_perception_sdk/compact_format/PointCloud/MultiEchoPointCloud.hpp>
#include <sick_perception_sdk/compact_format/PointCloud/PointCloudConfiguration.hpp>
#include <sick_perception_sdk/compact_format/telegram_type_6_multiScan200/MultiScan200Data.hpp>

namespace sick::compact::multiscan200 {

/**
 * @brief Converter from the intermediate `MultiScan200Data` representation into the internal `PointCloud` representation.
 */
class SDK_EXPORT PointCloudConverter
{
public:
  explicit PointCloudConverter(PointCloudConfiguration configuration);

  auto convert(MultiScan200Data const& data) const -> MultiEchoPointCloud;

private:
  PointCloudConfiguration m_configuration;
};

} // namespace sick::compact::multiscan200
