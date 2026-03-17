/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

#pragma once

#include <sick_perception_sdk/common/export.hpp>
#include <sick_perception_sdk/compact_format/PointCloud/MultiEchoPointCloud.hpp>

#include <iostream>
#include <string>

namespace sick::pcd {

SDK_EXPORT void convertToAscii(MultiEchoPointCloud const& pointCloud, std::ostream& outputStream);
SDK_EXPORT void convertToBinary(MultiEchoPointCloud const& pointCloud, std::ostream& outputStream);
SDK_EXPORT void writeToAsciiFile(sick::MultiEchoPointCloud const& pointCloud, std::string const& filePath);

} // namespace sick::pcd
