/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

#include <sick_perception_sdk/compact_receiver/Crc32Utils.hpp>

#include <cstdint>
#include <iterator>
#include <vector>

#ifdef USE_ZLIB_CRC32
#  include <zconf.h>
#  include <zlib.h>
#else
#  include "Crc32UtilsImpl.hpp"
#endif

namespace sick::compact {

auto crc32(std::vector<std::uint8_t>::const_iterator const& begin, std::vector<std::uint8_t>::const_iterator const& end) -> std::uint32_t
{
#ifdef USE_ZLIB_CRC32
  // NOLINTNEXTLINE(cppcoreguidelines-pro-type-reinterpret-cast)
  return ::crc32(0, reinterpret_cast<Bytef const*>(&*begin), static_cast<uInt>(std::distance(begin, end)));
#else
  return crc32Impl(begin, end);
#endif
}

} // namespace sick::compact
