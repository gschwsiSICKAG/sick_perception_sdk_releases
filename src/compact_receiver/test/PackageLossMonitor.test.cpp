/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

#include <gtest/gtest.h>
#include <sick_perception_sdk/compact_receiver/PackageLossMonitor.hpp>
#include <sick_perception_sdk/compact_receiver/ScanData.hpp>

using namespace sick::compact;
using namespace sick::compact::scan_data;

auto makeScanData(uint64_t telegramCounter, uint64_t frameNumber, uint64_t segmentIndex) -> ScanData
{
  Header header;
  Module module;
  std::vector<Module> modules;

  header.telegramCounter              = telegramCounter;
  module.metaData.frameSequenceNumber = frameNumber;
  module.metaData.segmentIndex        = segmentIndex;

  modules.push_back(module);
  return ScanData {header, modules, 0};
}

TEST(PackageLossMonitorTest, no_frame_losses_on_first_call)
{
  PackageLossMonitor monitor {12};

  auto result = monitor.check(makeScanData(1, 10, 5));

  EXPECT_EQ(result.numberOfLostTelegrams, 0u);
  EXPECT_EQ(result.numberOfLostFrames, 0u);
  EXPECT_EQ(result.numberOfLostSegments, 0u);
}

TEST(PackageLossMonitorTest, telegram_counter_without_gaps_no_loss_detected)
{
  PackageLossMonitor monitor {12};

  monitor.check(makeScanData(1, 10, 5));
  auto result = monitor.check(makeScanData(2, 10, 5));

  EXPECT_EQ(result.numberOfLostTelegrams, 0u);
  EXPECT_EQ(result.numberOfLostFrames, 0u);
  EXPECT_EQ(result.numberOfLostSegments, 0u);
}

TEST(PackageLossMonitorTest, frame_counter_without_gaps_no_loss_detected)
{
  PackageLossMonitor monitor {12};

  monitor.check(makeScanData(1, 10, 5));
  auto result = monitor.check(makeScanData(2, 11, 5));

  EXPECT_EQ(result.numberOfLostTelegrams, 0u);
  EXPECT_EQ(result.numberOfLostFrames, 0u);
  EXPECT_EQ(result.numberOfLostSegments, 0u);
}

TEST(PackageLossMonitorTest, segment_counter_without_gaps_no_loss_detected)
{
  PackageLossMonitor monitor {12};

  monitor.check(makeScanData(1, 10, 5));
  auto result = monitor.check(makeScanData(2, 10, 6));

  EXPECT_EQ(result.numberOfLostTelegrams, 0u);
  EXPECT_EQ(result.numberOfLostFrames, 0u);
  EXPECT_EQ(result.numberOfLostSegments, 0u);
}

TEST(PackageLossMonitorTest, telegram_counter_with_gap_loss_detected)
{
  PackageLossMonitor monitor {12};

  monitor.check(makeScanData(1, 10, 5));
  auto result = monitor.check(makeScanData(3, 10, 5));

  EXPECT_EQ(result.numberOfLostTelegrams, 2u);
  EXPECT_EQ(result.numberOfLostFrames, 0u);
  EXPECT_EQ(result.numberOfLostSegments, 0u);
}

TEST(PackageLossMonitorTest, frame_counter_with_gap_loss_detected)
{
  PackageLossMonitor monitor {12};

  monitor.check(makeScanData(1, 10, 5));
  auto result = monitor.check(makeScanData(2, 12, 5));

  EXPECT_EQ(result.numberOfLostTelegrams, 0u);
  EXPECT_EQ(result.numberOfLostFrames, 2u);
  EXPECT_EQ(result.numberOfLostSegments, 0u);
}

TEST(PackageLossMonitorTest, segment_counter_with_gap_loss_detected)
{
  PackageLossMonitor monitor {12};

  monitor.check(makeScanData(1, 10, 5));
  auto result = monitor.check(makeScanData(2, 10, 7));

  EXPECT_EQ(result.numberOfLostTelegrams, 0u);
  EXPECT_EQ(result.numberOfLostFrames, 0u);
  EXPECT_EQ(result.numberOfLostSegments, 1u);
}

TEST(PackageLossMonitorTest, telegram_loss_detected_followed_by_no_loss)
{
  PackageLossMonitor monitor {12};

  monitor.check(makeScanData(1, 10, 5));
  auto result1 = monitor.check(makeScanData(5, 10, 5));

  EXPECT_EQ(result1.numberOfLostTelegrams, 4u);
  EXPECT_EQ(result1.numberOfLostFrames, 0u);
  EXPECT_EQ(result1.numberOfLostSegments, 0u);
  auto result2 = monitor.check(makeScanData(6, 10, 5));

  EXPECT_EQ(result2.numberOfLostTelegrams, 0u);
  EXPECT_EQ(result2.numberOfLostFrames, 0u);
  EXPECT_EQ(result2.numberOfLostSegments, 0u);
}

