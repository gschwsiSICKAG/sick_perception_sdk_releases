/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

#include <sick_perception_sdk/compact_receiver/AmbientLightParser.hpp>

#include "../src/Crc32UtilsImpl.hpp"

#include <exception>
#include <gtest/gtest.h>

/**
 * This test suite explicitly tests only the internal CRC-32 implementation.
 * The actual implementation used in production code is selected at compile time
 * via the USE_ZLIB_CRC32 CMake option.
 */

TEST(Crc32UtilsTest, computes_correct_value)
{
  std::vector<std::uint8_t> const data {1, 2, 3, 4};
  auto const checksum = sick::compact::crc32Impl(data.begin(), data.end());
  EXPECT_EQ(0xB63CFBCD, checksum); // CRC-32/ISO-HDLC
}

TEST(Crc32UtilsTest, fails_with_reversed_iterators)
{
  std::vector<std::uint8_t> const data {1, 2, 3, 4};
  EXPECT_THROW(sick::compact::crc32Impl(data.end(), data.begin()), std::invalid_argument);
}

TEST(Crc32UtilsTest, does_not_crash_with_same_iterators)
{
  std::vector<std::uint8_t> const data {1, 2, 3, 4};
  EXPECT_NE(0xB63CFBCD, sick::compact::crc32Impl(data.begin(), data.begin()));
  EXPECT_NE(0xB63CFBCD, sick::compact::crc32Impl(data.end(), data.end()));
}

