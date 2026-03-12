/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

#pragma once

#include <sick_perception_sdk/common/export.hpp>
#include <sick_perception_sdk/compact_format/PointCloud/MultiEchoPointCloud.hpp>

#include <iostream>

namespace sick {

class SDK_EXPORT PointCloudToPCDConverter
{
public:
  static void convertToPCDBinary(MultiEchoPointCloud const& pointCloud, std::ostream& outputStream);
  static void convertToPCDASCII(MultiEchoPointCloud const& pointCloud, std::ostream& outputStream);
};

} // namespace sick
