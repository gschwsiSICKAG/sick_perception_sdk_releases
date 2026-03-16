/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file EtherAddressingMode.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'picoScan120' version '2.2.1'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::picoScan120::v2_2_1::api::rest {

/**
 * @brief Payloads for endpoint /EtherAddressingMode.
*/
struct SDK_EXPORT EtherAddressingMode
{

  constexpr static const char* variableName = "EtherAddressingMode";
  constexpr static const bool isSopasMethod = false;

  /**
   * @brief Returns/sets the mode for the IP address assignment (static or DHCP).
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
   * @brief Returns/sets the mode for the IP address assignment (static or DHCP).

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

} // namespace sick::picoScan120::v2_2_1::api::rest
