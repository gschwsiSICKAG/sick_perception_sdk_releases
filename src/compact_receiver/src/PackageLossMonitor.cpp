/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

#include <sick_perception_sdk/compact_receiver/PackageLossMonitor.hpp>

#include <sick_perception_sdk/common/logging/logging.hpp>
#include <sick_perception_sdk/compact_receiver/ScanData.hpp>

#include <cstdint>
#include <functional>
#include <utility>

namespace sick::compact::scan_data {

PackageLossMonitor::PackageLossMonitor(int expectedNumberOfSegmentsPerFrame, int expectedSegmentIndexIncrement)
  : m_onPackageLoss([](auto) -> void {})
  , m_expectedNumberOfSegmentsPerFrame(expectedNumberOfSegmentsPerFrame)
  , m_expectedSegmentIndexIncrement(expectedSegmentIndexIncrement)
{ }

auto PackageLossMonitor::check(ScanData const& scanData) -> MissedPackages
{
  MissedPackages missedPackages;

  if (!m_lastTelegramCounter.has_value() || !m_lastFrameNumber.has_value() || !m_lastSegmentCounter.has_value())
  {
    m_lastTelegramCounter = scanData.header.telegramCounter;
    m_lastFrameNumber     = scanData.modules[0].metaData.frameSequenceNumber;
    m_lastSegmentCounter  = scanData.modules[0].metaData.segmentIndex;
    return missedPackages;
  }

  std::uint64_t currentTelegramCounter = scanData.header.telegramCounter;
  std::uint64_t currentFrameNumber     = scanData.modules[0].metaData.frameSequenceNumber;
  std::uint64_t currentSegmentCounter  = scanData.modules[0].metaData.segmentIndex;

  if (currentTelegramCounter - m_lastTelegramCounter.value() > 1) // telegram loss, ethernet level
  {
    missedPackages.numberOfLostTelegrams = static_cast<int>(currentTelegramCounter - m_lastTelegramCounter.value());
    m_onPackageLoss(missedPackages);
    LOG_WARNING("PackageLossMonitor") << "Telegram not received, possibly due to a bad network connection. Lost " << missedPackages.numberOfLostTelegrams
                                      << " telegrams.";
  }
  else // data loss, caused on device
  {
    std::uint64_t const expectedFrameDiff = m_expectedSegmentIndexIncrement;
    if (currentFrameNumber - m_lastFrameNumber.value() > expectedFrameDiff) // lost frame, scan segment will be missing
    {
      missedPackages.numberOfLostFrames = static_cast<int>(currentFrameNumber - m_lastFrameNumber.value() - expectedFrameDiff + 1);
      m_onPackageLoss(missedPackages);
      LOG_FAST_LOOP_WARNING("PackageLossMonitor") << "Scan data frame not received, resulting in missing scan segments. Lost "
                                                  << missedPackages.numberOfLostFrames << " frames.";
    }
    else
    { // same frame, segments should increase
      std::uint64_t const diff =
        (currentSegmentCounter + m_expectedNumberOfSegmentsPerFrame - m_lastSegmentCounter.value()) % m_expectedNumberOfSegmentsPerFrame; // overflow handling
      if (diff > 1)
      {
        missedPackages.numberOfLostSegments = static_cast<int>(diff - 1);
        m_onPackageLoss(missedPackages);
        LOG_FAST_LOOP_WARNING("PackageLossMonitor") << "Scan segment not received. Lost " << missedPackages.numberOfLostSegments << " segments.";
      }
    }
  }
  m_lastSegmentCounter  = currentSegmentCounter;
  m_lastFrameNumber     = currentFrameNumber;
  m_lastTelegramCounter = currentTelegramCounter;

  return missedPackages;
}

void PackageLossMonitor::setPackageLossCallback(std::function<void(MissedPackages)> callback)
{
  m_onPackageLoss = std::move(callback);
}

} // namespace sick::compact::scan_data
