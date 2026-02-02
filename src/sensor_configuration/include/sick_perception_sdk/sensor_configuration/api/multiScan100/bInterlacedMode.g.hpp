/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file bInterlacedMode.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan100' version '2.4.1'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::multiScan100 {

/**
 * @brief Payloads for endpoint /bInterlacedMode.
*/
struct SDK_EXPORT bInterlacedMode
{

  constexpr static const char* variableName = "bInterlacedMode";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief Enables the interlaced mode.
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  Response() = default;

  explicit Response(bool bInterlacedMode)
    : _bInterlacedMode(bInterlacedMode)
  {}

  bool _bInterlacedMode;
};

}; // struct Get

/**
 * @brief Enables the interlaced mode.

 This function requires at least user level: Authorized Client.
*/
struct SDK_EXPORT Post
{
struct SDK_EXPORT Request
{
  Request() = default;

  explicit Request(bool bInterlacedMode)
    : _bInterlacedMode(bInterlacedMode)
  {}

  bool _bInterlacedMode;
};

}; // struct Post

}; // struct bInterlacedMode

} // namespace sick::srt::multiScan100
