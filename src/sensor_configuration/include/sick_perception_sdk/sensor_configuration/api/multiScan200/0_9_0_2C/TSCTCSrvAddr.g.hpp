/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file TSCTCSrvAddr.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0.2C'.
 * Do not edit manually!
 */
#pragma once

#include <cstdint>

namespace sick::multiScan200::v0_9_0_2C::api::rest {

/**
 * @brief Payloads for endpoint /TSCTCSrvAddr.
*/
struct TSCTCSrvAddr
{

  constexpr static const char* variableName = "TSCTCSrvAddr";
  constexpr static const bool isSopasMethod = false;

  /**
   * @brief Returns/sets the IP address of the time server.
   */
  struct Get
  {
    struct Response
    {
      Response() = default;

      explicit Response(std::vector<std::uint8_t> TSCTCSrvAddr)
        : _TSCTCSrvAddr(TSCTCSrvAddr)
      {}

      std::vector<std::uint8_t> _TSCTCSrvAddr;
    };

  }; // struct Get

  /**
   * @brief Returns/sets the IP address of the time server.

 This function requires at least user level: Authorized Client.
   */
  struct Post
  {
    struct Request
    {
      Request() = default;

      explicit Request(std::vector<std::uint8_t> TSCTCSrvAddr)
        : _TSCTCSrvAddr(TSCTCSrvAddr)
      {}

      std::vector<std::uint8_t> _TSCTCSrvAddr;
    };

  }; // struct Post

}; // struct TSCTCSrvAddr

} // namespace sick::multiScan200::v0_9_0_2C::api::rest
