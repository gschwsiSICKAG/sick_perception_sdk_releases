/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file EtherIPGateAddress.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan100' version '2.4.1'.
 * Do not edit manually!
 */
#pragma once


namespace sick::multiScan100::v2_4_1::api::rest {

/**
 * @brief Payloads for endpoint /EtherIPGateAddress.
*/
struct EtherIPGateAddress
{

  constexpr static const char* variableName = "EtherIPGateAddress";
  constexpr static const bool isSopasMethod = false;

  /**
   * @brief Returns/sets default gateway address.
   */
  struct Get
  {
    struct Response
    {
      Response() = default;

      explicit Response(std::array<int, 4> EtherIPGateAddress)
        : _EtherIPGateAddress(EtherIPGateAddress)
      {}

      std::array<int, 4> _EtherIPGateAddress;
    };

  }; // struct Get

  /**
   * @brief Returns/sets default gateway address.

 This function requires at least user level: Authorized Client.
   */
  struct Post
  {
    struct Request
    {
      Request() = default;

      explicit Request(std::array<int, 4> EtherIPGateAddress)
        : _EtherIPGateAddress(EtherIPGateAddress)
      {}

      std::array<int, 4> _EtherIPGateAddress;
    };

  }; // struct Post

}; // struct EtherIPGateAddress

} // namespace sick::multiScan100::v2_4_1::api::rest
