/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file EtherIPAddressDHCP.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'picoScan120' version '2.2.1'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::picoScan120::v2_2_1::api::rest {

/**
 * @brief Payloads for endpoint /EtherIPAddressDHCP.
*/
struct SDK_EXPORT EtherIPAddressDHCP
{

  constexpr static const char* variableName = "EtherIPAddressDHCP";
  constexpr static const bool isSopasMethod = false;

  /**
   * @brief Returns the assigned DHCP IP address.
   */
  struct SDK_EXPORT Get
  {
    struct SDK_EXPORT Response
    {
      Response() = default;

      explicit Response(std::array<int, 4> EtherIPAddressDHCP)
        : _EtherIPAddressDHCP(EtherIPAddressDHCP)
      {}

      std::array<int, 4> _EtherIPAddressDHCP;
    };

  }; // struct Get

}; // struct EtherIPAddressDHCP

} // namespace sick::picoScan120::v2_2_1::api::rest
