/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file EtherIPAddressDHCP.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan100' version '2.4.1'.
 * Do not edit manually!
 */
#pragma once


namespace sick::multiScan100::v2_4_1::api::rest {

/**
 * @brief Payloads for endpoint /EtherIPAddressDHCP.
*/
struct EtherIPAddressDHCP
{

  constexpr static const char* variableName = "EtherIPAddressDHCP";
  constexpr static const bool isSopasMethod = false;

  /**
   * @brief Returns the assigned DHCP IP address.
   */
  struct Get
  {
    struct Response
    {
      Response() = default;

      explicit Response(std::array<int, 4> EtherIPAddressDHCP)
        : _EtherIPAddressDHCP(EtherIPAddressDHCP)
      {}

      std::array<int, 4> _EtherIPAddressDHCP;
    };

  }; // struct Get

}; // struct EtherIPAddressDHCP

} // namespace sick::multiScan100::v2_4_1::api::rest
