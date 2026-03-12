/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file EtherMACAddress.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /EtherMACAddress.
*/
struct SDK_EXPORT EtherMACAddress
{

  constexpr static const char* variableName = "EtherMACAddress";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief MAC-Address of the Device.
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  Response() = default;

  explicit Response(std::array<int, 6> EtherMACAddress)
    : _EtherMACAddress(EtherMACAddress)
  {}

  std::array<int, 6> _EtherMACAddress;
};

}; // struct Get

/**
 * @brief MAC-Address of the Device.

 This function requires at least user level: Production.
*/
struct SDK_EXPORT Post
{
struct SDK_EXPORT Request
{
  Request() = default;

  explicit Request(std::array<int, 6> EtherMACAddress)
    : _EtherMACAddress(EtherMACAddress)
  {}

  std::array<int, 6> _EtherMACAddress;
};

}; // struct Post

}; // struct EtherMACAddress

} // namespace sick::srt::multiScan200
