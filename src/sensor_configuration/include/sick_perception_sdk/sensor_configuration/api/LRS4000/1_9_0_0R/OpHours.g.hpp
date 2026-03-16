/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file OpHours.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'LRS4000' version '1.9.0.0R'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::LRS4000::v1_9_0_0R::api::rest {

/**
 * @brief Payloads for endpoint /OpHours.
*/
struct SDK_EXPORT OpHours
{

  constexpr static const char* variableName = "OpHours";
  constexpr static const bool isSopasMethod = false;

  /**
   * @brief Returns the total number of operating hours during the lifetime of the device. The resolution is a 1/10 hour.
   */
  struct SDK_EXPORT Get
  {
    struct SDK_EXPORT Response
    {
      Response() = default;

      explicit Response(int OpHours)
        : _OpHours(OpHours)
      {}

      int _OpHours;
    };

  }; // struct Get

}; // struct OpHours

} // namespace sick::LRS4000::v1_9_0_0R::api::rest
