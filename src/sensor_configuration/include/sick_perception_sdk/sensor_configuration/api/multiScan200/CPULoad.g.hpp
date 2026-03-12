/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file CPULoad.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /CPULoad.
*/
struct SDK_EXPORT CPULoad
{

  constexpr static const char* variableName = "CPULoad";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief Get CPULoad.
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  Response() = default;

  explicit Response(int CPULoad)
    : _CPULoad(CPULoad)
  {}

  int _CPULoad;
};

}; // struct Get

}; // struct CPULoad

} // namespace sick::srt::multiScan200
