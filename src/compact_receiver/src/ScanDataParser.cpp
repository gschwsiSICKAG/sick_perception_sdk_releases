/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

#include <sick_perception_sdk/compact_receiver/ScanDataParser.hpp>

#include <sick_perception_sdk/common/logging/logging.hpp>
#include <sick_perception_sdk/common/quantities/Angle.hpp>
#include <sick_perception_sdk/common/quantities/Timestamp.hpp>
#include <sick_perception_sdk/compact_receiver/CompactData.hpp>
#include <sick_perception_sdk/compact_receiver/CompactParser.hpp>
#include <sick_perception_sdk/compact_receiver/Crc32Utils.hpp>
#include <sick_perception_sdk/compact_receiver/ScanData.hpp>

#include <cassert>
#include <cstddef>
#include <cstdint>
#include <cstring>
#include <iterator>
#include <limits>
#include <optional>
#include <stdexcept>
#include <vector>

namespace sick::compact::scan_data {

void Parser::validateHeader(Header const& header)
{
  if (header.startOfFrame != kStartOfFrame)
  {
    throw std::invalid_argument("Invalid start of frame");
  }
  if (header.telegramType != TelegramType::ScanData)
  {
    throw std::invalid_argument("Unsupported telegram type (command ID)");
  }

  if (header.telegramVersion != 3 && header.telegramVersion != 4)
  {
    throw std::invalid_argument("Unsupported telegram version. Supported versions are 3 and 4.");
  }
}

auto Parser::readModuleMetaData(
  std::vector<std::uint8_t>::const_iterator const& begin,
  std::vector<std::uint8_t>::const_iterator const& end,
  std::uint32_t version,
  Module::MetaData& metaData
) -> std::vector<std::uint8_t>::difference_type
{
  std::uint8_t reserved = 0;

  std::size_t metaDataFixedSize =
    sizeof(metaData.segmentIndex)                //
    + sizeof(metaData.frameSequenceNumber)       //
    + sizeof(metaData.senderSerialNumber)        //
    + sizeof(metaData.numberOfRows)              //
    + sizeof(metaData.numberOfColumns)           //
    + sizeof(metaData.numberOfEchoesPerBeam)     //
    + sizeof(metaData.numberOfBytesOfNextModule) //
    + sizeof(std::uint8_t)                       // availability, not stored in meta data
    + sizeof(metaData.echoContent)               //
    + sizeof(metaData.beamContent)               //
    + sizeof(reserved);

  if (version == 4)
  {
    metaDataFixedSize += sizeof(metaData.distanceScalingFactor); // Only available in version 4
  }

  assert(metaDataFixedSize <= static_cast<std::size_t>(std::numeric_limits<std::ptrdiff_t>::max()));
  if (std::distance(begin, end) < static_cast<std::ptrdiff_t>(metaDataFixedSize))
  {
    throw std::invalid_argument("Not enough data to read the module meta data.");
  }

  auto readPosition = begin;

  // FIXME Potential for optimization: Read all of those variables at once with a single
  // memcpy(&metaData.segmentCounter, data.data() + readPosition, sizeOfFirstFixedSizePortionOfMetaData)
  readPosition += sick::compact::CompactParser::readValueUnsafe(readPosition, end, metaData.segmentIndex);
  readPosition += sick::compact::CompactParser::readValueUnsafe(readPosition, end, metaData.frameSequenceNumber);
  readPosition += sick::compact::CompactParser::readValueUnsafe(readPosition, end, metaData.senderSerialNumber);
  readPosition += sick::compact::CompactParser::readValueUnsafe(readPosition, end, metaData.numberOfRows);
  readPosition += sick::compact::CompactParser::readValueUnsafe(readPosition, end, metaData.numberOfColumns);
  readPosition += sick::compact::CompactParser::readValueUnsafe(readPosition, end, metaData.numberOfEchoesPerBeam);

  auto const metaDataVariableSize = metaData.numberOfRows * sizeof(Module::RowMetaData);
  if (metaDataFixedSize + metaDataVariableSize > static_cast<std::size_t>(std::numeric_limits<std::ptrdiff_t>::max()))
  {
    throw std::invalid_argument("Number of layers is too large, causing overflow.");
  }
  if (std::distance(readPosition, end) < static_cast<std::ptrdiff_t>(metaDataFixedSize + metaDataVariableSize))
  {
    throw std::invalid_argument("Not enough data to read the module meta data.");
  }

  // Row meta data
  auto const numberOfRows = static_cast<std::size_t>(metaData.numberOfRows);
  metaData.rowMetaData    = std::vector<Module::RowMetaData>(numberOfRows);
  readPosition += readRowMetaDataArray<Timestamp::value_type>(
    readPosition,
    end,
    numberOfRows,
    metaData.rowMetaData,
    [](Module::RowMetaData& metaData) -> Timestamp::value_type& {
      return metaData.firstBeamTimestamp.rawValueMutable();
    }
  );
  readPosition += readRowMetaDataArray<Timestamp::value_type>(
    readPosition,
    end,
    numberOfRows,
    metaData.rowMetaData,
    [](Module::RowMetaData& metaData) -> Timestamp::value_type& {
      return metaData.lastBeamTimestamp.rawValueMutable();
    }
  );
  readPosition +=
    readRowMetaDataArray<Angle::value_type>(readPosition, end, numberOfRows, metaData.rowMetaData, [](Module::RowMetaData& metaData) -> Angle::value_type& {
      return metaData.elevation.rawValueMutable();
    });
  readPosition +=
    readRowMetaDataArray<Angle::value_type>(readPosition, end, numberOfRows, metaData.rowMetaData, [](Module::RowMetaData& metaData) -> Angle::value_type& {
      return metaData.firstBeamAzimuth.rawValueMutable();
    });
  readPosition +=
    readRowMetaDataArray<Angle::value_type>(readPosition, end, numberOfRows, metaData.rowMetaData, [](Module::RowMetaData& metaData) -> Angle::value_type& {
      return metaData.lastBeamAzimuth.rawValueMutable();
    });

  if (version == 4)
  {
    readPosition += sick::compact::CompactParser::readValueUnsafe(readPosition, end, metaData.distanceScalingFactor);
  }
  else
  {
    metaData.distanceScalingFactor = 1.0f;
  }

  // FIXME Potential for optimization: Read all of those variables at once with a single
  // memcpy(&metaData.numberOfBytesOfNextModule, data.data() + readPosition, sizeOfSecondFixedSizePortionOfMetaData)
  readPosition += sick::compact::CompactParser::readValueUnsafe(readPosition, end, metaData.numberOfBytesOfNextModule);
  readPosition += sizeof(std::uint8_t); // availability, not stored in meta data
  readPosition += sick::compact::CompactParser::readValueUnsafe(readPosition, end, metaData.echoContent);
  readPosition += sick::compact::CompactParser::readValueUnsafe(readPosition, end, metaData.beamContent);
  readPosition += sick::compact::CompactParser::readValueUnsafe(readPosition, end, reserved);

  return std::distance(begin, readPosition);
}

auto Parser::readModuleBeamData(
  std::vector<std::uint8_t>::const_iterator const& begin,
  std::vector<std::uint8_t>::const_iterator const& end,
  Module::MetaData const& metaData,
  std::vector<Column>& columns
) -> std::vector<std::uint8_t>::difference_type
{
  std::size_t sizeOfEchoData = 0;
  if ((metaData.echoContent & EchoContent::Distance) != EchoContent::None)
  {
    sizeOfEchoData += kSizeOfBinaryDistance;
  }
  if ((metaData.echoContent & EchoContent::Intensity) != EchoContent::None)
  {
    sizeOfEchoData += kSizeOfBinaryIntensity;
  }

  std::size_t sizeOfBeamData = 0;
  if ((metaData.beamContent & BeamContent::Properties) != BeamContent::None)
  {
    sizeOfBeamData += sizeof(Beam::properties);
  }
  if ((metaData.beamContent & BeamContent::Azimuth) != BeamContent::None)
  {
    sizeOfBeamData += kSizeOfBinaryAzimuth;
  }

  auto const numberOfBeamsInModule = static_cast<std::size_t>(metaData.numberOfColumns) * static_cast<std::size_t>(metaData.numberOfRows);
  auto const sizeOfBeamsData       = static_cast<std::size_t>(numberOfBeamsInModule * (sizeOfBeamData + metaData.numberOfEchoesPerBeam * sizeOfEchoData));

  if (sizeOfBeamsData > static_cast<std::size_t>(std::numeric_limits<std::ptrdiff_t>::max()))
  {
    throw std::invalid_argument("Number of beams is too large, causing overflow.");
  }
  if (std::distance(begin, end) < static_cast<std::ptrdiff_t>(sizeOfBeamsData))
  {
    throw std::invalid_argument("Not enough data to read the beams.");
  }

  auto readPosition = begin;
  columns.resize(metaData.numberOfColumns);
  for (auto& column : columns)
  {
    column.resize(metaData.numberOfRows);
    for (auto& beam : column)
    {
      beam.echoes.resize(metaData.numberOfEchoesPerBeam);
      for (auto& echo : beam.echoes)
      {
        if ((metaData.echoContent & EchoContent::Distance) != EchoContent::None)
        {
          // echoDistance is not necessarily given in millimeters.
          // It needs to be scaled by metaData.distanceScalingFactor to obtain the measured distance in millimeters.
          std::uint16_t echoDistanceRaw = 0;
          readPosition += sick::compact::CompactParser::readValueUnsafe(readPosition, end, echoDistanceRaw);
          echo.distance = Distance::fromMillimeters(static_cast<float>(echoDistanceRaw) * metaData.distanceScalingFactor);
        }
        if ((metaData.echoContent & EchoContent::Intensity) != EchoContent::None)
        {
          std::uint16_t intensity = 0;
          readPosition += sick::compact::CompactParser::readValueUnsafe(readPosition, end, intensity);
          echo.intensity = static_cast<float>(intensity) / kIntensityScalingFactor;
        }
      }
      if ((metaData.beamContent & BeamContent::Properties) != BeamContent::None)
      {
        beam.properties = 0;
        readPosition += sick::compact::CompactParser::readValueUnsafe(readPosition, end, beam.properties);
      }
      if ((metaData.beamContent & BeamContent::Azimuth) != BeamContent::None)
      {
        std::uint16_t angleUint16 = 0;
        readPosition += sick::compact::CompactParser::readValueUnsafe(readPosition, end, angleUint16);

        // See SICK Compact format description (document number 8028132 on www.sick.com):
        // angleUint = angleRad * 5215 + 16384
        // NOLINTNEXTLINE(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers): see documentation
        beam.azimuth = Angle::fromRadians((static_cast<float>(angleUint16) - 16384.0f) / 5215.0f);
      }
    }
  }
  return std::distance(begin, readPosition);
}

auto Parser::readModule(
  std::vector<std::uint8_t>::const_iterator const& begin,
  std::vector<std::uint8_t>::const_iterator const& end,
  std::uint32_t version,
  Module& module
) -> std::vector<std::uint8_t>::difference_type
{
  auto readPosition = begin + readModuleMetaData(begin, end, version, module.metaData);
  readPosition += readModuleBeamData(readPosition, end, module.metaData, module.columns);
  return std::distance(begin, readPosition);
}

auto Parser::validateAndParse(
  std::vector<std::uint8_t>::const_iterator const& begin,
  std::vector<std::uint8_t>::const_iterator const& end,
  bool validateChecksum
) -> ScanData
{
  LOG_FAST_LOOP_INFO("ScanDataParser") << "Validating and parsing " << std::distance(begin, end) << " bytes of scan data.";
  Header header;
  auto readPosition = begin + sick::compact::CompactParser::readValue(begin, end, header);
  validateHeader(header);

  std::vector<Module> modules;

  std::uint32_t numberOfBytesOfNextModule = header.numberOfBytesOfFirstModule;
  while (numberOfBytesOfNextModule > 0)
  {
    Module module;
    readPosition += readModule(readPosition, end, header.telegramVersion, module);
    modules.push_back(module);
    numberOfBytesOfNextModule = module.metaData.numberOfBytesOfNextModule;
  }

  // read checksum
  std::uint32_t receivedChecksum = 0;
  readPosition += sick::compact::CompactParser::readValue(readPosition, end, receivedChecksum);

  // Verify checksum
  std::uint32_t const computedChecksum = sick::compact::crc32(begin, readPosition - 4);
  if (validateChecksum && receivedChecksum != computedChecksum)
  {
    throw std::invalid_argument("Checksum verification failed");
  }

  return {header, modules, receivedChecksum};
}

auto Parser::getSize(std::vector<std::uint8_t>::const_iterator const& begin, std::vector<std::uint8_t>::const_iterator const& end) const
  -> std::optional<std::size_t>
{
  if (std::distance(begin, end) < sizeof(Header))
  {
    return std::nullopt;
  }

  Header header;
  auto readPosition = readValue(begin, end, header);
  validateHeader(header);

  std::uint32_t numberOfBytesOfCurrentModule = header.numberOfBytesOfFirstModule;

  while (numberOfBytesOfCurrentModule > 0)
  {
    LOG_FAST_LOOP_INFO("ScanDataParser") << "Position " << readPosition << ": Next module size: " << numberOfBytesOfCurrentModule;

    if (std::distance(begin, end) < readPosition)
    {
      return std::nullopt;
    }

    auto numberOfBytesOfNextModule = getNumberOfBytesOfNextModule(begin + readPosition, end, header.telegramVersion);
    if (!numberOfBytesOfNextModule.has_value())
    {
      return std::nullopt;
    }

    readPosition += numberOfBytesOfCurrentModule;
    numberOfBytesOfCurrentModule = *numberOfBytesOfNextModule;
  }

  return readPosition + sizeof(ScanData::checksum);
}

auto Parser::getNumberOfBytesOfNextModule(
  std::vector<std::uint8_t>::const_iterator const& begin,
  std::vector<std::uint8_t>::const_iterator const& end,
  std::uint32_t version
) -> std::optional<std::uint32_t>
{
  if (std::distance(begin, end) < kNumberOfRowsOffset + sizeof(Module::MetaData::numberOfRows))
  {
    return std::nullopt;
  }
  std::uint32_t numberOfRows = 0;
  sick::compact::CompactParser::readValueUnsafe(begin + kNumberOfRowsOffset, end, numberOfRows);

  auto nextModuleSizeOffset = static_cast<std::vector<std::uint8_t>::difference_type>(
    sizeof(Module::MetaData::segmentIndex) + sizeof(Module::MetaData::frameSequenceNumber) + sizeof(Module::MetaData::senderSerialNumber) +
    sizeof(Module::MetaData::numberOfRows) + sizeof(Module::MetaData::numberOfColumns) + sizeof(Module::MetaData::numberOfEchoesPerBeam) +
    numberOfRows * kModuleMetaDataSizePerRow
  );
  if (version == 4)
  {
    nextModuleSizeOffset += sizeof(Module::MetaData::distanceScalingFactor); // Only available in version 4
  }
  if (nextModuleSizeOffset > std::numeric_limits<std::vector<std::uint8_t>::difference_type>::max())
  {
    throw std::invalid_argument("Next module size is too large, causing overflow.");
  }
  if (std::distance(begin, end) < nextModuleSizeOffset + sizeof(Module::MetaData::numberOfBytesOfNextModule))
  {
    return std::nullopt;
  }

  std::uint32_t numberOfBytesOfNextModule = 0;
  sick::compact::CompactParser::readValueUnsafe(begin + nextModuleSizeOffset, end, numberOfBytesOfNextModule);
  return numberOfBytesOfNextModule;
}

} // namespace sick::compact::scan_data
