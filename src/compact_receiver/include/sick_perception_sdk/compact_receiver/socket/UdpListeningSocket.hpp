/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/
#pragma once

#include <sick_perception_sdk/common/export.hpp>
#include <sick_perception_sdk/compact_receiver/socket/Socket.hpp>

#include <chrono>
#include <memory>
#include <string>
#include <vector>

namespace sick {

//! \brief A blocking UDP socket
class SDK_EXPORT UdpListeningSocket : public Socket
{
public:
  static auto errorCodeIsTimeoutError(int errorCode) -> bool;

  //! \brief Create a listening socket at the given port.
  //! \param port The port on which to open the socket.
  explicit UdpListeningSocket(std::uint16_t port);
  ~UdpListeningSocket();

  UdpListeningSocket(UdpListeningSocket const&)                    = delete;
  auto operator=(UdpListeningSocket const&) -> UdpListeningSocket& = delete;
  UdpListeningSocket(UdpListeningSocket&&)                         = delete;
  auto operator=(UdpListeningSocket&&) -> UdpListeningSocket&      = delete;
};

} // namespace sick
