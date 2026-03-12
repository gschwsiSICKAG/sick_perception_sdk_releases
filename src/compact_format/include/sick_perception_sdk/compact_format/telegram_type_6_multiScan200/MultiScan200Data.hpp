/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

#pragma once

#include <sick_perception_sdk/common/BitField.hpp>
#include <sick_perception_sdk/common/export.hpp>
#include <sick_perception_sdk/common/quantities/Angle.hpp>
#include <sick_perception_sdk/common/quantities/Distance.hpp>
#include <sick_perception_sdk/common/quantities/Timestamp.hpp>
#include <sick_perception_sdk/compact_format/CompactData.hpp>

#include <cstdint>
#include <limits>
#include <optional>
#include <type_traits>
#include <vector>

/**
 * @brief This namespace contains data structures and converters for the MultiScan200 Compact telegram (telegram type 6).
 */
namespace sick::compact::multiscan200 {

enum class EchoDataContent : std::uint8_t
{
  None       = 0x00,
  Intensity  = 0x01,
  PulseWidth = 0x02,
  Properties = 0x04,
  All        = Intensity | PulseWidth | Properties,
};

enum class ColumnProperties : std::uint16_t
{
  IDK = 0,
};

enum class EchoProperties : std::uint8_t
{
  IDK = 0,
};

struct SDK_EXPORT SegmentMetaData
{
  std::uint64_t frameSequenceNumber = 0;
  Timestamp frameTimestamp;
  std::uint16_t segmentIndex               = 0;
  std::uint16_t numberOfSegmentsPerFrame   = 0;
  std::uint16_t numberOfColumnsInSegment   = 0;
  std::uint16_t numberOfColumnsInFrame     = 0;
  std::uint16_t numberOfRows               = 0;
  std::uint8_t numberOfEchoes              = 0;
  std::uint16_t numberOfAmbientLightRows   = 0;
  std::uint8_t numberOfInterlaceSteps      = 0;
  std::uint8_t currentInterlaceIndex       = 0;
  std::uint8_t scanConfigurationIdentifier = 0;
  float distanceScalingFactor              = 0.0f;
  BitField<EchoDataContent> echoDataContent;
  static constexpr std::size_t reservedSize = 91;
};

using AmbientLightColumn                              = std::vector<std::uint16_t>;
static constexpr std::size_t kSizeOfAmbientLightPixel = sizeof(AmbientLightColumn::value_type);

struct SDK_EXPORT Echo
{
  Distance distance;
  std::optional<float> intensity;
  std::optional<BitField<EchoProperties>> properties;
  std::optional<Duration> pulseWidth;
};

struct SDK_EXPORT Beam
{
  std::vector<Echo> echoes;
  Angle azimuth;
  Angle elevation;
};

struct Geometry
{
  std::vector<Angle> elevations;
  std::vector<Angle> azimuths;
  std::vector<Duration> relativeTimeStamps;
  std::vector<BitField<ColumnProperties>> columnProperties;
};

using ScanColumn = std::vector<Beam>;

struct SDK_EXPORT MultiScan200Data
{
  TelegramHeaderWithSenderSerialNumber telegramHeader;
  SegmentMetaData segmentMetaData;
  std::vector<AmbientLightColumn> ambientLightData;
  Geometry geometry;
  std::vector<ScanColumn> scanData;

  std::uint32_t checksum {0};
};

} // namespace sick::compact::multiscan200
