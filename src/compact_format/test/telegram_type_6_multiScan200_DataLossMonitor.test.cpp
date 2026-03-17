/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

#include <gtest/gtest.h>
#include <sick_perception_sdk/compact_format/telegram_type_6_multiScan200/DataLossMonitor.hpp>
#include <sick_perception_sdk/compact_format/telegram_type_6_multiScan200/MultiScan200Data.hpp>

using namespace sick;
using namespace sick::compact;
using namespace sick::compact::multiscan200;

namespace {

auto makeData(uint64_t telegramCounter, uint64_t frameNumber, uint64_t segmentIndex) -> MultiScan200Data
{
  TelegramHeaderWithSenderSerialNumber header;
  SegmentMetaData metaData;

  header.telegramCounter       = telegramCounter;
  metaData.frameSequenceNumber = frameNumber;
  metaData.segmentIndex        = segmentIndex;

  return MultiScan200Data {
    header,                                  //
    metaData,                                //
    std::vector<AmbientLightColumn>(),       //
    Geometry {},                             //
    std::vector<Distance>(),                 // distances
    std::vector<float>(),                    // intensities
    std::vector<BitField<EchoProperties>>(), // echoProperties
    std::vector<Duration>()                  // pulseWidths,
  };
}

} // namespace

TEST(Telegram_type_6_multiScan200_DataLossMonitorTest, check_uses_telegram_counter_from_telegram_header)
{
  constexpr std::uint64_t expectedFrameSequenceNumberIncrement = 1;
  constexpr std::uint64_t expectedNumberOfSegmentsPerFrame     = 12;
  DataLossMonitor monitor {expectedFrameSequenceNumberIncrement, expectedNumberOfSegmentsPerFrame};

  monitor.check(makeData(1, 10, 5));
  auto result = monitor.check(makeData(5, 10, 5)); // gap in telegram counter

  EXPECT_EQ(result.numberOfLostTelegrams, 3);
}

TEST(Telegram_type_6_multiScan200_DataLossMonitorTest, check_uses_frame_sequence_number_from_first_module_metadata)
{
  constexpr std::uint64_t expectedFrameSequenceNumberIncrement = 1;
  constexpr std::uint64_t expectedNumberOfSegmentsPerFrame     = 12;
  DataLossMonitor monitor {expectedFrameSequenceNumberIncrement, expectedNumberOfSegmentsPerFrame};

  monitor.check(makeData(1, 10, 5));
  auto result = monitor.check(makeData(2, 15, 5)); // gap in frame number

  EXPECT_EQ(result.numberOfLostFrames, 4);
}

TEST(Telegram_type_6_multiScan200_DataLossMonitorTest, check_uses_segment_index_from_first_module_metadata)
{
  constexpr std::uint64_t expectedFrameSequenceNumberIncrement = 1;
  constexpr std::uint64_t expectedNumberOfSegmentsPerFrame     = 12;
  DataLossMonitor monitor {expectedFrameSequenceNumberIncrement, expectedNumberOfSegmentsPerFrame};

  monitor.check(makeData(1, 10, 5));
  auto result = monitor.check(makeData(2, 10, 8)); // gap in segment index

  EXPECT_EQ(result.numberOfLostSegments, 2);
}
