/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

#pragma once

#include <sick_perception_sdk/common/logging/logging.hpp>
#include <sick_perception_sdk/compact_receiver/CompactStream.hpp>
#include <sick_perception_sdk/compact_receiver/Exceptions/Timeout.hpp>
#include <sick_perception_sdk/compact_receiver/socket/ReceiveError.hpp>
#include <sick_perception_sdk/compact_receiver/socket/UdpListeningSocket.hpp>

#include <chrono>
#include <functional>

namespace sick::compact {

template <typename ParserT, typename DataT>
class UdpCompactStream : public CompactStream<DataT>
{
public:
  //! \param receiverPort The port on which to listen for incoming UDP packets. Listens on all interfaces.
  //! \param receiveBufferSize The size of the buffer used to receive data from the socket
  //! \param onNewData Callback function that is called when new data is received and parsed
  //! \param onError Callback function that is called when an unhandled exception is thrown
  //! \param firstDataTimeout If more time has passed than specified since the stream was started without receiving
  //! any data, an exception is raised. A value of 0 means no timeout.
  //! \param newDataTimeout If more time has passed than specified without receiving any data after the first data was
  //! received, an exception is raised. A value of 0 means no timeout.
  //! \param streamName The name of the stream, used to identify the stream in logs
  UdpCompactStream(
    std::uint16_t receiverPort,
    std::size_t receiveBufferSize,
    std::function<void(DataT)> onNewData,
    std::function<void(std::exception)> onError,
    std::chrono::milliseconds firstDataTimeout = std::chrono::milliseconds(0),
    std::chrono::milliseconds newDataTimeout   = std::chrono::milliseconds(0),
    std::string streamName                     = "UdpCompactStream"
  )
    : CompactStream<DataT>(receiveBufferSize, std::move(onNewData), std::move(onError), firstDataTimeout, newDataTimeout, streamName)
    , m_socket(std::make_unique<UdpListeningSocket>(receiverPort))
  {
    LOG_INFO(CompactStream<DataT>::m_streamName) << "Setting socket timeout to " << firstDataTimeout.count() << " ms.";
    m_socket->setTimeout(firstDataTimeout);
  }

private:
  void receive() override
  {
    std::size_t numberOfBytesReceived = 0;
    try
    {
      numberOfBytesReceived = m_socket->receive(this->m_receiveBuffer);
      LOG_FAST_LOOP_INFO(CompactStream<DataT>::m_streamName) << "Received " << numberOfBytesReceived << " bytes.";
      if (numberOfBytesReceived > 0)
      {
        if (!this->m_lastReceiveTime.has_value())
        {
          LOG_INFO(CompactStream<DataT>::m_streamName) << "First data received, setting socket timeout to " << this->m_newDataTimeout.count() << " ms.";
          m_socket->setTimeout(this->m_newDataTimeout);
        }
        this->m_lastReceiveTime = std::chrono::steady_clock::now();
      }
      else
      {
        this->onNoDataReceived();
        return;
      }
    }
    catch (ReceiveError const& e)
    {
      if (UdpListeningSocket::errorCodeIsTimeoutError(e.getErrorCode()))
      {
        throw Timeout("Timeout while receiving data from socket.");
      }
      else
      {
        throw e;
      }
    }
    this->m_onNewData(ParserT::validateAndParse(this->m_receiveBuffer.cbegin(), this->m_receiveBuffer.cbegin() + numberOfBytesReceived, true));
  }

private:
  std::unique_ptr<UdpListeningSocket> m_socket;
};

} // namespace sick::compact
