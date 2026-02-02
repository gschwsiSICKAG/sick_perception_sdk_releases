/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

#pragma once

#include <sick_perception_sdk/common/export.hpp>
#include <sick_perception_sdk/compact_receiver/AmbientLightData.hpp>
#include <sick_perception_sdk/compact_receiver/CompactParser.hpp>

#include <vector>

namespace sick::compact::ambient_light {

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
  ) -> AmbientLightData;

  /**
   * Returns the size if the data vector contains the whole ambient light compact frame
   */
  auto getSize(std::vector<std::uint8_t>::const_iterator const& begin, std::vector<std::uint8_t>::const_iterator const& end) const
    -> std::optional<std::size_t> override;

private:
  static constexpr std::size_t kSizeOfPixel = sizeof(Column::value_type);

  /**
   * @throws std::invalid_argument if the header is invalid.
   */
  static void validateHeader(Header const& header);

  /**
   * @brief Reads ambient light payload from the data vector.
   * @return The number of bytes read.
   * @throws std::invalid_argument if there is not enough data.
   */
  static auto readPayload(std::vector<std::uint8_t>::const_iterator const& begin, std::vector<std::uint8_t>::const_iterator const& end, Payload& payload)
    -> std::vector<std::uint8_t>::difference_type;

  /**
   * @brief Reads ambient light data pixels from the data vector.
   * @return The number of bytes read.
   * @throws std::invalid_argument if there is not enough data.
   */
  static auto readPixels(
    std::vector<std::uint8_t>::const_iterator const& begin,
    std::vector<std::uint8_t>::const_iterator const& end,
    MetaData const& metaData,
    std::vector<Column>& pixels
  ) -> std::vector<std::uint8_t>::difference_type;
};

} // namespace sick::compact::ambient_light
