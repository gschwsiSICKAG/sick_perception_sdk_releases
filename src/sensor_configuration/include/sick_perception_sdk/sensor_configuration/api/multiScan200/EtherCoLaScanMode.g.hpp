/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file EtherCoLaScanMode.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /EtherCoLaScanMode.
*/
struct SDK_EXPORT EtherCoLaScanMode
{

  constexpr static const char* variableName = "EtherCoLaScanMode";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief Selects if CoLa Scan (UDP port 37018) is enabled and if IP address configuration via CoLa Scan is allowed for this Ethernet interface.
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  enum class EtherCoLaScanMode
  {
    Enabled = 0,
    IpConfigDisabled = 1,
    Disabled = 2,
    IpConfigTimeLimit = 3,
  };

  Response() = default;

  explicit Response(EtherCoLaScanMode EtherCoLaScanMode)
    : _EtherCoLaScanMode(EtherCoLaScanMode)
  {}

  EtherCoLaScanMode _EtherCoLaScanMode;
};

}; // struct Get

/**
 * @brief Selects if CoLa Scan (UDP port 37018) is enabled and if IP address configuration via CoLa Scan is allowed for this Ethernet interface.

 This function requires at least user level: Authorized Client.
*/
struct SDK_EXPORT Post
{
struct SDK_EXPORT Request
{
  enum class EtherCoLaScanMode
  {
    Enabled = 0,
    IpConfigDisabled = 1,
    Disabled = 2,
    IpConfigTimeLimit = 3,
  };

  Request() = default;

  explicit Request(EtherCoLaScanMode EtherCoLaScanMode)
    : _EtherCoLaScanMode(EtherCoLaScanMode)
  {}

  EtherCoLaScanMode _EtherCoLaScanMode;
};

}; // struct Post

}; // struct EtherCoLaScanMode

} // namespace sick::srt::multiScan200
