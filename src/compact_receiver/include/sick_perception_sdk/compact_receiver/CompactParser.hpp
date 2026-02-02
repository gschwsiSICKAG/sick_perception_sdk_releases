/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

#pragma once

#include <sick_perception_sdk/common/export.hpp>

#include <cstdint>
#include <cstring> // for std::memcpy
#include <limits>
#include <optional>
#include <stdexcept>
#include <vector>

namespace sick::compact {

class SDK_EXPORT CompactParser
{
public:
  static constexpr std::uint32_t kStartOfFrame = 0x02020202u;

  CompactParser()                                        = default;
  virtual ~CompactParser()                               = default;
  CompactParser(CompactParser const&)                    = default;
  auto operator=(CompactParser const&) -> CompactParser& = default;
  CompactParser(CompactParser&&)                         = default;
  auto operator=(CompactParser&&) -> CompactParser&      = default;

  virtual auto getSize(std::vector<std::uint8_t>::const_iterator const& begin, std::vector<std::uint8_t>::const_iterator const& end) const
    -> std::optional<std::size_t> = 0;

  virtual auto isChecksumValid(std::vector<std::uint8_t>::const_iterator const& begin, std::vector<std::uint8_t>::const_iterator const& end) const -> bool;

protected:
  /**
   * @brief Reads a value of type T from the data vector without bounds check.
   * @tparam T The type of value to read.
   * @param data The input data vector.
   * @param readPosition The position to start reading from.
   * @param value The variable to store the read value.
   * @return The number of bytes read.
   */
  template <typename T>
  static auto readValueUnsafe(std::vector<std::uint8_t>::const_iterator const& begin, std::vector<std::uint8_t>::const_iterator const& end, T& value)
    -> std::vector<std::uint8_t>::difference_type
  {
#ifdef UNSAFE_MEMCPY_ALLOWED
    std::memcpy(reinterpret_cast<void*>(&value), &*begin, sizeof(T));
    return sizeof(T);
#else
    return readValue(begin, end, value);
#endif
  }

  /**
   * @brief Reads a value of type T from the data vector with bounds check.
   * @tparam T The type of value to read.
   * @param data The input data vector.
   * @param readPosition The position to start reading from.
   * @param value The variable to store the read value.
   * @return The number of bytes read.
   * @throws std::invalid_argument if there is not enough data.
   */
  template <typename T>
  static auto readValue(std::vector<std::uint8_t>::const_iterator const& begin, std::vector<std::uint8_t>::const_iterator const& end, T& value)
    -> std::vector<std::uint8_t>::difference_type
  {
    auto const distance = std::distance(begin, end);
    if (distance < 0)
    {
      throw std::invalid_argument("Begin iterator invalid");
    }
    if (distance < sizeof(T))
    {
      throw std::invalid_argument("Not enough data to read the value");
    }
    std::memcpy(&value, &*begin, sizeof(T));
    return sizeof(T);
  }

  /**
   * @brief Reads an array of elements from the source vector.
   * @tparam T The type of elements.
   * @param source The input data vector.
   * @param readPosition The position to start reading from.
   * @param numberOfElements The number of elements to read.
   * @param destination The vector to fill with read elements.
   * @return The number of bytes read.
   * @throws std::invalid_argument if there is not enough data.
   */
  template <typename T>
  static auto readArray(
    std::vector<std::uint8_t>::const_iterator const& begin,
    std::vector<std::uint8_t>::const_iterator const& end,
    std::size_t numberOfElements,
    std::vector<T>& destination
  ) -> std::vector<std::uint8_t>::difference_type
  {
    std::size_t bytesToRead = numberOfElements * sizeof(T);
    if (bytesToRead > static_cast<std::size_t>(std::numeric_limits<std::ptrdiff_t>::max()))
    {
      throw std::invalid_argument("Number of elements is too large, causing overflow.");
    }

    if (std::distance(begin, end) < static_cast<std::ptrdiff_t>(bytesToRead))
    {
      throw std::invalid_argument("Not enough data to read the array.");
    }
    destination.resize(numberOfElements);
    std::memcpy(destination.data(), &*begin, bytesToRead);
    return static_cast<std::vector<std::uint8_t>::difference_type>(bytesToRead);
  }
};

} // namespace sick::compact
