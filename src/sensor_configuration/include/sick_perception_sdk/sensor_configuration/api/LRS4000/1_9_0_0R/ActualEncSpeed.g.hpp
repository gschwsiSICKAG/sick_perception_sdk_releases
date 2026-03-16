/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file ActualEncSpeed.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'LRS4000' version '1.9.0.0R'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::LRS4000::v1_9_0_0R::api::rest {

/**
 * @brief Payloads for endpoint /ActualEncSpeed.
*/
struct SDK_EXPORT ActualEncSpeed
{

  constexpr static const char* variableName = "ActualEncSpeed";
  constexpr static const bool isSopasMethod = false;

  /**
   * @brief Read encoder speed in m/s.
   */
  struct SDK_EXPORT Get
  {
    struct SDK_EXPORT Response
    {
      Response() = default;

      explicit Response(float ActualEncSpeed)
        : _ActualEncSpeed(ActualEncSpeed)
      {}

      float _ActualEncSpeed;
    };

  }; // struct Get

}; // struct ActualEncSpeed

} // namespace sick::LRS4000::v1_9_0_0R::api::rest
