/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

#pragma once

#include <sick_perception_sdk/common/logging/logging.hpp>
#include <sick_perception_sdk/compact_receiver/Exceptions/Timeout.hpp>

#include <chrono>
#include <functional>
#include <optional>
#include <string>
#include <thread>
#include <vector>

namespace sick::compact {

template <typename DataT>
class CompactStream
{
public:
  CompactStream(
    std::size_t receiveBufferSize,
    std::function<void(DataT)> onNewData,
    std::function<void(std::exception)> onError,
    std::chrono::milliseconds firstDataTimeout = std::chrono::milliseconds(0),
    std::chrono::milliseconds newDataTimeout   = std::chrono::milliseconds(0),
    std::string streamName                     = "CompactStream"
  )
    : m_onNewData(std::move(onNewData))
    , m_onError(std::move(onError))
    , m_receiveBuffer(receiveBufferSize)
    , m_receiveThread(std::thread())
    , m_runReceiveLoop(false)
    , m_firstDataTimeout(firstDataTimeout)
    , m_newDataTimeout(newDataTimeout)
    , m_streamName(std::move(streamName))
  { }

  void start()
  {
    m_startTime = std::chrono::steady_clock::now();

    connectToSource();

    m_runReceiveLoop = true;
    m_receiveThread  = std::thread([this]() {
      LOG_INFO(m_streamName) << "Starting receive loop.";

      while (m_runReceiveLoop)
      {
        try
        {
          receive();
        }
        catch (std::exception const& e)
        {
          LOG_WARNING(m_streamName) << "Exception in receive loop: " << e.what();
          m_onError(e);
        }
      }
    });
  }

  void stop()
  {
    LOG_INFO(m_streamName) << "Stopping receive loop.";
    m_runReceiveLoop = false;
    m_receiveThread.join();
  }

  ~CompactStream()
  {
    if (m_runReceiveLoop)
    {
      stop();
    }
  }

protected:
  virtual void receive() = 0;
  virtual void connectToSource() {};

  void onNoDataReceived()
  {
    if (m_lastReceiveTime && m_newDataTimeout.count() > 0)
    {
      auto const now                  = std::chrono::steady_clock::now();
      auto const timeSinceLastReceive = std::chrono::duration_cast<std::chrono::milliseconds>(now - m_lastReceiveTime.value());
      if (timeSinceLastReceive > m_newDataTimeout)
      {
        std::string msg = "No data received for more than " + std::to_string(m_newDataTimeout.count()) + " ms since the last data was received.";
        LOG_ERROR(m_streamName) << msg;
        m_onError(Timeout(msg));
      }
      return;
    }

    // Check timeout until first data is received.
    if (!m_lastReceiveTime && m_startTime)
    {
      // We have not received any data yet.
      if (m_firstDataTimeout.count() > 0)
      {
        auto const now            = std::chrono::steady_clock::now();
        auto const timeSinceStart = std::chrono::duration_cast<std::chrono::milliseconds>(now - m_startTime.value());
        if (timeSinceStart > m_firstDataTimeout)
        {
          std::string msg = "No data received for more than " + std::to_string(m_firstDataTimeout.count()) + " ms since stream start.";
          LOG_ERROR(m_streamName) << msg;
          m_onError(Timeout(msg));
        }
      }
      return;
    }
  };

  std::vector<std::uint8_t> m_receiveBuffer;
  std::function<void(DataT)> m_onNewData;
  std::function<void(std::exception)> m_onError;

  std::chrono::milliseconds m_firstDataTimeout;
  std::chrono::milliseconds m_newDataTimeout;
  std::optional<std::chrono::steady_clock::time_point> m_lastReceiveTime;

  std::string m_streamName;

private:
  std::thread m_receiveThread;
  bool m_runReceiveLoop;
  std::optional<std::chrono::steady_clock::time_point> m_startTime;
};

} // namespace sick::compact
