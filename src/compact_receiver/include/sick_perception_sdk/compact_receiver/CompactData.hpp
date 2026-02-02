/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

#pragma once

#include <cstdint>

namespace sick::compact {

/**
   * @brief Type of a Compact telegram.
   * 
   * @note In the format description this is referred to as command ID.
   */
enum class TelegramType : std::uint32_t
{
  Invalid      = 0,
  ScanData     = 1,
  Imu          = 2,
  AmbientLight = 3,
  Encoder      = 4,
};

} // namespace sick::compact
