/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file LEDEnable.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /LEDEnable.
*/
struct SDK_EXPORT LEDEnable
{

  constexpr static const char* variableName = "LEDEnable";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief Enable or disable LEDs.
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  Response() = default;

  explicit Response(bool LEDEnable)
    : _LEDEnable(LEDEnable)
  {}

  bool _LEDEnable;
};

}; // struct Get

/**
 * @brief Enable or disable LEDs.

 This function requires at least user level: Authorized Client.
*/
struct SDK_EXPORT Post
{
struct SDK_EXPORT Request
{
  Request() = default;

  explicit Request(bool LEDEnable)
    : _LEDEnable(LEDEnable)
  {}

  bool _LEDEnable;
};

}; // struct Post

}; // struct LEDEnable

} // namespace sick::srt::multiScan200
