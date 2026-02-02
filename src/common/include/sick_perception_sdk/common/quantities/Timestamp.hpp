/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

#pragma once

#include <sick_perception_sdk/common/export.hpp>
#include <sick_perception_sdk/common/quantities/Duration.hpp>

#include <cstdint>
#include <ostream>
#include <string>

// NOLINTBEGIN(cppcoreguidelines-avoid-magic-numbers, readability-magic-numbers)

namespace sick {

/**
 * @ingroup Quantities
 * 
 * See quantities.hpp for an overview.
 */
class SDK_EXPORT Timestamp
{
public:
  using value_type = std::uint64_t;

  constexpr Timestamp()
    : m_microsecondsSinceEpoch(0)
  { }

  constexpr static auto fromMicrosecondsSinceEpoch(value_type microseconds) -> Timestamp
  {
    return Timestamp(microseconds);
  }

  constexpr static auto fromNanoseconds(value_type nanoseconds) -> Timestamp
  {
    return Timestamp(nanoseconds / 1'000);
  }

  constexpr auto microsecondsSinceEpoch() const -> value_type
  {
    return m_microsecondsSinceEpoch;
  }

  constexpr auto nanosecondsSinceEpoch() const -> value_type
  {
    return m_microsecondsSinceEpoch * 1'000;
  }

  /*
   * @brief Mutable access to the raw value.
   *
   * @warning Use this function with caution. It relies on convention what the internal representation is.
   * Therefore, this function should only be used for deserialization of Compact formats.
   */

  auto rawValueMutable() -> Timestamp::value_type&
  {
    return m_microsecondsSinceEpoch;
  }

private:
  /**
   * @brief The internal representation of the quantity's value.
   * 
   * @warning This member must be the same type and scaling as in the Compact format!
   */
  value_type m_microsecondsSinceEpoch;

  constexpr explicit Timestamp(value_type microseconds)
    : m_microsecondsSinceEpoch {microseconds}
  { }
};

// Comparison operators
constexpr auto operator<(Timestamp const& lhs, Timestamp const& rhs) -> bool
{
  return lhs.microsecondsSinceEpoch() < rhs.microsecondsSinceEpoch();
}

// Arithmetic operators
constexpr auto operator+(Timestamp const& lhs, Duration const& rhs) -> Timestamp
{
  return Timestamp::fromMicrosecondsSinceEpoch(lhs.microsecondsSinceEpoch() + rhs.microseconds());
}

constexpr auto operator-(Timestamp const& lhs, Timestamp const& rhs) -> Duration
{
  return Duration::fromMicroseconds(lhs.microsecondsSinceEpoch() - rhs.microsecondsSinceEpoch());
}

// Stream operators
auto SDK_EXPORT operator<<(std::ostream& stream, Timestamp const& timestamp) -> std::ostream&;

} // namespace sick

namespace std {

constexpr auto max(sick::Timestamp const& lhs, sick::Timestamp const& rhs) -> sick::Timestamp
{
  return lhs.microsecondsSinceEpoch() > rhs.microsecondsSinceEpoch() ? lhs : rhs;
}

constexpr auto min(sick::Timestamp const& lhs, sick::Timestamp const& rhs) -> sick::Timestamp
{
  return lhs.microsecondsSinceEpoch() < rhs.microsecondsSinceEpoch() ? lhs : rhs;
}

// NOLINTNEXTLINE(readability-identifier-naming): to_string is standard library style
auto SDK_EXPORT to_string(sick::Timestamp const& timestamp) -> std::string;

} // namespace std

// NOLINTEND(cppcoreguidelines-avoid-magic-numbers, readability-magic-numbers)
