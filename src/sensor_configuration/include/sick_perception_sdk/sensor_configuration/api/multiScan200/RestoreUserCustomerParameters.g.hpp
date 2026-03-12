/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file RestoreUserCustomerParameters.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 *
 * @note This class represents the payload of a SOPAS method. Do not use in `write_variable()`!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /RestoreUserCustomerParameters.
*/
struct SDK_EXPORT RestoreUserCustomerParameters
{

  constexpr static const char* methodName = "RestoreUserCustomerParameters";
  constexpr static const bool isSopasMethod = true;

/**
 * @brief Restorse the user params by copy from user prm to system prm.

 This function requires at least user level: Service.
*/
struct SDK_EXPORT Post
{
struct SDK_EXPORT Response
{
  Response() = default;

  explicit Response(bool Success)
    : _Success(Success)
  {}

  bool _Success;
};

}; // struct Post

}; // struct RestoreUserCustomerParameters

} // namespace sick::srt::multiScan200
