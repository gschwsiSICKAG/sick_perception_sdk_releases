/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file EtherIPMask.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0'.
 * Do not edit manually!
 */
#pragma once


namespace sick::multiScan200::v0_9_0::api::rest {

/**
 * @brief Payloads for endpoint /EtherIPMask.
*/
struct EtherIPMask
{

  constexpr static const char* variableName = "EtherIPMask";
  constexpr static const bool isSopasMethod = false;

  /**
   * @brief Returns/sets the subnet mask.
   */
  struct Get
  {
    struct Response
    {
      Response() = default;

      explicit Response(std::array<int, 4> EtherIPMask)
        : _EtherIPMask(EtherIPMask)
      {}

      std::array<int, 4> _EtherIPMask;
    };

  }; // struct Get

  /**
   * @brief Returns/sets the subnet mask.

 This function requires at least user level: Authorized Client.
   */
  struct Post
  {
    struct Request
    {
      Request() = default;

      explicit Request(std::array<int, 4> EtherIPMask)
        : _EtherIPMask(EtherIPMask)
      {}

      std::array<int, 4> _EtherIPMask;
    };

  }; // struct Post

}; // struct EtherIPMask

} // namespace sick::multiScan200::v0_9_0::api::rest
