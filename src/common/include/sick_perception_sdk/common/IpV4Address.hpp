/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

#pragma once

#include <sick_perception_sdk/common/export.hpp>

#include <array>
#include <cstdint>
#include <string>

namespace sick {

class SDK_EXPORT IpV4Address
{
public:
  // NOLINTNEXTLINE(google-explicit-constructor): ctors are not explicit so it can be used for implicit conversions from string literals
  IpV4Address(char const* str);

  // NOLINTNEXTLINE(google-explicit-constructor): ctors are not explicit so it can be used for implicit conversions from string literals
  IpV4Address(std::string const& str);

  explicit IpV4Address(std::array<std::uint8_t, 4> bytes);

  auto toString() const -> std::string;

  auto bytes() const -> std::array<std::uint8_t, 4> const&
  {
    return m_bytes;
  }

private:
  std::array<std::uint8_t, 4> m_bytes;
};

} // namespace sick
