/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

#pragma once

#include <sick_perception_sdk/common/export.hpp>

#include <cstdint>
#include <vector>

namespace sick::compact {

auto SDK_EXPORT crc32(std::vector<std::uint8_t>::const_iterator const& begin, std::vector<std::uint8_t>::const_iterator const& end) -> std::uint32_t;

} // namespace sick::compact
