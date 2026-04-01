/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

#pragma once

#include <sick_perception_sdk/common/BitField.hpp>
#include <sick_perception_sdk/common/quantities/Timestamp.hpp>
#include <sick_perception_sdk/compact_format/telegram_type_6_multiScan200/MultiScan200Data.hpp>

#include <cstdint>

namespace sick::test {

/**
 * @brief Test helper to generate MultiScan200Data objects.
 * 
 * This generator creates realistic MultiScan200Data structures for testing purposes.
 * It supports configurable parameters like number of rows, columns, echoes, and segments.
 * 
 * The generator is stateful, i.e. calling next() advances the segment index and frame sequence number,
 * similar to how a real sensor would stream data.
 */
class MultiScan200DataGenerator
{
public:
  MultiScan200DataGenerator();

  auto withNumberOfRows(std::uint16_t value) -> MultiScan200DataGenerator&;
  auto withNumberOfColumnsInSegment(std::uint16_t value) -> MultiScan200DataGenerator&;
  auto withNumberOfColumnsInFrame(std::uint16_t value) -> MultiScan200DataGenerator&;
  auto withNumberOfEchoes(std::uint8_t value) -> MultiScan200DataGenerator&;
  auto withNumberOfSegmentsPerFrame(std::uint16_t value) -> MultiScan200DataGenerator&;
  auto withNumberOfAmbientLightRows(std::uint16_t value) -> MultiScan200DataGenerator&;
  auto withDistanceScalingFactor(float value) -> MultiScan200DataGenerator&;
  auto withEchoDataContent(sick::compact::multiscan200::EchoDataContent value) -> MultiScan200DataGenerator&;

  auto next() -> sick::compact::multiscan200::MultiScan200Data;
  void reset();

private:
  std::uint64_t m_frameSequenceNumber;
  std::uint16_t m_numberOfRows;
  std::uint16_t m_numberOfColumnsInSegment;
  std::uint16_t m_numberOfColumnsInFrame;
  std::uint8_t m_numberOfEchoes;
  std::uint16_t m_numberOfSegmentsPerFrame;
  std::uint16_t m_segmentIndex;
  std::uint16_t m_numberOfAmbientLightRows;
  float m_distanceScalingFactor;
  sick::BitField<sick::compact::multiscan200::EchoDataContent> m_echoDataContent;
};

} // namespace sick::test
