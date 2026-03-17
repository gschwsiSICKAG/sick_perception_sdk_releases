/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

#include <sick_perception_sdk/compact_format/telegram_type_6_multiScan200/MultiScan200Parser.hpp>

#include <sick_perception_sdk/common/BitField.hpp>
#include <sick_perception_sdk/common/ByteView.hpp>
#include <sick_perception_sdk/common/SubByteArrayConverter.hpp>
#include <sick_perception_sdk/common/logging/logging.hpp>
#include <sick_perception_sdk/common/quantities/Distance.hpp>
#include <sick_perception_sdk/common/quantities/Duration.hpp>
#include <sick_perception_sdk/compact_format/CompactData.hpp>
#include <sick_perception_sdk/compact_format/CompactParser.hpp>
#include <sick_perception_sdk/compact_format/telegram_type_6_multiScan200/MultiScan200Data.hpp>

#include <array>
#include <cassert>
#include <cstddef>
#include <cstdint>
#include <cstring>
#include <optional>
#include <set>
#include <stdexcept>
#include <utility>
#include <vector>

namespace sick::compact::multiscan200 {

namespace {

std::set<std::uint32_t> const kSupportedTelegramVersions = {1};
constexpr std::size_t kSizeOfIntensityInBits             = 12;
constexpr auto maxIntensityValue                         = static_cast<float>((1 << kSizeOfIntensityInBits) - 1);

auto readSegmentMetaData(ByteView data, SegmentMetaData& metaData) -> std::size_t
{
  if (data.size() < sizeof(SegmentMetaData))
  {
    throw std::invalid_argument("Not enough data to read the module meta data.");
  }

  // Caution! The order of the following readValueUnsafe calls is important and defined by the protocol!

  std::size_t readPosition = 0;
  readPosition += CompactParser::readValueUnsafe(data.subview(readPosition), metaData.frameSequenceNumber);
  readPosition += CompactParser::readValueUnsafe(data.subview(readPosition), metaData.frameTimestamp);
  readPosition += CompactParser::readValueUnsafe(data.subview(readPosition), metaData.segmentIndex);
  readPosition += CompactParser::readValueUnsafe(data.subview(readPosition), metaData.numberOfSegmentsPerFrame);
  readPosition += CompactParser::readValueUnsafe(data.subview(readPosition), metaData.numberOfColumnsInSegment);
  readPosition += CompactParser::readValueUnsafe(data.subview(readPosition), metaData.numberOfColumnsInFrame);
  readPosition += CompactParser::readValueUnsafe(data.subview(readPosition), metaData.numberOfRows);
  readPosition += CompactParser::readValueUnsafe(data.subview(readPosition), metaData.numberOfEchoes);
  readPosition += CompactParser::readValueUnsafe(data.subview(readPosition), metaData.numberOfAmbientLightRows);
  readPosition += CompactParser::readValueUnsafe(data.subview(readPosition), metaData.numberOfInterlaceSteps);
  readPosition += CompactParser::readValueUnsafe(data.subview(readPosition), metaData.currentInterlaceIndex);
  readPosition += CompactParser::readValueUnsafe(data.subview(readPosition), metaData.scanConfigurationIdentifier);
  readPosition += CompactParser::readValueUnsafe(data.subview(readPosition), metaData.distanceScalingFactor);

  std::uint8_t echoDataContent = 0;
  readPosition += CompactParser::readValueUnsafe(data.subview(readPosition), echoDataContent);
  metaData.echoDataContent = BitField<EchoDataContent>(echoDataContent);

  constexpr std::size_t reservedDataSize = 91;
  readPosition += reservedDataSize;

  return readPosition;
}

auto readAmbientLightPixels(ByteView data, SegmentMetaData const& metaData, std::vector<AmbientLightColumn>& columns) -> std::size_t
{
  auto const numberOfColumns     = static_cast<std::size_t>(metaData.numberOfColumnsInSegment);
  auto const numberOfRows        = static_cast<std::size_t>(metaData.numberOfAmbientLightRows);
  auto const numberOfBytesToRead = numberOfColumns * numberOfRows * kSizeOfAmbientLightPixel;
  auto const columnSize          = numberOfRows * kSizeOfAmbientLightPixel;
  if (data.size() < numberOfBytesToRead)
  {
    throw std::invalid_argument("Not enough data to read the pixel data.");
  }

  // FIXME We could pre-allocate if this turns out to be a performance bottleneck
  std::size_t readPosition = 0;
  columns.resize(metaData.numberOfColumnsInSegment);
  for (auto& column : columns)
  {
    column.resize(numberOfRows);
    // NOLINTNEXTLINE(cppcoreguidelines-pro-bounds-pointer-arithmetic) Pointer arithmetic is necessary here for efficient reading of the pixel data.
    std::memcpy(column.data(), data.data() + readPosition, columnSize);
    readPosition += columnSize;
  }
  return readPosition;
}

auto readGeometry(ByteView data, SegmentMetaData const& metaData, Geometry& geometry) -> std::size_t
{
  geometry.elevations.reserve(metaData.numberOfRows);
  geometry.azimuths.reserve(metaData.numberOfColumnsInSegment);
  geometry.relativeTimeStamps.reserve(metaData.numberOfColumnsInSegment);
  geometry.columnProperties.reserve(metaData.numberOfColumnsInSegment);

  // Caution! The order of the readValueUnsafe calls is important and defined by the protocol!
  std::size_t readPosition = 0;
  for (std::size_t rowIndex = 0; rowIndex < metaData.numberOfRows; ++rowIndex)
  {
    Angle elevationAngle;
    readPosition += CompactParser::readValueUnsafe(data.subview(readPosition), elevationAngle.rawValueMutable());
    geometry.elevations.push_back(elevationAngle);
  }

  // Separate loops are necessary because the telegram layout stores all azimuths first, then all relative timestamps, etc.
  for (std::size_t columnIndex = 0; columnIndex < metaData.numberOfColumnsInSegment; ++columnIndex)
  {
    Angle azimuthAngle;
    readPosition += CompactParser::readValueUnsafe(data.subview(readPosition), azimuthAngle.rawValueMutable());
    geometry.azimuths.push_back(azimuthAngle);
  }

  for (std::size_t columnIndex = 0; columnIndex < metaData.numberOfColumnsInSegment; ++columnIndex)
  {
    // Caution! Contrary to most other timestamp related values this is a 32 bit value!
    std::uint32_t columnTimeOffset = 0;
    readPosition += CompactParser::readValueUnsafe(data.subview(readPosition), columnTimeOffset);
    geometry.relativeTimeStamps.push_back(Duration::fromMicroseconds(columnTimeOffset));
  }

  for (std::size_t columnIndex = 0; columnIndex < metaData.numberOfColumnsInSegment; ++columnIndex)
  {
    std::uint16_t columnProperties = 0;
    readPosition += CompactParser::readValueUnsafe(data.subview(readPosition), columnProperties);
    geometry.columnProperties.emplace_back(columnProperties);
  }

  return readPosition;
}

auto readScanData(ByteView data, MultiScan200Data& scanData) -> std::size_t
{
  std::size_t readPosition = 0;

  auto const numberOfEchoes  = static_cast<std::size_t>(scanData.segmentMetaData.numberOfEchoes);
  auto const numberOfRows    = static_cast<std::size_t>(scanData.segmentMetaData.numberOfRows);
  auto const numberOfColumns = static_cast<std::size_t>(scanData.segmentMetaData.numberOfColumnsInSegment);
  auto const numberOfBeams   = static_cast<std::size_t>(numberOfRows * numberOfColumns);
  auto const numberOfSamples = static_cast<std::size_t>(numberOfEchoes * numberOfBeams);

  // Bulk read raw distances and convert
  std::vector<std::uint16_t> rawDistances(numberOfSamples);
  std::memcpy(rawDistances.data(), data.data() + readPosition, numberOfSamples * sizeof(std::uint16_t));
  readPosition += numberOfSamples * sizeof(std::uint16_t);

  scanData.distances.resize(numberOfSamples);
  auto const scalingFactor = scanData.segmentMetaData.distanceScalingFactor;
  for (std::size_t i = 0; i < numberOfSamples; ++i)
  {
    scanData.distances[i] = Distance::fromMillimeters(static_cast<Distance::value_type>(rawDistances[i]) * scalingFactor);
  }

  // Intensities
  if ((scanData.segmentMetaData.echoDataContent.isSet(EchoDataContent::Intensity)))
  {
    std::vector<std::uint16_t> rawIntensities;
    readPosition += convertSubByteArray<std::uint16_t, kSizeOfIntensityInBits>(data.subview(readPosition), numberOfSamples, rawIntensities);

    scanData.intensities.resize(numberOfSamples);
    for (std::size_t i = 0; i < numberOfSamples; ++i)
    {
      scanData.intensities[i] = static_cast<float>(rawIntensities[i]) / maxIntensityValue;
    }
  }

  // Pulse widths - bulk read and convert
  if ((scanData.segmentMetaData.echoDataContent.isSet(EchoDataContent::PulseWidth)))
  {
    std::vector<std::uint8_t> rawPulseWidths(numberOfSamples);
    std::memcpy(rawPulseWidths.data(), data.data() + readPosition, numberOfSamples);
    readPosition += numberOfSamples;

    scanData.pulseWidths.resize(numberOfSamples);
    constexpr double pulseWidthScalingFactor = 8.0;
    for (std::size_t i = 0; i < numberOfSamples; ++i)
    {
      scanData.pulseWidths[i] = Duration::fromNanoseconds(static_cast<double>(rawPulseWidths[i]) / pulseWidthScalingFactor);
    }
  }

  // Echo properties - bulk read directly into target
  if ((scanData.segmentMetaData.echoDataContent.isSet(EchoDataContent::Properties)))
  {
    scanData.echoProperties.resize(numberOfSamples);
    std::memcpy(scanData.echoProperties.data(), data.data() + readPosition, numberOfSamples);
    readPosition += numberOfSamples;
  }

  return readPosition;
}

} // namespace

auto Parser::validateAndParse(ByteView data, bool validateChecksum) -> MultiScan200Data
{
  LOG_FAST_LOOP_INFO("MultiScan200Parser") << "Validating and parsing " << data.size() << " bytes of data.";

  MultiScan200Data scanData;

  // Read and parse the telegram header
  std::size_t readPosition = CompactParser::readValue(data, scanData.telegramHeader);
  CompactParser::validateTelegramHeader(scanData.telegramHeader, TelegramType::MultiScan200, kSupportedTelegramVersions);

  // Read and validate the checksum
  if (validateChecksum)
  {
    CompactParser::validateChecksum(scanData.telegramHeader, data);
  }

  // Read and parse the segment meta data
  readPosition += readSegmentMetaData(data.subview(readPosition), scanData.segmentMetaData);

  // Read and parse the ambient light pixels
  readPosition += readAmbientLightPixels(data.subview(readPosition), scanData.segmentMetaData, scanData.ambientLightData);

  // Intermediate step: read the geometry information. This will later be used to fill the beams.
  readPosition += readGeometry(data.subview(readPosition), scanData.segmentMetaData, scanData.geometry);

  // Read the scan data. The resulting data is quite different from the protocol layout so it needs the
  // geometry information to assemble the beams correctly.
  readScanData(data.subview(readPosition), scanData);

  return scanData;
}

auto Parser::getSize(ByteView data) const -> std::optional<std::size_t>
{
  if (data.size() < sizeof(TelegramHeaderWithSenderSerialNumber))
  {
    return std::nullopt;
  }

  TelegramHeaderWithSenderSerialNumber header;
  readValue(data, header);
  validateTelegramHeader(header, TelegramType::MultiScan200, kSupportedTelegramVersions);

  return sizeof(TelegramHeader) + header.payloadLength + sizeof(std::uint32_t);
}

} // namespace sick::compact::multiscan200
