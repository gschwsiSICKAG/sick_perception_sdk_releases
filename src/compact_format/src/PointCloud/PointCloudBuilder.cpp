/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

#include "PointCloudBuilder.hpp"

#include <sick_perception_sdk/compact_format/PointCloud/MultiEchoPointCloud.hpp>
#include <sick_perception_sdk/compact_format/PointCloud/PointCloudConfiguration.hpp>

#include <cstdint>
#include <functional>

namespace sick {

using PointField = MultiEchoPointCloud::PointField;

auto addFields(
  PointCloudConfiguration const& config,
  std::function<void(
    MultiEchoPointCloud::PointField::FieldType fieldType, //
    MultiEchoPointCloud::PointField::DataType dataType,   //
    std::uint32_t fieldOffsetBytes
  )> const& addField
) -> std::uint32_t
{
  std::uint32_t currentOffset = 0;

  using FieldType = PointField::FieldType;
  using DataType  = PointField::DataType;
  if (config.fields.enableCartesian)
  {
    addField(FieldType::X, DataType::Float32, currentOffset);
    currentOffset += sizeof(float);
    addField(FieldType::Y, DataType::Float32, currentOffset);
    currentOffset += sizeof(float);
    addField(FieldType::Z, DataType::Float32, currentOffset);
    currentOffset += sizeof(float);
  }

  if (config.fields.enableSpherical)
  {
    addField(FieldType::Range, DataType::Float32, currentOffset);
    currentOffset += sizeof(float);
    addField(FieldType::Azimuth, DataType::Float32, currentOffset);
    currentOffset += sizeof(float);
    addField(FieldType::Elevation, DataType::Float32, currentOffset);
    currentOffset += sizeof(float);
  }

  if (config.fields.enableIntensity)
  {
    addField(FieldType::Intensity, DataType::Float32, currentOffset);
    currentOffset += sizeof(float);
  }

  if (config.fields.enableTimeOffset)
  {
    addField(FieldType::TimeOffsetNanoseconds, DataType::Uint32, currentOffset);
    currentOffset += sizeof(std::uint32_t);
    addField(FieldType::TimeOffsetSeconds, DataType::Uint32, currentOffset);
    currentOffset += sizeof(std::uint32_t);
  }

  if (config.fields.enableRing)
  {
    addField(FieldType::Ring, DataType::Uint8, currentOffset);
    currentOffset += sizeof(std::uint8_t);
  }

  if (config.fields.enableLayer)
  {
    addField(FieldType::Layer, DataType::Uint8, currentOffset);
    currentOffset += sizeof(std::uint8_t);
  }

  if (config.fields.enableEcho)
  {
    addField(FieldType::Echo, DataType::Uint8, currentOffset);
    currentOffset += sizeof(std::uint8_t);
  }

  if (config.fields.enableIsReflector)
  {
    addField(FieldType::IsReflector, DataType::Uint8, currentOffset);
    currentOffset += sizeof(std::uint8_t);
  }

  if (config.fields.enableHasBlooming)
  {
    addField(FieldType::HasBlooming, DataType::Uint8, currentOffset);
    currentOffset += sizeof(std::uint8_t);
  }

  if (config.fields.enablePulseWidth)
  {
    addField(FieldType::PulseWidth, DataType::Float32, currentOffset);
    currentOffset += sizeof(float);
  }

  return currentOffset;
}

} // namespace sick
