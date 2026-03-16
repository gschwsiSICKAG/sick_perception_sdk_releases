/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file EtherIPGateAddress.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::multiScan200::v0_9_0::api::rest {

/**
 * @brief Payloads for endpoint /EtherIPGateAddress.
*/
struct SDK_EXPORT EtherIPGateAddress
{

  constexpr static const char* variableName = "EtherIPGateAddress";
  constexpr static const bool isSopasMethod = false;

  /**
   * @brief Returns/sets the default gateway address.
   */
  struct SDK_EXPORT Get
  {
    struct SDK_EXPORT Response
    {
      Response() = default;

      explicit Response(std::array<int, 4> EtherIPGateAddress)
        : _EtherIPGateAddress(EtherIPGateAddress)
      {}

      std::array<int, 4> _EtherIPGateAddress;
    };

  }; // struct Get

  /**
   * @brief Returns/sets the default gateway address.

 This function requires at least user level: Authorized Client.
   */
  struct SDK_EXPORT Post
  {
    struct SDK_EXPORT Request
    {
      Request() = default;

      explicit Request(std::array<int, 4> EtherIPGateAddress)
        : _EtherIPGateAddress(EtherIPGateAddress)
      {}

      std::array<int, 4> _EtherIPGateAddress;
    };

  }; // struct Post

}; // struct EtherIPGateAddress

} // namespace sick::multiScan200::v0_9_0::api::rest
