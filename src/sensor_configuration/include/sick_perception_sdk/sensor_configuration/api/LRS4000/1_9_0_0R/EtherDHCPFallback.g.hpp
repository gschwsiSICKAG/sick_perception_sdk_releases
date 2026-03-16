/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file EtherDHCPFallback.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'LRS4000' version '1.9.0.0R'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::LRS4000::v1_9_0_0R::api::rest {

/**
 * @brief Payloads for endpoint /EtherDHCPFallback.
*/
struct SDK_EXPORT EtherDHCPFallback
{

  constexpr static const char* variableName = "EtherDHCPFallback";
  constexpr static const bool isSopasMethod = false;

  /**
   * @brief Returns/sets the more for the DHCP fallback (retry or static).
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
   * @brief Returns/sets the more for the DHCP fallback (retry or static).

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

} // namespace sick::LRS4000::v1_9_0_0R::api::rest
