/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file FREchoFilter.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::multiScan200::v0_9_0::api::rest {

/**
 * @brief Payloads for endpoint /FREchoFilter.
*/
struct SDK_EXPORT FREchoFilter
{

  constexpr static const char* variableName = "FREchoFilter";
  constexpr static const bool isSopasMethod = false;

  /**
   * @brief Returns/sets the multi-echo filter settings. Depending on the environment the sensor receives several measurement points on the same angular step (multi-echo).
   */
  struct SDK_EXPORT Get
  {
    struct SDK_EXPORT Response
    {
      enum class FREchoFilter
      {
        FirstEcho = 0,
        AllEchos = 1,
        LastEcho = 2,
        StrongestEcho = 3,
        AllEchosStrongestFirst = 4,
      };

      Response() = default;

      explicit Response(FREchoFilter FREchoFilter)
        : _FREchoFilter(FREchoFilter)
      {}

      FREchoFilter _FREchoFilter;
    };

  }; // struct Get

  /**
   * @brief Returns/sets the multi-echo filter settings. Depending on the environment the sensor receives several measurement points on the same angular step (multi-echo).

 This function requires at least user level: Authorized Client.
   */
  struct SDK_EXPORT Post
  {
    struct SDK_EXPORT Request
    {
      enum class FREchoFilter
      {
        FirstEcho = 0,
        AllEchos = 1,
        LastEcho = 2,
        StrongestEcho = 3,
        AllEchosStrongestFirst = 4,
      };

      Request() = default;

      explicit Request(FREchoFilter FREchoFilter)
        : _FREchoFilter(FREchoFilter)
      {}

      FREchoFilter _FREchoFilter;
    };

  }; // struct Post

}; // struct FREchoFilter

} // namespace sick::multiScan200::v0_9_0::api::rest