TEST(PackageLossMonitorTest, frame_loss_detected_followed_by_no_loss)
{
  PackageLossMonitor monitor {12};

  monitor.check(makeScanData(1, 10, 5));
  auto result1 = monitor.check(makeScanData(2, 14, 5));

  EXPECT_EQ(result1.numberOfLostTelegrams, 0u);
  EXPECT_EQ(result1.numberOfLostFrames, 4u);
  EXPECT_EQ(result1.numberOfLostSegments, 0u);
  auto result2 = monitor.check(makeScanData(3, 15, 5));

  EXPECT_EQ(result2.numberOfLostTelegrams, 0u);
  EXPECT_EQ(result2.numberOfLostFrames, 0u);
  EXPECT_EQ(result2.numberOfLostSegments, 0u);
}

TEST(PackageLossMonitorTest, segment_loss_detected_followed_by_no_loss)
{
  PackageLossMonitor monitor {12};

  monitor.check(makeScanData(1, 10, 5));
  auto result1 = monitor.check(makeScanData(2, 10, 9));

  EXPECT_EQ(result1.numberOfLostTelegrams, 0u);
  EXPECT_EQ(result1.numberOfLostFrames, 0u);
  EXPECT_EQ(result1.numberOfLostSegments, 3u);
  auto result2 = monitor.check(makeScanData(3, 10, 10));

  EXPECT_EQ(result2.numberOfLostTelegrams, 0u);
  EXPECT_EQ(result2.numberOfLostFrames, 0u);
  EXPECT_EQ(result2.numberOfLostSegments, 0u);
}

TEST(PackageLossMonitorTest, telegram_loss_via_callback)
{
  PackageLossMonitor monitor {12};
  PackageLossMonitor::MissedPackages localMissedPackages;

  monitor.setPackageLossCallback([&](PackageLossMonitor::MissedPackages missedPackages) {
    localMissedPackages = missedPackages;
  });
  monitor.check(makeScanData(1, 1, 1));
  monitor.check(makeScanData(5, 2, 2));
  EXPECT_EQ(localMissedPackages.numberOfLostTelegrams, 4u);
}

TEST(PackageLossMonitorTest, frame_loss_via_callback)
{
  PackageLossMonitor monitor {12};
  PackageLossMonitor::MissedPackages localMissedPackages;

  monitor.setPackageLossCallback([&](PackageLossMonitor::MissedPackages missedPackages) {
    localMissedPackages = missedPackages;
  });
  monitor.check(makeScanData(1, 1, 1));
  monitor.check(makeScanData(2, 5, 2));
  EXPECT_EQ(localMissedPackages.numberOfLostFrames, 4u);
}

TEST(PackageLossMonitorTest, segment_loss_via_callback)
{
  PackageLossMonitor monitor {12};
  PackageLossMonitor::MissedPackages localMissedPackages;

  monitor.setPackageLossCallback([&](PackageLossMonitor::MissedPackages missedPackages) {
    localMissedPackages = missedPackages;
  });
  monitor.check(makeScanData(1, 1, 1));
  monitor.check(makeScanData(2, 2, 5));
  EXPECT_EQ(localMissedPackages.numberOfLostSegments, 3u);
}

TEST(PackageLossMonitorTest, segment_loss_with_overflow)
{
  PackageLossMonitor monitor {12};
  PackageLossMonitor::MissedPackages localMissedPackages;

  monitor.setPackageLossCallback([&](PackageLossMonitor::MissedPackages missedPackages) {
    localMissedPackages = missedPackages;
  });
  monitor.check(makeScanData(1, 1, 11));
  monitor.check(makeScanData(2, 2, 1));
  EXPECT_EQ(localMissedPackages.numberOfLostSegments, 1u);
}

TEST(PackageLossMonitorTest, segment_no_loss_with_overflow)
{
  PackageLossMonitor monitor {12};
  PackageLossMonitor::MissedPackages localMissedPackages;

  monitor.setPackageLossCallback([&](PackageLossMonitor::MissedPackages missedPackages) {
    localMissedPackages = missedPackages;
  });
  monitor.check(makeScanData(1, 1, 11));
  monitor.check(makeScanData(2, 2, 0));
  EXPECT_EQ(localMissedPackages.numberOfLostSegments, 0u);
}
