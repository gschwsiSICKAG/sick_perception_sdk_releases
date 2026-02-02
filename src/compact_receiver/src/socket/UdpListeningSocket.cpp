/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

#include <sick_perception_sdk/common/logging/logging.hpp>
#include <sick_perception_sdk/compact_receiver/socket/ConnectionError.hpp>
#include <sick_perception_sdk/compact_receiver/socket/UdpListeningSocket.hpp>

#include <cerrno>
#include <stdexcept>
#include <string>

// NOLINTBEGIN(misc-include-cleaner): socket definitions are platform dependent

namespace sick {

auto UdpListeningSocket::errorCodeIsTimeoutError(int errorCode) -> bool
{
#ifdef _WIN32
  return errorCode == WSAETIMEDOUT;
#else
  return errorCode == EAGAIN || errorCode == EWOULDBLOCK;
#endif
}

UdpListeningSocket::UdpListeningSocket(std::uint16_t port)
{
  LOG_INFO("UdpListeningSocket") << "Creating socket.";
  m_socket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
  if (m_socket == INVALID_SOCKET)
  {
    LOG_ERROR("UdpListeningSocket") << "Creating socket failed";
    cleanup();
    throw std::runtime_error("socket() failed");
  }

  // Prepare the sockaddr_in structure
  struct sockaddr_in server
  { };

  server.sin_family      = AF_INET;
  server.sin_addr.s_addr = INADDR_ANY;
  server.sin_port        = htons(port);

  LOG_INFO("UdpListeningSocket") << "Binding socket to port " << port;
  // NOLINTNEXTLINE(cppcoreguidelines-pro-type-reinterpret-cast)
  if (bind(m_socket, reinterpret_cast<struct sockaddr*>(&server), sizeof(server)) == SOCKET_ERROR)
  {
    int const errorCode        = getErrorCode();
    std::string const errorMsg = "Unable to bind socket to port " + std::to_string(port) + " bind() failed with error " + std::to_string(errorCode) +
                                 ". Make sure that the port is available.";
    LOG_ERROR("UdpListeningSocket") << errorMsg;
    throw sick::ConnectionError(errorCode, errorMsg);
  }
}

UdpListeningSocket::~UdpListeningSocket()
{
  LOG_INFO("UdpListeningSocket") << "Closing UDP socket.";
  closeConnection();
}

} // namespace sick

// NOLINTEND(misc-include-cleaner)
