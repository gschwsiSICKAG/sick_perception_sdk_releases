/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file SetAccessMode.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 *
 * @note This class represents the payload of a SOPAS method. Do not use in `write_variable()`!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /SetAccessMode.
*/
struct SDK_EXPORT SetAccessMode
{

  constexpr static const char* methodName = "SetAccessMode";
  constexpr static const bool isSopasMethod = true;

/**
 * @brief Post SetAccessMode.
*/
struct SDK_EXPORT Post
{
struct SDK_EXPORT Request
{
  Request() = default;

  explicit Request(int NewMode, int Password)
    : _NewMode(NewMode), _Password(Password)
  {}

  int _NewMode;
  int _Password;
};

struct SDK_EXPORT Response
{
  Response() = default;

  explicit Response(bool success)
    : _success(success)
  {}

  bool _success;
};

}; // struct Post

}; // struct SetAccessMode

} // namespace sick::srt::multiScan200
