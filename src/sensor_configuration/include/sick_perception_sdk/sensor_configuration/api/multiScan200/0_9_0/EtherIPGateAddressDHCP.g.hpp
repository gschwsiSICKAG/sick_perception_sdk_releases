/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file EtherIPGateAddressDHCP.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0'.
 * Do not edit manually!
 */
#pragma once


namespace sick::multiScan200::v0_9_0::api::rest {

/**
 * @brief Payloads for endpoint /EtherIPGateAddressDHCP.
*/
struct EtherIPGateAddressDHCP
{

  constexpr static const char* variableName = "EtherIPGateAddressDHCP";
  constexpr static const bool isSopasMethod = false;

  /**
   * @brief Returns the assigned DHCP default gateway address.
   */
  struct Get
  {
    struct Response
    {
      Response() = default;

      explicit Response(std::array<int, 4> EtherIPGateAddressDHCP)
        : _EtherIPGateAddressDHCP(EtherIPGateAddressDHCP)
      {}

      std::array<int, 4> _EtherIPGateAddressDHCP;
    };

  }; // struct Get

}; // struct EtherIPGateAddressDHCP

} // namespace sick::multiScan200::v0_9_0::api::rest
