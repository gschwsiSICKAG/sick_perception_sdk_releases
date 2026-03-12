/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file SCRebootNeedful.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /SCRebootNeedful.
*/
struct SDK_EXPORT SCRebootNeedful
{

  constexpr static const char* variableName = "SCRebootNeedful";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief Signs that ue to special parameter changes a reboot is meaningful.
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  Response() = default;

  explicit Response(int SCRebootNeedful)
    : _SCRebootNeedful(SCRebootNeedful)
  {}

  int _SCRebootNeedful;
};

}; // struct Get

}; // struct SCRebootNeedful

} // namespace sick::srt::multiScan200
