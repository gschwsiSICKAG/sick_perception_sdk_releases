/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file SetPassword.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'picoScan120' version '2.2.1'.
 * Do not edit manually!
 *
 * @note This class represents the payload of a SOPAS method. Do not use in `write_variable()`!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::picoScan120::v2_2_1::api::rest {

/**
 * @brief Payloads for endpoint /SetPassword.
*/
struct SDK_EXPORT SetPassword
{

  constexpr static const char* methodName = "SetPassword";
  constexpr static const bool isSopasMethod = true;

  /**
   * @brief Sets the password for the CoLa A/B interface only. In this example the password for user level: Service (4) is set to - test - (integer value of the password hash - test -). For more details see  https://github.com/SICKAG/sick_scan_rest_client.
   */
  struct SDK_EXPORT Post
  {
    struct SDK_EXPORT Request
    {
      Request() = default;

      explicit Request(int siUserLevel, int udiNewPassword)
        : _siUserLevel(siUserLevel), _udiNewPassword(udiNewPassword)
      {}

      int _siUserLevel;
      int _udiNewPassword;
    };

    struct SDK_EXPORT Response
    {
      Response() = default;

      explicit Response(bool bSuccess)
        : _bSuccess(bSuccess)
      {}

      bool _bSuccess;
    };

  }; // struct Post

}; // struct SetPassword

} // namespace sick::picoScan120::v2_2_1::api::rest
