/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file dataOutputMode.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /dataOutputMode.
*/
struct SDK_EXPORT dataOutputMode
{

  constexpr static const char* variableName = "dataOutputMode";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief Data output mode.
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  enum class dataOutputMode
  {
    Disabled = 0,
    Compact = 1,
    NativeRos2 = 2,
  };

  Response() = default;

  explicit Response(dataOutputMode dataOutputMode)
    : _dataOutputMode(dataOutputMode)
  {}

  dataOutputMode _dataOutputMode;
};

}; // struct Get

/**
 * @brief Data output mode.

 This function requires at least user level: Authorized Client.
*/
struct SDK_EXPORT Post
{
struct SDK_EXPORT Request
{
  enum class dataOutputMode
  {
    Disabled = 0,
    Compact = 1,
    NativeRos2 = 2,
  };

  Request() = default;

  explicit Request(dataOutputMode dataOutputMode)
    : _dataOutputMode(dataOutputMode)
  {}

  dataOutputMode _dataOutputMode;
};

}; // struct Post

}; // struct dataOutputMode

} // namespace sick::srt::multiScan200
