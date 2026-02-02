/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

// NOLINTBEGIN(readability-identifier-naming,readability-identifier-length)

#pragma once

#include <nlohmann/json.hpp>
#include <stdexcept>

namespace sick {

template <int min, int max, int defaultValue>
class NumericRange
{
public:
  constexpr NumericRange()
    : m_value(defaultValue)
  {
    static_assert(defaultValue >= min && defaultValue <= max, "Default value is out of range");
  }

  // NOLINTNEXTLINE(google-explicit-constructor): implicit conversion from int is desired
  constexpr NumericRange(int value)
    : m_value(value)
  {
    if (value < min || value > max)
    {
      throw std::out_of_range("Value " + std::to_string(value) + " is out of range [" + std::to_string(min) + ", " + std::to_string(max) + "]");
    }
  }

  constexpr auto value() const
  {
    return m_value;
  }

private:
  int m_value;
};

template <int min, int max, int defaultValue>
inline void from_json(nlohmann::json const& j, NumericRange<min, max, defaultValue>& r)
{
  int value = j.get<int>();
  r         = NumericRange<min, max, defaultValue>(value);
}

} // namespace sick

// NOLINTEND(readability-identifier-naming,readability-identifier-length)
