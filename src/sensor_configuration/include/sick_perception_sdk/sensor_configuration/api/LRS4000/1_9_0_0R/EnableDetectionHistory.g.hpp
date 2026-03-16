/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file EnableDetectionHistory.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'LRS4000' version '1.9.0.0R'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::LRS4000::v1_9_0_0R::api::rest {

/**
 * @brief Payloads for endpoint /EnableDetectionHistory.
*/
struct SDK_EXPORT EnableDetectionHistory
{

  constexpr static const char* variableName = "EnableDetectionHistory";
  constexpr static const bool isSopasMethod = false;

  /**
   * @brief Returns/sets the detection history.
   */
  struct SDK_EXPORT Get
  {
    struct SDK_EXPORT Response
    {
      Response() = default;

      explicit Response(bool EnableDetectionHistory)
        : _EnableDetectionHistory(EnableDetectionHistory)
      {}

      bool _EnableDetectionHistory;
    };

  }; // struct Get

  /**
   * @brief Returns/sets the detection history.

 This function requires at least user level: Authorized Client.
   */
  struct SDK_EXPORT Post
  {
    struct SDK_EXPORT Request
    {
      Request() = default;

      explicit Request(bool EnableDetectionHistory)
        : _EnableDetectionHistory(EnableDetectionHistory)
      {}

      bool _EnableDetectionHistory;
    };

  }; // struct Post

}; // struct EnableDetectionHistory

} // namespace sick::LRS4000::v1_9_0_0R::api::rest
