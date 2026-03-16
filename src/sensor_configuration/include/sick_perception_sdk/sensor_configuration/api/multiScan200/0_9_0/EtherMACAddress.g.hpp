/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file EtherMACAddress.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::multiScan200::v0_9_0::api::rest {

/**
 * @brief Payloads for endpoint /EtherMACAddress.
*/
struct SDK_EXPORT EtherMACAddress
{

  constexpr static const char* variableName = "EtherMACAddress";
  constexpr static const bool isSopasMethod = false;

  /**
   * @brief Returns the MAC address of the Ethernet interface.
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

}; // struct EtherMACAddress

} // namespace sick::multiScan200::v0_9_0::api::rest
