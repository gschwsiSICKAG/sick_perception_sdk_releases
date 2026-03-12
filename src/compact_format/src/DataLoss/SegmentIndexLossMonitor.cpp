/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

#include <sick_perception_sdk/compact_format/DataLoss/SegmentIndexLossMonitor.hpp>

#include <cstdint>
#include <optional>
#include <stdexcept>

namespace sick::compact {

SegmentIndexLossMonitor::SegmentIndexLossMonitor(std::uint64_t expectedNumberOfSegmentsPerFrame)
  : m_expectedNumberOfSegmentsPerFrame(expectedNumberOfSegmentsPerFrame)
  , m_lastLinearSegmentIndex(std::nullopt)
{
  if (expectedNumberOfSegmentsPerFrame == 0u)
  {
    throw std::invalid_argument("expectedNumberOfSegmentsPerFrame must be greater than 0");
  }
}

auto SegmentIndexLossMonitor::computeNumberOfMissingElements(std::uint64_t frameSequenceNumber, std::uint64_t segmentIndex) -> int
{
  if (segmentIndex >= m_expectedNumberOfSegmentsPerFrame)
  {
    throw std::invalid_argument("segmentIndex must be smaller than expectedNumberOfSegmentsPerFrame");
  }

  if (!m_lastLinearSegmentIndex.has_value())
  {
    m_lastLinearSegmentIndex = frameSequenceNumber * m_expectedNumberOfSegmentsPerFrame + segmentIndex;
    return 0;
  }

  auto const linearSegmentIndex = frameSequenceNumber * m_expectedNumberOfSegmentsPerFrame + segmentIndex;

  if (linearSegmentIndex <= m_lastLinearSegmentIndex)
  {
    // This is a weird case. The segment index should always be increasing with the frame sequence number.
    // We don't bother with the case that the segment index has wrapped around.
    return 1;
  }

  auto const segmentIndexDiff = linearSegmentIndex - m_lastLinearSegmentIndex.value();

  m_lastLinearSegmentIndex = linearSegmentIndex;

  return static_cast<int>(segmentIndexDiff) - 1;
}

} // namespace sick::compact
