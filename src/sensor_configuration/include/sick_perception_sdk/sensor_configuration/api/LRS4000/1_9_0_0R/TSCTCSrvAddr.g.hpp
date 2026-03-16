/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file TSCTCSrvAddr.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'LRS4000' version '1.9.0.0R'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::LRS4000::v1_9_0_0R::api::rest {

/**
 * @brief Payloads for endpoint /TSCTCSrvAddr.
*/
struct SDK_EXPORT TSCTCSrvAddr
{

  constexpr static const char* variableName = "TSCTCSrvAddr";
  constexpr static const bool isSopasMethod = false;

  /**
   * @brief Returns/sets the NTP time server"s IP address.
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
   * @brief Returns/sets the NTP time server"s IP address.

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

} // namespace sick::LRS4000::v1_9_0_0R::api::rest
