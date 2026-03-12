/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file EtherAddressingMode.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /EtherAddressingMode.
*/
struct SDK_EXPORT EtherAddressingMode
{

  constexpr static const char* variableName = "EtherAddressingMode";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief Which mode to use for Ethernet address assignement.
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  enum class EtherAddressingMode
  {
    TxIpStatic = 0,
    TxIpDhcp = 1,
  };

  Response() = default;

  explicit Response(EtherAddressingMode EtherAddressingMode)
    : _EtherAddressingMode(EtherAddressingMode)
  {}

  EtherAddressingMode _EtherAddressingMode;
};

}; // struct Get

/**
 * @brief Which mode to use for Ethernet address assignement.

 This function requires at least user level: Authorized Client.
*/
struct SDK_EXPORT Post
{
struct SDK_EXPORT Request
{
  enum class EtherAddressingMode
  {
    TxIpStatic = 0,
    TxIpDhcp = 1,
  };

  Request() = default;

  explicit Request(EtherAddressingMode EtherAddressingMode)
    : _EtherAddressingMode(EtherAddressingMode)
  {}

  EtherAddressingMode _EtherAddressingMode;
};

}; // struct Post

}; // struct EtherAddressingMode

} // namespace sick::srt::multiScan200
