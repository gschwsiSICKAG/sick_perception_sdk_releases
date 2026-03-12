/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file EnableColaScan.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /EnableColaScan.
*/
struct SDK_EXPORT EnableColaScan
{

  constexpr static const char* variableName = "EnableColaScan";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief Disables ColaScan / AutoIP. Port 30178 will not be opened. Changing IP address via ColaScan protocol not possible any longer.
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  Response() = default;

  explicit Response(bool EnableColaScan)
    : _EnableColaScan(EnableColaScan)
  {}

  bool _EnableColaScan;
};

}; // struct Get

/**
 * @brief Disables ColaScan / AutoIP. Port 30178 will not be opened. Changing IP address via ColaScan protocol not possible any longer.

 This function requires at least user level: Authorized Client.
*/
struct SDK_EXPORT Post
{
struct SDK_EXPORT Request
{
  Request() = default;

  explicit Request(bool EnableColaScan)
    : _EnableColaScan(EnableColaScan)
  {}

  bool _EnableColaScan;
};

}; // struct Post

}; // struct EnableColaScan

} // namespace sick::srt::multiScan200
