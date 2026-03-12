/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file CheckPassword.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 *
 * @note This class represents the payload of a SOPAS method. Do not use in `write_variable()`!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /CheckPassword.
*/
struct SDK_EXPORT CheckPassword
{

  constexpr static const char* methodName = "CheckPassword";
  constexpr static const bool isSopasMethod = true;

/**
 * @brief Post CheckPassword.
*/
struct SDK_EXPORT Post
{
struct SDK_EXPORT Request
{
  Request() = default;

  explicit Request(int siUserLevel, int udiPassword)
    : _siUserLevel(siUserLevel), _udiPassword(udiPassword)
  {}

  int _siUserLevel;
  int _udiPassword;
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

}; // struct CheckPassword

} // namespace sick::srt::multiScan200
