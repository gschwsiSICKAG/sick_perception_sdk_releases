/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

#pragma once

#include <sick_perception_sdk/common/export.hpp>

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
class SDK_EXPORT Duration
{
public:
  using value_type = std::uint64_t;

  constexpr Duration()
    : m_microseconds(0)
  { }

  constexpr static auto fromSeconds(value_type seconds) -> Duration
  {
    return Duration(seconds * 1'000'000);
  }

  constexpr static auto fromMilliseconds(value_type milliseconds) -> Duration
  {
    return Duration(milliseconds * 1'000);
  }

  constexpr static auto fromMicroseconds(value_type microseconds) -> Duration
  {
    return Duration(microseconds);
  }

  constexpr static auto fromNanoseconds(value_type nanoseconds) -> Duration
  {
    return Duration(nanoseconds / 1'000);
  }

  constexpr auto microseconds() const -> value_type
  {
    return m_microseconds;
  }

  constexpr auto nanoseconds() const -> value_type
  {
    return m_microseconds * 1'000;
  }

  constexpr auto seconds() const -> value_type
  {
    return m_microseconds / 1'000'000;
  }

private:
  /**
   * @brief The internal representation of the quantity's value.
   * 
   * @warning This member must be the same type and scaling as in the Compact format!
   */
  value_type m_microseconds;

  constexpr explicit Duration(value_type microseconds)
    : m_microseconds {microseconds}
  { }
};

// Comparison operators
constexpr auto operator<(Duration const& lhs, Duration const& rhs) -> bool
{
  return lhs.microseconds() < rhs.microseconds();
}

// Arithmetic operators
constexpr auto operator+(Duration const& lhs, Duration const& rhs) -> Duration
{
  return Duration::fromMicroseconds(lhs.microseconds() + rhs.microseconds());
}

constexpr auto operator-(Duration const& lhs, Duration const& rhs) -> Duration
{
  return Duration::fromMicroseconds(lhs.microseconds() - rhs.microseconds());
}

/**
 * Multiplication with a non-Duration scalar is useful for forming multiples of a duration and are therefore only implemented for integers.
 */
constexpr auto operator*(Duration const& lhs, std::size_t rhs) -> Duration
{
  return Duration::fromMicroseconds(lhs.microseconds() * static_cast<Duration::value_type>(rhs));
}

/**
 * Division by a non-Duration scalar is useful for forming partial durations and are therefore only implemented for integers.
 */
constexpr auto operator/(Duration const& lhs, unsigned int rhs) -> Duration
{
  return Duration::fromMicroseconds(static_cast<Duration::value_type>(lhs.microseconds() / rhs));
}

// Stream operators
auto SDK_EXPORT operator<<(std::ostream& stream, Duration const& timestamp) -> std::ostream&;

namespace literals {

constexpr auto operator"" _s(unsigned long long value) -> Duration
{
  return Duration::fromSeconds(value);
}

constexpr auto operator"" _ms(unsigned long long value) -> Duration
{
  return Duration::fromMilliseconds(value);
}

constexpr auto operator"" _us(unsigned long long value) -> Duration
{
  return Duration::fromMicroseconds(value);
}

constexpr auto operator"" _ns(unsigned long long value) -> Duration
{
  return Duration::fromNanoseconds(value);
}

} // namespace literals

} // namespace sick

namespace std {

constexpr auto min(sick::Duration const& lhs, sick::Duration const& rhs) -> sick::Duration
{
  return lhs.microseconds() < rhs.microseconds() ? lhs : rhs;
}

// NOLINTNEXTLINE(readability-identifier-naming): to_string is standard library style
auto SDK_EXPORT to_string(sick::Duration const& duration) -> std::string;

} // namespace std

// NOLINTEND(cppcoreguidelines-avoid-magic-numbers, readability-magic-numbers)
