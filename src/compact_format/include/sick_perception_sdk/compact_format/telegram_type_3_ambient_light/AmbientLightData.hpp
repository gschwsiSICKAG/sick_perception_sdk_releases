/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

#pragma once

#include <sick_perception_sdk/common/export.hpp>
#include <sick_perception_sdk/common/quantities/Angle.hpp>
#include <sick_perception_sdk/common/quantities/Timestamp.hpp>
#include <sick_perception_sdk/compact_format/CompactData.hpp>

#include <cstdint>
#include <vector>

/**
 * @brief This namespace contains data structures and converters for the Ambient Light Compact telegram (telegram type 3).
 */
namespace sick::compact::ambient_light {

#pragma pack(push, 1) // add pragma to prevent the compiler from adding padding bytes for alignment

struct SDK_EXPORT MetaData
{
  std::uint64_t frameSequenceNumber {0};
  Timestamp startTimestamp;
  Timestamp stopTimestamp;
  std::uint16_t numberOfLayers {0};
  std::uint16_t numberOfColumns {0};
  Angle startAzimuth;
  Angle stopAzimuth;
  Angle startElevation;
  Angle stopElevation;
  std::uint16_t encoding {0};
};

#pragma pack(pop)

using Column = std::vector<std::uint16_t>;

struct SDK_EXPORT Payload
{
  MetaData metaData;
  std::vector<Column> pixels;
};

struct SDK_EXPORT AmbientLightData
{
  TelegramHeaderWithSenderSerialNumber telegramHeader;
  Payload payload;
};

} // namespace sick::compact::ambient_light
