/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/
#include <sick_perception_sdk/compact_receiver/AmbientLightParser.hpp>

#include <sick_perception_sdk/compact_receiver/AmbientLightData.hpp>
#include <sick_perception_sdk/compact_receiver/CompactData.hpp>
#include <sick_perception_sdk/compact_receiver/CompactParser.hpp>
#include <sick_perception_sdk/compact_receiver/Crc32Utils.hpp>

#include <cstddef>
#include <cstdint>
#include <cstring> // for std::memcpy
#include <iterator>
#include <limits>
#include <optional>
#include <stdexcept>
#include <vector>

namespace sick::compact::ambient_light {

void Parser::validateHeader(Header const& header)
{
  if (header.startOfFrame != kStartOfFrame)
  {
    throw std::invalid_argument("Invalid start of frame");
  }
  if (header.telegramType != TelegramType::AmbientLight)
  {
    throw std::invalid_argument("Unsupported telegram type (command ID)");
  }

  if (header.telegramVersion != 1)
  {
    throw std::invalid_argument("Unsupported telegram version. Supported version is 1.");
  }
}

auto Parser::readPixels(
  std::vector<std::uint8_t>::const_iterator const& begin,
  std::vector<std::uint8_t>::const_iterator const& end,
  MetaData const& metaData,
  std::vector<Column>& pixels
) -> std::vector<std::uint8_t>::difference_type
{
  auto const numberOfBytesToRead = static_cast<std::size_t>(metaData.numberOfColumns) * static_cast<std::size_t>(metaData.numberOfLayers) * kSizeOfPixel;
  if (numberOfBytesToRead > static_cast<std::size_t>(std::numeric_limits<std::ptrdiff_t>::max()))
  {
    throw std::invalid_argument("Number of pixels is too large, causing overflow.");
  }

  if (std::distance(begin, end) < static_cast<std::ptrdiff_t>(numberOfBytesToRead))
  {
    throw std::invalid_argument("Not enough data to read the pixel data.");
  }

  auto readPosition = begin;
  pixels.resize(metaData.numberOfColumns);
  for (auto& column : pixels)
  {
    column.resize(metaData.numberOfLayers);
    std::memcpy(column.data(), &*readPosition, column.size() * kSizeOfPixel);
    readPosition += static_cast<std::vector<std::uint8_t>::difference_type>(column.size() * kSizeOfPixel);
  }
  return std::distance(begin, readPosition);
}

auto Parser::readPayload(std::vector<std::uint8_t>::const_iterator const& begin, std::vector<std::uint8_t>::const_iterator const& end, Payload& payload)
  -> std::vector<std::uint8_t>::difference_type
{
  auto readPosition = begin + sick::compact::CompactParser::readValue(begin, end, payload.metaData);
  readPosition += readPixels(readPosition, end, payload.metaData, payload.pixels);
  return std::distance(begin, readPosition);
}

auto Parser::validateAndParse(
  std::vector<std::uint8_t>::const_iterator const& begin,
  std::vector<std::uint8_t>::const_iterator const& end,
  bool validateChecksum
) -> AmbientLightData
{
  Header header {};
  auto readPosition = begin + sick::compact::CompactParser::readValue(begin, end, header);
  validateHeader(header);

  Payload payload;
  readPosition += readPayload(readPosition, end, payload);

  // read checksum
  std::uint32_t receivedChecksum = 0;
  readPosition += readValue(readPosition, end, receivedChecksum);

  // Verify checksum
  std::uint32_t const computedChecksum = crc32(begin, readPosition - 4);
  if (validateChecksum && receivedChecksum != computedChecksum)
  {
    throw std::invalid_argument("Checksum verification failed");
  }

  return {header, payload, receivedChecksum};
}

auto Parser::getSize(std::vector<std::uint8_t>::const_iterator const& begin, std::vector<std::uint8_t>::const_iterator const& end) const
  -> std::optional<std::size_t>
{
  if (std::distance(begin, end) < sizeof(Header))
  {
    return std::nullopt;
  }
  Header header {};
  sick::compact::CompactParser::readValue(begin, end, header);
  validateHeader(header);

  std::size_t const totalSize = sizeof(Header) + header.payloadLength + sizeof(AmbientLightData::checksum);
  return totalSize;
}

} // namespace sick::compact::ambient_light
