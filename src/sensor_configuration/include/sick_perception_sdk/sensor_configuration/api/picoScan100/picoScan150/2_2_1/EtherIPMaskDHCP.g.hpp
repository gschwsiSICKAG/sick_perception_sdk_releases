/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file EtherIPMaskDHCP.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'picoScan150' version '2.2.1'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::picoScan150::v2_2_1::api::rest {

/**
 * @brief Payloads for endpoint /EtherIPMaskDHCP.
*/
struct SDK_EXPORT EtherIPMaskDHCP
{

  constexpr static const char* variableName = "EtherIPMaskDHCP";
  constexpr static const bool isSopasMethod = false;

  /**
   * @brief Returns the assigned DHCP subnet mask.
   */
  struct SDK_EXPORT Get
  {
    struct SDK_EXPORT Response
    {
      Response() = default;

      explicit Response(std::array<int, 4> EtherIPMaskDHCP)
        : _EtherIPMaskDHCP(EtherIPMaskDHCP)
      {}

      std::array<int, 4> _EtherIPMaskDHCP;
    };

  }; // struct Get

}; // struct EtherIPMaskDHCP

} // namespace sick::picoScan150::v2_2_1::api::rest
