/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file dataOutputMode.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::multiScan200::v0_9_0::api::rest {

/**
 * @brief Payloads for endpoint /dataOutputMode.
*/
struct SDK_EXPORT dataOutputMode
{

  constexpr static const char* variableName = "dataOutputMode";
  constexpr static const bool isSopasMethod = false;

  /**
   * @brief Returns/sets the data output mode (e.g. Compact format) or disables scan data transmission.
   */
  struct SDK_EXPORT Get
  {
    struct SDK_EXPORT Response
    {
      enum class dataOutputMode
      {
        Disabled = 0,
        TcpCompact = 1,
        NativeRos2 = 3,
      };

      Response() = default;

      explicit Response(dataOutputMode dataOutputMode)
        : _dataOutputMode(dataOutputMode)
      {}

      dataOutputMode _dataOutputMode;
    };

  }; // struct Get

  /**
   * @brief Returns/sets the data output mode (e.g. Compact format) or disables scan data transmission.

 This function requires at least user level: Authorized Client.
   */
  struct SDK_EXPORT Post
  {
    struct SDK_EXPORT Request
    {
      enum class dataOutputMode
      {
        Disabled = 0,
        TcpCompact = 1,
        NativeRos2 = 3,
      };

      Request() = default;

      explicit Request(dataOutputMode dataOutputMode)
        : _dataOutputMode(dataOutputMode)
      {}

      dataOutputMode _dataOutputMode;
    };

  }; // struct Post

}; // struct dataOutputMode

} // namespace sick::multiScan200::v0_9_0::api::rest
