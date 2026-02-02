/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

#include "Crc32UtilsImpl.hpp"

#include <cstdint>
#include <iterator>
#include <stdexcept>
#include <vector>

namespace sick::compact {

auto crc32Impl(std::vector<std::uint8_t>::const_iterator const& begin, std::vector<std::uint8_t>::const_iterator const& end) -> std::uint32_t
{
  if (std::distance(begin, end) < 0)
  {
    throw std::invalid_argument("Reversed iterators are not allowed.");
  }

  constexpr std::uint32_t startValue = 0xffffffffu;
  constexpr std::uint32_t polynomial = 0xedb88320u;
  constexpr int bitsPerByte          = 8;

  std::uint32_t crc = startValue;
  for (auto it = begin; it != end; ++it)
  {
    crc ^= *it;
    for (int i = 0; i < bitsPerByte; i++)
    {
      crc = static_cast<bool>(crc & 1) ? (crc >> 1) ^ polynomial : crc >> 1;
    }
  }
  return ~crc;
}

} // namespace sick::compact
