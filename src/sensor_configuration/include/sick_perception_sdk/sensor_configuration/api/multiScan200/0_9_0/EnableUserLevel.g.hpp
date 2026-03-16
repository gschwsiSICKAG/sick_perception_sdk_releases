/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file EnableUserLevel.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0'.
 * Do not edit manually!
 *
 * @note This class represents the payload of a SOPAS method. Do not use in `write_variable()`!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::multiScan200::v0_9_0::api::rest {

/**
 * @brief Payloads for endpoint /EnableUserLevel.
*/
struct SDK_EXPORT EnableUserLevel
{

  constexpr static const char* methodName = "EnableUserLevel";
  constexpr static const bool isSopasMethod = true;

  /**
   * @brief Activates/deactivates a specific user level for the REST interface.

 This function requires at least user level: Service.
   */
  struct SDK_EXPORT Post
  {
    struct SDK_EXPORT Request
    {
      Request() = default;

      explicit Request(int userLevel, bool isEnabled)
        : _userLevel(userLevel), _isEnabled(isEnabled)
      {}

      int _userLevel;
      bool _isEnabled;
    };

    struct SDK_EXPORT Response
    {
      enum class result
      {
        Success = 0,
        NotAccepted = 2,
      };

      Response() = default;

      explicit Response(result result)
        : _result(result)
      {}

      result _result;
    };

  }; // struct Post

}; // struct EnableUserLevel

} // namespace sick::multiScan200::v0_9_0::api::rest
