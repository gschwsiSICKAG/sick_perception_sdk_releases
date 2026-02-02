/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

#pragma once

#include <sick_perception_sdk/common/export.hpp>
#include <sick_perception_sdk/compact_receiver/AmbientLightData.hpp>
#include <sick_perception_sdk/compact_receiver/ScanData.hpp>

#include <cstdint>
#include <functional>
#include <optional>
#include <string>

namespace sick::compact::scan_data {

/**
 * @brief Detect data losses in a ScanData stream. 
 * 
 * The detection is based on the telegram index, segment index, and frame index.
 * A telegram loss happens on ethernet level and indicates an issue with sending or receiving.
 * Segment and frame losses are caused on device, for example due to high system load.
 */
class SDK_EXPORT PackageLossMonitor
{
public:
  struct SDK_EXPORT MissedPackages
  {
    int numberOfLostTelegrams = 0;
    int numberOfLostFrames    = 0;
    int numberOfLostSegments  = 0;
  };

  /**
   * @brief
   * 
   * @param expectedNumberOfSegmentsPerFrame The expected number of segments per full scan frame. This number depends on the device type and its configuration.
   * @param expectedSegmentIndexIncrement The expected increment of the segment index between subsequent telegrams.
   */
  explicit PackageLossMonitor(int expectedNumberOfSegmentsPerFrame, int expectedSegmentIndexIncrement = 1);

  /**
   * @brief Analyze the given ScanData for lost telegrams, frames, or segments.
   * 
   * If registered, the callback set via `setPackageLossCallback()` is invoked when losses are detected.
   */
  auto check(ScanData const& scanData) -> MissedPackages;

  /**
   * @brief Register a callback invoked whenever a loss is detected (telegram/frame/segment).
   * 
   * The callback is called when `check()` is called, 
   * so the callback is called from the context of the caller of `check()`.
   */
  void setPackageLossCallback(std::function<void(MissedPackages)> callback);

private:
  std::optional<std::uint64_t> m_lastTelegramCounter;
  std::optional<std::uint64_t> m_lastFrameNumber;
  std::optional<std::uint64_t> m_lastSegmentCounter;
  std::function<void(MissedPackages)> m_onPackageLoss;
  int m_expectedNumberOfSegmentsPerFrame;
  int m_expectedSegmentIndexIncrement;
};

} // namespace sick::compact::scan_data
