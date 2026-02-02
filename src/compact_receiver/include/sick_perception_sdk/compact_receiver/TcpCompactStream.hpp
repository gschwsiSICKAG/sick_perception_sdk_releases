/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

#pragma once

#include <sick_perception_sdk/common/IpV4Address.hpp>
#include <sick_perception_sdk/common/logging/logging.hpp>
#include <sick_perception_sdk/compact_receiver/CompactStream.hpp>
#include <sick_perception_sdk/compact_receiver/Exceptions/Timeout.hpp>
#include <sick_perception_sdk/compact_receiver/StreamExtractor.hpp>
#include <sick_perception_sdk/compact_receiver/socket/TcpClientSocket.hpp>

#include <chrono>
#include <optional>

namespace sick::compact {

template <typename ParserT, typename DataT>
class TCPCompactStream : public CompactStream<DataT>
{
public:
  //! \param deviceAddress The IP address of the device to connect to
  //! \param devicePort The port on the device to which to connect
  //! \param receiveBufferSize The size of the buffer used to receive data from the socket
  //! \param onNewData Callback function that is called when new data is received and parsed
  //! \param onError Callback function that is called when an unhandled exception is thrown
  //! \param firstDataTimeout If more time has passed than specified since the stream was started without receiving
  //! any data, an exception is raised. A value of 0 means no timeout.
  //! \param newDataTimeout If more time has passed than specified without receiving any data after the first data was
  //! received, an exception is raised. A value of 0 means no timeout.
  //! \param streamName The name of the stream, used to identify the stream in logs
  TCPCompactStream(
    IpV4Address const& deviceAddress,
    std::uint16_t devicePort,
    std::size_t receiveBufferSize,
    std::function<void(DataT)> onNewData,
    std::function<void(std::exception)> onError,
    std::chrono::milliseconds firstDataTimeout = std::chrono::milliseconds(0),
    std::chrono::milliseconds newDataTimeout   = std::chrono::milliseconds(0),
    std::string streamName                     = "TcpCompactStream"
  )
    : CompactStream<DataT>(receiveBufferSize, std::move(onNewData), std::move(onError), firstDataTimeout, newDataTimeout, streamName)
    , m_socket(std::make_unique<TcpClientSocket>(std::move(deviceAddress), devicePort))
  {
    LOG_INFO(CompactStream<DataT>::m_streamName) << "Setting socket timeout to " << firstDataTimeout.count() << " ms.";
    m_socket->setTimeout(firstDataTimeout);
  }

private:
  void receive() override
  {
    std::size_t numberOfBytesReceived = m_socket->receive(this->m_receiveBuffer);
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
    auto extractedPackages = this->m_streamExtractor.extractTelegrams(this->m_receiveBuffer.cbegin(), this->m_receiveBuffer.cbegin() + numberOfBytesReceived);
    LOG_FAST_LOOP_INFO(CompactStream<DataT>::m_streamName) << "Extracted " << extractedPackages.size() << " packages.";
    for (auto& extractedPackage : extractedPackages)
    {
      // Don't check CRC32 here, because it has already been checked in the StreamExtractor
      bool const checkCrc32 = false;
      this->m_onNewData(ParserT::validateAndParse(extractedPackage.cbegin(), extractedPackage.cend(), checkCrc32));
    }
  }

  void connectToSource() override
  {
    m_socket->openConnection();
    LOG_INFO(CompactStream<DataT>::m_streamName) << "Connected.";
  }

  std::unique_ptr<TcpClientSocket> m_socket;
  StreamExtractor m_streamExtractor;
};

} // namespace sick::compact
