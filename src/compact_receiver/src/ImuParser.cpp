/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

#include <sick_perception_sdk/compact_receiver/ImuParser.hpp>

#include <sick_perception_sdk/compact_receiver/CompactData.hpp>
#include <sick_perception_sdk/compact_receiver/CompactParser.hpp>
#include <sick_perception_sdk/compact_receiver/Crc32Utils.hpp>
#include <sick_perception_sdk/compact_receiver/ImuData.hpp>

#include <cstddef>
#include <cstdint>
#include <optional>
#include <stdexcept>
#include <vector>

namespace sick::compact::imu {

void Parser::validateHeader(Header const& header)
{
  if (header.startOfFrame != kStartOfFrame)
  {
    throw std::invalid_argument("Invalid start of frame");
  }
  if (header.telegramType != TelegramType::Imu)
  {
    throw std::invalid_argument("Unsupported telegram type (command ID)");
  }

  if (header.telegramVersion != 1u)
  {
    throw std::invalid_argument("Unsupported telegram version. Supported version is 1.");
  }
}

auto Parser::validateAndParse(
  std::vector<std::uint8_t>::const_iterator const& begin,
  std::vector<std::uint8_t>::const_iterator const& end,
  bool validateChecksum
) -> ImuData
{
  ImuData compactImuData {};
  sick::compact::CompactParser::readValue(begin, end, compactImuData);

  validateHeader(compactImuData.header);

  // Verify checksum
  std::uint32_t const computedChecksum = crc32(begin, begin + sizeof(ImuData) - sizeof(ImuData::checksum));
  if (validateChecksum && compactImuData.checksum != computedChecksum)
  {
    throw std::invalid_argument("Checksum verification failed");
  }

  return compactImuData;
}

auto Parser::getSize(std::vector<std::uint8_t>::const_iterator const&, std::vector<std::uint8_t>::const_iterator const&) const -> std::optional<std::size_t>
{
  return sizeof(ImuData);
}

} // namespace sick::compact::imu
