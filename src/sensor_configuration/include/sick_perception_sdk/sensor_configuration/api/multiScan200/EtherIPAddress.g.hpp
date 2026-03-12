/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file EtherIPAddress.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /EtherIPAddress.
*/
struct SDK_EXPORT EtherIPAddress
{

  constexpr static const char* variableName = "EtherIPAddress";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief IP-Address of the Device.
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  Response() = default;

  explicit Response(std::array<int, 4> EtherIPAddress)
    : _EtherIPAddress(EtherIPAddress)
  {}

  std::array<int, 4> _EtherIPAddress;
};

}; // struct Get

/**
 * @brief IP-Address of the Device.

 This function requires at least user level: Authorized Client.
*/
struct SDK_EXPORT Post
{
struct SDK_EXPORT Request
{
  Request() = default;

  explicit Request(std::array<int, 4> EtherIPAddress)
    : _EtherIPAddress(EtherIPAddress)
  {}

  std::array<int, 4> _EtherIPAddress;
};

}; // struct Post

}; // struct EtherIPAddress

} // namespace sick::srt::multiScan200
