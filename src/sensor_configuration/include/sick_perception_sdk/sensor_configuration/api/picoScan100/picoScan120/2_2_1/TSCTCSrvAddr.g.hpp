/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file TSCTCSrvAddr.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'picoScan120' version '2.2.1'.
 * Do not edit manually!
 */
#pragma once


namespace sick::picoScan120::v2_2_1::api::rest {

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

      explicit Response(std::vector<int> TSCTCSrvAddr)
        : _TSCTCSrvAddr(TSCTCSrvAddr)
      {}

      std::vector<int> _TSCTCSrvAddr;
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

      explicit Request(std::vector<int> TSCTCSrvAddr)
        : _TSCTCSrvAddr(TSCTCSrvAddr)
      {}

      std::vector<int> _TSCTCSrvAddr;
    };

  }; // struct Post

}; // struct TSCTCSrvAddr

} // namespace sick::picoScan120::v2_2_1::api::rest
