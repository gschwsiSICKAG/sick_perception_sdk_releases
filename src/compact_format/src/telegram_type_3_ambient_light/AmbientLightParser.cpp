/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/
#include <sick_perception_sdk/compact_format/telegram_type_3_ambient_light/AmbientLightParser.hpp>

#include <sick_perception_sdk/common/ByteView.hpp>
#include <sick_perception_sdk/compact_format/CompactData.hpp>
#include <sick_perception_sdk/compact_format/CompactParser.hpp>
#include <sick_perception_sdk/compact_format/telegram_type_3_ambient_light/AmbientLightData.hpp>

#include <cstddef>
#include <cstdint>
#include <cstring> // for std::memcpy
#include <limits>
#include <optional>
#include <set>
#include <stdexcept>
#include <vector>

namespace sick::compact::ambient_light {

namespace {

std::set<std::uint32_t> const kSupportedTelegramVersions = {1};

constexpr std::size_t kSizeOfPixel = sizeof(Column::value_type);

auto readPixels(ByteView data, MetaData const& metaData, std::vector<Column>& pixels) -> std::size_t
{
  auto const numberOfBytesToRead = static_cast<std::size_t>(metaData.numberOfColumns) * static_cast<std::size_t>(metaData.numberOfLayers) * kSizeOfPixel;
  if (numberOfBytesToRead > static_cast<std::size_t>(std::numeric_limits<std::ptrdiff_t>::max()))
  {
    throw std::invalid_argument("Number of pixels is too large, causing overflow.");
  }

  if (data.size() < numberOfBytesToRead)
  {
    throw std::invalid_argument("Not enough data to read the pixel data.");
  }

  std::size_t readPosition = 0;
  pixels.resize(metaData.numberOfColumns);
  for (auto& column : pixels)
  {
    column.resize(metaData.numberOfLayers);
    // NOLINTNEXTLINE(cppcoreguidelines-pro-bounds-pointer-arithmetic) Pointer arithmetic is necessary here for efficient reading of the pixel data.
    std::memcpy(column.data(), data.data() + readPosition, column.size() * kSizeOfPixel);
    readPosition += column.size() * kSizeOfPixel;
  }
  return readPosition;
}

auto readPayload(ByteView data, Payload& payload) -> std::size_t
{
  std::size_t readPosition = CompactParser::readValue(data, payload.metaData);
  readPosition += readPixels(data.subview(readPosition), payload.metaData, payload.pixels);
  return readPosition;
}

} // namespace

auto Parser::validateAndParse(ByteView data, bool validateChecksum) -> AmbientLightData
{
  TelegramHeaderWithSenderSerialNumber telegramHeader {};
  std::size_t readPosition = CompactParser::readValue(data, telegramHeader);
  CompactParser::validateTelegramHeader(telegramHeader, TelegramType::AmbientLight, kSupportedTelegramVersions);

  if (validateChecksum)
  {
    CompactParser::validateChecksum(telegramHeader, data);
  }

  Payload payload;
  readPayload(data.subview(readPosition), payload);

  return {telegramHeader, payload};
}

auto Parser::getSize(ByteView data) const -> std::optional<std::size_t>
{
  if (data.size() < sizeof(TelegramHeaderWithSenderSerialNumber))
  {
    return std::nullopt;
  }

  TelegramHeaderWithSenderSerialNumber header;
  CompactParser::readValue(data, header);
  CompactParser::validateTelegramHeader(header, TelegramType::AmbientLight, kSupportedTelegramVersions);

  return sizeof(TelegramHeaderWithSenderSerialNumber) + header.payloadLength + sizeof(std::uint32_t);
}

} // namespace sick::compact::ambient_light
