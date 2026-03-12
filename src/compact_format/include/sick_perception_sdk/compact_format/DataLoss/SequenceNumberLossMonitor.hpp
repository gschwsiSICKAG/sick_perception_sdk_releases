/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

#pragma once

#include <optional>
#include <stdexcept>

namespace sick::compact {

template <typename SequenceNumberT>
class SequenceNumberLossMonitor
{
public:
  explicit SequenceNumberLossMonitor(SequenceNumberT expectedIncrement = 1)
    : m_expectedIncrement(expectedIncrement)
    , m_lastSequenceNumber(std::nullopt)
  {
    if (expectedIncrement <= 0)
    {
      throw std::invalid_argument("Expected increment must be greater than 0");
    }
  }

  virtual ~SequenceNumberLossMonitor() = default;

  SequenceNumberLossMonitor(SequenceNumberLossMonitor const&)                    = default;
  auto operator=(SequenceNumberLossMonitor const&) -> SequenceNumberLossMonitor& = default;
  SequenceNumberLossMonitor(SequenceNumberLossMonitor&&)                         = default;
  auto operator=(SequenceNumberLossMonitor&&) -> SequenceNumberLossMonitor&      = default;

  auto computeNumberOfMissingElements(SequenceNumberT currentSequenceNumber) -> int
  {
    if (!m_lastSequenceNumber.has_value())
    {
      m_lastSequenceNumber = currentSequenceNumber;
      return 0;
    }

    auto const numberOfLosses = [this, currentSequenceNumber]() -> int {
      // The weird case first. The sequence number should always be increasing.
      // We don't bother with the case that the sequence number has wrapped around.
      if (currentSequenceNumber <= m_lastSequenceNumber)
      {
        // Losses are a bit strange to compute here so we return just 1.
        return 1;
      }

      // From here we know that the diff is always greater than 0.
      auto const diff = currentSequenceNumber - m_lastSequenceNumber.value();

      if (diff == m_expectedIncrement)
      {
        return 0;
      }

      if (diff < m_expectedIncrement)
      {
        return 1;
      }

      return (diff - 1) / m_expectedIncrement;
    }();

    m_lastSequenceNumber = currentSequenceNumber;
    return numberOfLosses;
  }

private:
  SequenceNumberT m_expectedIncrement;
  std::optional<SequenceNumberT> m_lastSequenceNumber;
};

} // namespace sick::compact
