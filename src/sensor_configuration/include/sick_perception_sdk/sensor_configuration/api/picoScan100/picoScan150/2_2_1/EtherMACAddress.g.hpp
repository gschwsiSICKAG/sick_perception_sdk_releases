/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file EtherMACAddress.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'picoScan150' version '2.2.1'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::picoScan150::v2_2_1::api::rest {

/**
 * @brief Payloads for endpoint /EtherMACAddress.
*/
struct SDK_EXPORT EtherMACAddress
{

  constexpr static const char* variableName = "EtherMACAddress";
  constexpr static const bool isSopasMethod = false;

  /**
   * @brief Returns the MAC address of the ethernet interface.
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

} // namespace sick::picoScan150::v2_2_1::api::rest
