/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file ScanDataEthSettings.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan100' version '2.4.1'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::multiScan100 {

/**
 * @brief Payloads for endpoint /ScanDataEthSettings.
*/
struct SDK_EXPORT ScanDataEthSettings
{

  constexpr static const char* variableName = "ScanDataEthSettings";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief Returns/sets the destination IP address settings for measurement data streaming (UDP).
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
 * @brief Returns/sets the destination IP address settings for measurement data streaming (UDP).

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

}; // struct ScanDataEthSettings

} // namespace sick::srt::multiScan100
