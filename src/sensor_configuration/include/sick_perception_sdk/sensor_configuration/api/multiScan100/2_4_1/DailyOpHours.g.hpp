/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file DailyOpHours.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan100' version '2.4.1'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::multiScan100::v2_4_1::api::rest {

/**
 * @brief Payloads for endpoint /DailyOpHours.
*/
struct SDK_EXPORT DailyOpHours
{

  constexpr static const char* variableName = "DailyOpHours";
  constexpr static const bool isSopasMethod = false;

  /**
   * @brief Returns the runtime duration since the last power on (non-persistent).
   */
  struct SDK_EXPORT Get
  {
    struct SDK_EXPORT Response
    {
      Response() = default;

      explicit Response(float DailyOpHours)
        : _DailyOpHours(DailyOpHours)
      {}

      float _DailyOpHours;
    };

  }; // struct Get

}; // struct DailyOpHours

} // namespace sick::multiScan100::v2_4_1::api::rest
