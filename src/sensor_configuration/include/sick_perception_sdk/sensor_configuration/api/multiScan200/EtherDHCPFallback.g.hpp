/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file EtherDHCPFallback.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /EtherDHCPFallback.
*/
struct SDK_EXPORT EtherDHCPFallback
{

  constexpr static const char* variableName = "EtherDHCPFallback";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief Fallback if DHCP not successfull.
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  enum class EtherDHCPFallback
  {
    TxUseStaticIp = 0,
    TxRetryDhcp = 1,
  };

  Response() = default;

  explicit Response(EtherDHCPFallback EtherDHCPFallback)
    : _EtherDHCPFallback(EtherDHCPFallback)
  {}

  EtherDHCPFallback _EtherDHCPFallback;
};

}; // struct Get

/**
 * @brief Fallback if DHCP not successfull.

 This function requires at least user level: Authorized Client.
*/
struct SDK_EXPORT Post
{
struct SDK_EXPORT Request
{
  enum class EtherDHCPFallback
  {
    TxUseStaticIp = 0,
    TxRetryDhcp = 1,
  };

  Request() = default;

  explicit Request(EtherDHCPFallback EtherDHCPFallback)
    : _EtherDHCPFallback(EtherDHCPFallback)
  {}

  EtherDHCPFallback _EtherDHCPFallback;
};

}; // struct Post

}; // struct EtherDHCPFallback

} // namespace sick::srt::multiScan200
