/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file NotifyMode.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 *
 * @note This class represents the payload of a SOPAS method. Do not use in `write_variable()`!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /NotifyMode.
*/
struct SDK_EXPORT NotifyMode
{

  constexpr static const char* methodName = "NotifyMode";
  constexpr static const bool isSopasMethod = true;

/**
 * @brief Decoupling login from sensor mode. This function will be called before and after something is written.
*/
struct SDK_EXPORT Post
{
struct SDK_EXPORT Request
{
  enum class NewMode
  {
    Endwrite = 0,
    Beginwrite = 1,
  };

  Request() = default;

  explicit Request(NewMode NewMode)
    : _NewMode(NewMode)
  {}

  NewMode _NewMode;
};

}; // struct Post

}; // struct NotifyMode

} // namespace sick::srt::multiScan200
