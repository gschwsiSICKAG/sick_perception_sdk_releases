/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

#include <sick_perception_sdk/compact_receiver/CompactParser.hpp>

#include <sick_perception_sdk/compact_receiver/Crc32Utils.hpp>

#include <cstdint>
#include <cstring> // for std::memcpy
#include <iterator>
#include <vector>

static_assert(sizeof(float) == 4);

namespace sick::compact {

auto CompactParser::isChecksumValid(std::vector<std::uint8_t>::const_iterator const& begin, std::vector<std::uint8_t>::const_iterator const& end) const -> bool
{
  // Assumes that the CRC32 is the last four bytes
  if (std::distance(begin, end) < sizeof(std::uint32_t))
  {
    return false;
  }

  std::uint32_t expectedCRC = 0;
  std::memcpy(&expectedCRC, &*(end - sizeof(std::uint32_t)), sizeof(std::uint32_t));

  // Compute the CRC32 of the data
  std::uint32_t const computedCRC = crc32(begin, end - sizeof(std::uint32_t));
  return expectedCRC == computedCRC;
}

} // namespace sick::compact
