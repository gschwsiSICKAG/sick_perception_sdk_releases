/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file TSCTCSrvAddr.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::multiScan200::v0_9_0::api::rest {

/**
 * @brief Payloads for endpoint /TSCTCSrvAddr.
*/
struct SDK_EXPORT TSCTCSrvAddr
{

  constexpr static const char* variableName = "TSCTCSrvAddr";
  constexpr static const bool isSopasMethod = false;

  /**
   * @brief Returns/sets the IP address of the time server.
   */
  struct SDK_EXPORT Get
  {
    struct SDK_EXPORT Response
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
  struct SDK_EXPORT Post
  {
    struct SDK_EXPORT Request
    {
      Request() = default;

      explicit Request(std::vector<int> TSCTCSrvAddr)
        : _TSCTCSrvAddr(TSCTCSrvAddr)
      {}

      std::vector<int> _TSCTCSrvAddr;
    };

  }; // struct Post

}; // struct TSCTCSrvAddr

} // namespace sick::multiScan200::v0_9_0::api::rest
