/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

#include <sick_perception_sdk/compact_receiver/StreamExtractor.hpp>

#include <sick_perception_sdk/common/logging/logging.hpp>
#include <sick_perception_sdk/compact_receiver/AmbientLightParser.hpp>
#include <sick_perception_sdk/compact_receiver/CompactData.hpp>
#include <sick_perception_sdk/compact_receiver/EncoderParser.hpp>
#include <sick_perception_sdk/compact_receiver/ImuParser.hpp>
#include <sick_perception_sdk/compact_receiver/ScanDataParser.hpp>

#include <algorithm>
#include <array>
#include <cstddef>
#include <cstdint>
#include <cstring> // for std::memcpy
#include <exception>
#include <iterator>
#include <limits>
#include <memory>
#include <optional>
#include <stdexcept>
#include <type_traits>
#include <utility>
#include <vector>

// NOLINTBEGIN(misc-no-recursion): recursion is necessary for resolution of multiple data packages

namespace sick::compact {

constexpr std::array<std::uint8_t, 4> kStxBytes = {0x02, 0x02, 0x02, 0x02};

StreamExtractor::StreamExtractor()
  : m_buffer()
  , m_state(State::WaitingForStx)
  , m_parser(nullptr)
  , m_stxPosition(0)
{ }

inline auto StreamExtractor::getStxPosition() const -> std::vector<std::uint8_t>::const_iterator
{
  return m_buffer.begin() + m_stxPosition;
}

auto StreamExtractor::extractTelegrams(std::vector<std::uint8_t>::const_iterator begin, std::vector<std::uint8_t>::const_iterator end)
  -> std::vector<std::vector<std::uint8_t>>
{
  if (std::distance(begin, end) < 0)
  {
    throw std::invalid_argument("Reversed iterators are not allowed.");
  }

  std::vector<std::vector<std::uint8_t>> result;

  try
  {
    m_buffer.insert(m_buffer.end(), begin, end);

    // Use iteration instead of recursion to avoid stack overflow
    while (true)
    {
      auto const previousState = m_state;

      switch (m_state)
      {
      case State::WaitingForStx:
        findStx();
        break;
      case State::WaitingForTelegramType:
        readTelegramType();
        break;
      case State::WaitingForChecksum:
      {
        auto packet = extractPacket();
        if (packet.has_value())
        {
          result.push_back(std::move(packet.value()));
          continue;
        }
        break;
      }
      default:
        throw std::logic_error("Unknown state in StreamExtractor state machine.");
      }

      // If state changed, we made progress - continue processing the buffer
      if (m_state != previousState)
      {
        continue;
      }

      // State didn't change - we're waiting for more data
      return result;
    }
  }
  catch (std::exception const& ex)
  {
    LOG_FAST_LOOP_WARNING("StreamExtractor") << "Data packet extraction from stream failed: " << ex.what();
    discardStx();
    m_state = State::WaitingForStx;
    return result;
  }
}

void StreamExtractor::discardStx()
{
  if (m_buffer.size() >= kStxBytes.size())
  {
    m_buffer.erase(m_buffer.begin(), m_buffer.begin() + kStxBytes.size());
  }
}

void StreamExtractor::findStx()
{
  LOG_FAST_LOOP_INFO("StreamExtractor") << "Searching for STX.";
  m_state       = State::WaitingForStx;
  m_stxPosition = std::distance(m_buffer.begin(), std::search(m_buffer.begin(), m_buffer.end(), kStxBytes.begin(), kStxBytes.end()));
  if (m_stxPosition == m_buffer.size())
  {
    LOG_FAST_LOOP_INFO("StreamExtractor") << "STX not found. Waiting for more data.";
    return;
  }
  LOG_FAST_LOOP_INFO("StreamExtractor") << "STX found at position " << m_stxPosition << ".";

  m_state = State::WaitingForTelegramType;
}

void StreamExtractor::readTelegramType()
{
  LOG_FAST_LOOP_INFO("StreamExtractor") << "Reading telegram type.";
  m_state                   = State::WaitingForTelegramType;
  TelegramType telegramType = TelegramType::Invalid;
  if (static_cast<std::size_t>(std::distance(getStxPosition(), m_buffer.cend())) < kStxBytes.size() + sizeof(telegramType))
  {
    LOG_FAST_LOOP_INFO("StreamExtractor") << "Not enough data for telegram type. Waiting for more data.";
    return;
  }

  std::memcpy(&telegramType, &*(getStxPosition() + kStxBytes.size()), sizeof(telegramType));

  LOG_FAST_LOOP_INFO("StreamExtractor") << "Telegram type: " << static_cast<std::underlying_type_t<TelegramType>>(telegramType);

  if (telegramType == TelegramType::ScanData)
  {
    m_parser = std::make_unique<sick::compact::scan_data::Parser>();
  }
  else if (telegramType == TelegramType::Imu)
  {
    m_parser = std::make_unique<sick::compact::imu::Parser>();
  }
  else if (telegramType == TelegramType::Encoder)
  {
    m_parser = std::make_unique<sick::compact::encoder::Parser>();
  }
  else if (telegramType == TelegramType::AmbientLight)
  {
    m_parser = std::make_unique<sick::compact::ambient_light::Parser>();
  }
  else
  {
    LOG_FAST_LOOP_WARNING("StreamExtractor") << "Unsupported telegram type. Discarding STX.";
    discardStx();
    m_state = State::WaitingForStx;
    return;
  }

  m_state = State::WaitingForChecksum;
}

auto StreamExtractor::extractPacket() -> std::optional<std::vector<std::uint8_t>>
{
  LOG_FAST_LOOP_INFO("StreamExtractor") << "Validating and extracting packet.";
  m_state                         = State::WaitingForChecksum;
  std::optional<std::size_t> size = m_parser->getSize(getStxPosition(), m_buffer.cend());
  if (!size.has_value())
  {
    LOG_FAST_LOOP_INFO("StreamExtractor") << "Not enough data to compute the size of the data package. Waiting for more data.";
    return std::nullopt;
  }

  if (size.value() > static_cast<std::size_t>(std::numeric_limits<std::ptrdiff_t>::max()))
  {
    LOG_FAST_LOOP_WARNING("StreamExtractor") << "Data package size is too large, causing overflow. Discarding STX.";
    discardStx();
    m_state = State::WaitingForStx;
    return std::nullopt;
  }
  if (std::distance(getStxPosition(), m_buffer.cend()) < static_cast<std::ptrdiff_t>(size.value()))
  {
    LOG_FAST_LOOP_INFO("StreamExtractor") << "Not enough data for the whole data package. Waiting for more data.";
    return std::nullopt;
  }

  auto const dataEnd = getStxPosition() + static_cast<std::vector<std::uint8_t>::difference_type>(size.value());

  if (!m_parser->isChecksumValid(getStxPosition(), dataEnd))
  {
    LOG_FAST_LOOP_WARNING("StreamExtractor") << "CRC failed. Not synchronized. Discarding STX.";
    discardStx();
    m_state = State::WaitingForStx;
    return std::nullopt;
  }

  std::vector<std::uint8_t> dataPackage(getStxPosition(), dataEnd);

  m_buffer.erase(m_buffer.begin(), dataEnd);
  m_state = State::WaitingForStx;
  return dataPackage;
}

} // namespace sick::compact

// NOLINTEND(misc-no-recursion)
