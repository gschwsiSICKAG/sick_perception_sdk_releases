/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

#pragma once

#include <sick_perception_sdk/common/ByteView.hpp>
#include <sick_perception_sdk/common/logging/logging.hpp>
#include <sick_perception_sdk/drivers/Exceptions/Timeout.hpp>
#include <sick_perception_sdk/drivers/PacketReceiver.hpp>
#include <sick_perception_sdk/drivers/socket/UdpListeningSocket.hpp>

#include <chrono>
#include <functional>

namespace sick::compact {

template <typename ParserT, typename DataT>
class UdpPacketReceiver : public PacketReceiver<DataT>
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
  UdpPacketReceiver(
    std::uint16_t receiverPort,
    std::size_t receiveBufferSize,
    std::function<void(DataT)> onNewData,
    std::function<void(std::exception_ptr)> onError,
    std::chrono::milliseconds firstDataTimeout = std::chrono::milliseconds(0),
    std::chrono::milliseconds newDataTimeout   = std::chrono::milliseconds(0),
    std::string streamName                     = "UdpPacketReceiver"
  )
    : PacketReceiver<DataT>(
        std::make_unique<UdpListeningSocket>(receiverPort),
        receiveBufferSize,
        std::move(onNewData),
        std::move(onError),
        firstDataTimeout,
        newDataTimeout,
        std::move(streamName)
      )
  { }

private:
  void receive() override
  {
    std::size_t const numberOfBytesReceived = this->receiveWithTimeout();
    this->m_onNewData(ParserT::validateAndParse(ByteView {this->m_receiveBuffer.data(), numberOfBytesReceived}, true));
  }
};

} // namespace sick::compact
