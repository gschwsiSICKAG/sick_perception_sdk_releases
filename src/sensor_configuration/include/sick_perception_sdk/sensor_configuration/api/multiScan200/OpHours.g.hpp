/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file OpHours.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /OpHours.
*/
struct SDK_EXPORT OpHours
{

  constexpr static const char* variableName = "OpHours";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief The total number of operating hours during the lifetime of the device. Resolution is a 1/10 hour.
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  Response() = default;

  explicit Response(int OpHours)
    : _OpHours(OpHours)
  {}

  int _OpHours;
};

}; // struct Get

/**
 * @brief The total number of operating hours during the lifetime of the device. Resolution is a 1/10 hour.

 This function requires at least user level: Production.
*/
struct SDK_EXPORT Post
{
struct SDK_EXPORT Request
{
  Request() = default;

  explicit Request(int OpHours)
    : _OpHours(OpHours)
  {}

  int _OpHours;
};

}; // struct Post

}; // struct OpHours

} // namespace sick::srt::multiScan200
