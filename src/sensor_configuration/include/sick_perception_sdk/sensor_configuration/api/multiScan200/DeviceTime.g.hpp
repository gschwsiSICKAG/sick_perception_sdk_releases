/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file DeviceTime.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /DeviceTime.
*/
struct SDK_EXPORT DeviceTime
{

  constexpr static const char* variableName = "DeviceTime";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief Timestamp of the device in milliseconds. Must be updated in real time by the device itself.
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  Response() = default;

  explicit Response(int DeviceTime)
    : _DeviceTime(DeviceTime)
  {}

  int _DeviceTime;
};

}; // struct Get

/**
 * @brief Timestamp of the device in milliseconds. Must be updated in real time by the device itself.
*/
struct SDK_EXPORT Post
{
struct SDK_EXPORT Request
{
  Request() = default;

  explicit Request(int DeviceTime)
    : _DeviceTime(DeviceTime)
  {}

  int _DeviceTime;
};

}; // struct Post

}; // struct DeviceTime

} // namespace sick::srt::multiScan200
