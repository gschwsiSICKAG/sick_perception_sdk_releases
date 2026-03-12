/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file DailyOpHours.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /DailyOpHours.
*/
struct SDK_EXPORT DailyOpHours
{

  constexpr static const char* variableName = "DailyOpHours";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief The runtime duration since last power on. Non persistant !.
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  Response() = default;

  explicit Response(float DailyOpHours)
    : _DailyOpHours(DailyOpHours)
  {}

  float _DailyOpHours;
};

}; // struct Get

/**
 * @brief The runtime duration since last power on. Non persistant !.

 This function requires at least user level: Production.
*/
struct SDK_EXPORT Post
{
struct SDK_EXPORT Request
{
  Request() = default;

  explicit Request(float DailyOpHours)
    : _DailyOpHours(DailyOpHours)
  {}

  float _DailyOpHours;
};

}; // struct Post

}; // struct DailyOpHours

} // namespace sick::srt::multiScan200
