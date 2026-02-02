/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

#pragma once

#include <sick_perception_sdk/common/export.hpp>
#include <sick_perception_sdk/compact_receiver/CompactParser.hpp>
#include <sick_perception_sdk/compact_receiver/ImuData.hpp>

#include <vector>

namespace sick::compact::imu {

class SDK_EXPORT Parser : public CompactParser
{
public:
  /**
   * @throws std::invalid_argument if validation or parsing fails.
   */
  static auto validateAndParse(
    std::vector<std::uint8_t>::const_iterator const& begin,
    std::vector<std::uint8_t>::const_iterator const& end,
    bool validateChecksum
  ) -> ImuData;

  /**
   * Returns the size if the data vector contains the whole imu compact frame
   */
  auto getSize(std::vector<std::uint8_t>::const_iterator const& begin, std::vector<std::uint8_t>::const_iterator const& end) const
    -> std::optional<std::size_t> override;

private:
  /**
   * @brief Validates the header fields.
   * @param header The header to validate.
   * @throws std::invalid_argument if the header is invalid.
   */
  static void validateHeader(Header const& header);
};

} // namespace sick::compact::imu
