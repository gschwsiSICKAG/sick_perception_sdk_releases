/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/
#pragma once

#include <sick_perception_sdk/common/export.hpp>
#include <sick_perception_sdk/compact_receiver/CompactParser.hpp>

#include <iterator>
#include <memory>
#include <vector>

namespace sick::compact {

class SDK_EXPORT StreamExtractor
{
public:
  StreamExtractor();

  auto extractTelegrams(std::vector<std::uint8_t>::const_iterator begin, std::vector<std::uint8_t>::const_iterator end)
    -> std::vector<std::vector<std::uint8_t>>;

private:
  enum class State
  {
    WaitingForStx          = 1,
    WaitingForTelegramType = 2,
    WaitingForChecksum     = 3
  };

  std::vector<std::uint8_t> m_buffer;
  State m_state;
  std::vector<std::uint8_t>::difference_type m_stxPosition;
  std::unique_ptr<CompactParser> m_parser;

  inline auto getStxPosition() const -> std::vector<std::uint8_t>::const_iterator;

  void discardStx();

  void findStx();

  void readTelegramType();

  auto extractPacket() -> std::optional<std::vector<std::uint8_t>>;
};

} // namespace sick::compact
