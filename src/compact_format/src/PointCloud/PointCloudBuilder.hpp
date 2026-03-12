/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

#include <sick_perception_sdk/compact_format/PointCloud/MultiEchoPointCloud.hpp>
#include <sick_perception_sdk/compact_format/PointCloud/PointCloudConfiguration.hpp>

#include <cstddef>
#include <cstdint>
#include <functional>

namespace sick {

/**
 * @brief Call `addField` for each field with the correct field and data types and the field offset in bytes.
 * 
 * @return The total size of one point in bytes.
 */
auto addFields(
  PointCloudConfiguration const& config,
  std::function<void(
    MultiEchoPointCloud::PointField::FieldType fieldType, //
    MultiEchoPointCloud::PointField::DataType dataType,   //
    std::uint32_t fieldOffsetBytes
  )> const& addField
) -> std::uint32_t;

} // namespace sick
