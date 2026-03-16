/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file PerformanceProfileNumber.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::multiScan200::v0_9_0::api::rest {

/**
 * @brief Payloads for endpoint /PerformanceProfileNumber.
*/
struct SDK_EXPORT PerformanceProfileNumber
{

  constexpr static const char* variableName = "PerformanceProfileNumber";
  constexpr static const bool isSopasMethod = false;

  /**
   * @brief Returns/sets the scan configuration (scanning frequency and angular resolution).
   */
  struct SDK_EXPORT Get
  {
    struct SDK_EXPORT Response
    {
      enum class PerformanceProfileNumber
      {
        Sc047h094v27620hz1x = 1,
        Sc047h047v27620hz1x = 2,
        Sc047h023v27620hz1x = 3,
        Sc047h047v36010hz1x = 4,
        Sc023h047v27620hz2x = 10,
        Sc023h023v27620hz2x = 11,
        Sc012h023v27620hz4x = 13,
        Sc047h047v19020hz1x = 20,
        Sc047h047v12020hz1x = 21,
      };

      Response() = default;

      explicit Response(PerformanceProfileNumber PerformanceProfileNumber)
        : _PerformanceProfileNumber(PerformanceProfileNumber)
      {}

      PerformanceProfileNumber _PerformanceProfileNumber;
    };

  }; // struct Get

  /**
   * @brief Returns/sets the scan configuration (scanning frequency and angular resolution).

 This function requires at least user level: Authorized Client.
   */
  struct SDK_EXPORT Post
  {
    struct SDK_EXPORT Request
    {
      enum class PerformanceProfileNumber
      {
        Sc047h094v27620hz1x = 1,
        Sc047h047v27620hz1x = 2,
        Sc047h023v27620hz1x = 3,
        Sc047h047v36010hz1x = 4,
        Sc023h047v27620hz2x = 10,
        Sc023h023v27620hz2x = 11,
        Sc012h023v27620hz4x = 13,
        Sc047h047v19020hz1x = 20,
        Sc047h047v12020hz1x = 21,
      };

      Request() = default;

      explicit Request(PerformanceProfileNumber PerformanceProfileNumber)
        : _PerformanceProfileNumber(PerformanceProfileNumber)
      {}

      PerformanceProfileNumber _PerformanceProfileNumber;
    };

  }; // struct Post

}; // struct PerformanceProfileNumber

} // namespace sick::multiScan200::v0_9_0::api::rest
