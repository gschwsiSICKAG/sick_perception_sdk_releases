/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file AppEngineDevSysApps.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /AppEngineDevSysApps.
*/
struct SDK_EXPORT AppEngineDevSysApps
{

  constexpr static const char* variableName = "AppEngineDevSysApps";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief AppEngine shows the system apps and allows development of them. Needs a device reboot to get active.
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  Response() = default;

  explicit Response(bool AppEngineDevSysApps)
    : _AppEngineDevSysApps(AppEngineDevSysApps)
  {}

  bool _AppEngineDevSysApps;
};

}; // struct Get

/**
 * @brief AppEngine shows the system apps and allows development of them. Needs a device reboot to get active.

 This function requires at least user level: Production.
*/
struct SDK_EXPORT Post
{
struct SDK_EXPORT Request
{
  Request() = default;

  explicit Request(bool AppEngineDevSysApps)
    : _AppEngineDevSysApps(AppEngineDevSysApps)
  {}

  bool _AppEngineDevSysApps;
};

}; // struct Post

}; // struct AppEngineDevSysApps

} // namespace sick::srt::multiScan200
