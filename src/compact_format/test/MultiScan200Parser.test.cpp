/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

#include <sick_perception_sdk/compact_format/telegram_type_6_multiScan200/MultiScan200Parser.hpp>

#include "utils/TestParams.hpp"
#include "utils/test_utils.hpp"

#include <exception>
#include <gtest/gtest.h>

TEST(MultiScan200ParserTest, valid_data_can_be_parsed)
{
  auto const data = sick::test::readBinary("data/multiScan270_0.9.0_ms270_all_fields-frame_0.bin");

  constexpr bool validateChecksum = true;
  auto const scanData             = sick::compact::multiscan200::Parser::validateAndParse(data, validateChecksum);

  EXPECT_EQ(0x02020202, scanData.telegramHeader.startOfFrame);
  EXPECT_EQ(sick::compact::TelegramType::MultiScan200, scanData.telegramHeader.telegramType);
  EXPECT_EQ(1, scanData.telegramHeader.telegramVersion);
}

TEST(MultiScan200ParserTest, invalid_data_is_detected)
{
  auto data = sick::test::readBinary("data/multiScan270_0.9.0_ms270_all_fields-frame_0.bin");
  data[42]  = 42; // Modify a byte to invalidate the checksum

  constexpr bool validateChecksum = true;
  EXPECT_THROW(sick::compact::multiscan200::Parser::validateAndParse(data, validateChecksum), std::exception);
}

TEST(MultiScan200ParserTest, corrupted_start_of_frame_is_detected)
{
  auto data = sick::test::readBinary("data/multiScan270_0.9.0_ms270_all_fields-frame_0.bin");
  data[0]   = 42;

  // Recompute the checksum to ensure that the parser does not fail due to invalid checksum.
  sick::test::recomputeChecksum(data);

  constexpr bool validateChecksum = true;
  EXPECT_THROW(sick::compact::multiscan200::Parser::validateAndParse(data, validateChecksum), std::exception);
}

TEST(MultiScan200ParserTest, corrupted_frame_id_is_detected)
{
  auto data = sick::test::readBinary("data/multiScan270_0.9.0_ms270_all_fields-frame_0.bin");
  data[4]   = 42; // Command ID is the 5th byte (index 4).

  // Recompute the checksum to ensure that the parser does not fail due to invalid checksum.
  sick::test::recomputeChecksum(data);

  constexpr bool validateChecksum = true;
  EXPECT_THROW(sick::compact::multiscan200::Parser::validateAndParse(data, validateChecksum), std::exception);
}

TEST(MultiScan200ParserTest, corrupted_telegram_version_is_detected)
{
  auto data = sick::test::readBinary("data/multiScan270_0.9.0_ms270_all_fields-frame_0.bin");
  data[24]  = 42; // Telegram version is the 25th byte (index 24).

  // Recompute the checksum to ensure that the parser does not fail due to invalid checksum.
  sick::test::recomputeChecksum(data);

  constexpr bool validateChecksum = true;
  EXPECT_THROW(sick::compact::multiscan200::Parser::validateAndParse(data, validateChecksum), std::exception);
}

TEST(MultiScan200ParserTest, injected_data_errors_are_detected)
{
  auto data = sick::test::readBinary("data/multiScan270_0.9.0_ms270_all_fields-frame_0.bin");
  data.insert(data.end() - 10'000, 42); // Inject an error byte. Do it close to the end so the test is faster.

  constexpr bool validateChecksum = true;
  EXPECT_THROW(sick::compact::multiscan200::Parser::validateAndParse(data, validateChecksum), std::exception);
}

TEST(MultiScan200ParserTest, does_not_crash_with_empty_data)
{
  std::vector<std::uint8_t> const data {};

  constexpr bool validateChecksum = true;
  EXPECT_THROW(sick::compact::multiscan200::Parser::validateAndParse(data, validateChecksum), std::exception);
}
