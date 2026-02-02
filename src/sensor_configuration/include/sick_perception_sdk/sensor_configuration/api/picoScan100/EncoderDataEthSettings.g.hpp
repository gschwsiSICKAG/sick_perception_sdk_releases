/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file EncoderDataEthSettings.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'picoScan100' version '2.2.0'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::picoScan100 {

/**
 * @brief Payloads for endpoint /EncoderDataEthSettings.
*/
struct SDK_EXPORT EncoderDataEthSettings
{

  constexpr static const char* variableName = "EncoderDataEthSettings";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief Returns/sets the destination IP address settings for encoder data streaming (UDP).
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  enum class Protocol
  {
    Udp = 1,
    Tcp = 2,
  };

  Response() = default;

  explicit Response(Protocol Protocol, std::vector<int> IPAddress, int Port)
    : _Protocol(Protocol), _IPAddress(IPAddress), _Port(Port)
  {}

  Protocol _Protocol;
  std::vector<int> _IPAddress;
  int _Port;
};

}; // struct Get

/**
 * @brief Returns/sets the destination IP address settings for encoder data streaming (UDP).

 This function requires at least user level: Authorized Client.
*/
struct SDK_EXPORT Post
{
struct SDK_EXPORT Request
{
  enum class Protocol
  {
    Udp = 1,
    Tcp = 2,
  };

  Request() = default;

  explicit Request(Protocol Protocol, std::vector<int> IPAddress, int Port)
    : _Protocol(Protocol), _IPAddress(IPAddress), _Port(Port)
  {}

  Protocol _Protocol;
  std::vector<int> _IPAddress;
  int _Port;
};

}; // struct Post

}; // struct EncoderDataEthSettings

} // namespace sick::srt::picoScan100
