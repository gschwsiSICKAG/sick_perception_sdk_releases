/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file EtherIPAddress.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0'.
 * Do not edit manually!
 */
#pragma once


namespace sick::multiScan200::v0_9_0::api::rest {

/**
 * @brief Payloads for endpoint /EtherIPAddress.
*/
struct EtherIPAddress
{

  constexpr static const char* variableName = "EtherIPAddress";
  constexpr static const bool isSopasMethod = false;

  /**
   * @brief Returns/sets the used static IP address.
   */
  struct Get
  {
    struct Response
    {
      Response() = default;

      explicit Response(std::array<int, 4> EtherIPAddress)
        : _EtherIPAddress(EtherIPAddress)
      {}

      std::array<int, 4> _EtherIPAddress;
    };

  }; // struct Get

  /**
   * @brief Returns/sets the used static IP address.

 This function requires at least user level: Authorized Client.
   */
  struct Post
  {
    struct Request
    {
      Request() = default;

      explicit Request(std::array<int, 4> EtherIPAddress)
        : _EtherIPAddress(EtherIPAddress)
      {}

      std::array<int, 4> _EtherIPAddress;
    };

  }; // struct Post

}; // struct EtherIPAddress

} // namespace sick::multiScan200::v0_9_0::api::rest
