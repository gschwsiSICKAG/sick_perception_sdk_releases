/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file CurrentTempDev.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /CurrentTempDev.
*/
struct SDK_EXPORT CurrentTempDev
{

  constexpr static const char* variableName = "CurrentTempDev";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief Current Temperature of device.
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  Response() = default;

  explicit Response(float CurrentTempDev)
    : _CurrentTempDev(CurrentTempDev)
  {}

  float _CurrentTempDev;
};

}; // struct Get

}; // struct CurrentTempDev

} // namespace sick::srt::multiScan200
