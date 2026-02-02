/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

#pragma once

#include <sick_perception_sdk/common/export.hpp>
#include <sick_perception_sdk/compact_receiver/CompactParser.hpp>
#include <sick_perception_sdk/compact_receiver/EncoderData.hpp>

#include <optional>
#include <vector>

namespace sick::compact::encoder {

class SDK_EXPORT Parser : public CompactParser
{
public:
  static auto validateAndParse(
    std::vector<std::uint8_t>::const_iterator const& begin,
    std::vector<std::uint8_t>::const_iterator const& end,
    bool validateChecksum
  ) -> EncoderData;

  auto getSize(std::vector<std::uint8_t>::const_iterator const& begin, std::vector<std::uint8_t>::const_iterator const& end) const
    -> std::optional<size_t> override;

private:
  static void validateHeader(Header const& header);
};

} // namespace sick::compact::encoder
