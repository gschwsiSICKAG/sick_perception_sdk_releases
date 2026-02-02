/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

#pragma once

#include <sick_perception_sdk/common/export.hpp>
#include <sick_perception_sdk/compact_receiver/CompactParser.hpp>
#include <sick_perception_sdk/compact_receiver/ScanData.hpp>

#include <functional>
#include <vector>

namespace sick::compact::scan_data {

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
  ) -> ScanData;

  /**
   * Returns the size if the data vector contains the whole scan data compact frame
   */
  auto getSize(std::vector<std::uint8_t>::const_iterator const& begin, std::vector<std::uint8_t>::const_iterator const& end) const
    -> std::optional<std::size_t> override;

private:
  // The size of some of the fields in the compact binary data is different from the data structure.
  // Beam::azimuth is a float, but in the binary data it is a std::uint16_t.
  static constexpr std::size_t kSizeOfBinaryAzimuth = sizeof(std::uint16_t);
  // Echo::distance is a float, but in the binary data it is a std::uint16_t.
  static constexpr std::size_t kSizeOfBinaryDistance = sizeof(std::uint16_t);
  // Echo::intensity is a float, but in the binary data it is a std::uint16_t.
  static constexpr std::size_t kSizeOfBinaryIntensity = sizeof(std::uint16_t);
  // In the binary data the intensity value is between 0 and 65,535, in the data structure it is between 0.0 and 1.0.
  static constexpr float kIntensityScalingFactor = 65'535.0f;

  // The offset from the start of the module meta data of the numberOfRows field.
  static constexpr std::size_t kNumberOfRowsOffset =
    sizeof(Module::MetaData::segmentIndex) + sizeof(Module::MetaData::frameSequenceNumber) + sizeof(Module::MetaData::senderSerialNumber);

  // The number of bytes by which the module meta data grows per row in the module
  static constexpr std::size_t kModuleMetaDataSizePerRow = sizeof(Module::RowMetaData);

  /**
   * @throws std::invalid_argument if the header is invalid.
   */
  static void validateHeader(Header const& header);

  /**
   * @brief Reads module meta data from the data vector.
   * @return The number of bytes read.
   * @throws std::invalid_argument if there is not enough data.
   */
  static auto readModuleMetaData(
    std::vector<std::uint8_t>::const_iterator const& begin,
    std::vector<std::uint8_t>::const_iterator const& end,
    std::uint32_t version,
    Module::MetaData& metaData
  ) -> std::vector<std::uint8_t>::difference_type;

  /**
   * @brief Reads the beam data of a module from the data vector.
   * @return The number of bytes read.
   * @throws std::invalid_argument if there is not enough data.
   */
  static auto readModuleBeamData(
    std::vector<std::uint8_t>::const_iterator const& begin,
    std::vector<std::uint8_t>::const_iterator const& end,
    Module::MetaData const& metaData,
    std::vector<Column>& columns
  ) -> std::vector<std::uint8_t>::difference_type;

  /**
   * @brief Reads a module (meta data and beams) from the data vector.
   * @return The number of bytes read.
   */
  static auto readModule(
    std::vector<std::uint8_t>::const_iterator const& begin,
    std::vector<std::uint8_t>::const_iterator const& end,
    std::uint32_t version,
    Module& module
  ) -> std::vector<std::uint8_t>::difference_type;

  /**
   * @brief Gets the number of bytes of the next module.
   * @return The number of bytes of the next module, or std::nullopt if not enough data in data.
   */
  static auto getNumberOfBytesOfNextModule(
    std::vector<std::uint8_t>::const_iterator const& begin,
    std::vector<std::uint8_t>::const_iterator const& end,
    std::uint32_t version
  ) -> std::optional<std::uint32_t>;

  template <typename ValueT>
  static auto readRowMetaDataArray(
    std::vector<std::uint8_t>::const_iterator const& begin,
    std::vector<std::uint8_t>::const_iterator const& end,
    std::size_t numberOfRows,
    std::vector<Module::RowMetaData>& rowMetaData,
    std::function<ValueT&(Module::RowMetaData&)> const& memberAccessor
  ) -> std::ptrdiff_t
  {
    std::ptrdiff_t numberOfBytesRead = 0;
    for (std::size_t i = 0; i < numberOfRows; ++i)
    {
      numberOfBytesRead += Parser::readValueUnsafe<ValueT>(begin + numberOfBytesRead, end, memberAccessor(rowMetaData[i]));
    }

    return numberOfBytesRead;
  }
};

} // namespace sick::compact::scan_data
