/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file AutoStartMeasure.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /AutoStartMeasure.
*/
struct SDK_EXPORT AutoStartMeasure
{

  constexpr static const char* variableName = "AutoStartMeasure";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief Start measurement after boot-up automatically.
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  Response() = default;

  explicit Response(bool AutoStartMeasure)
    : _AutoStartMeasure(AutoStartMeasure)
  {}

  bool _AutoStartMeasure;
};

}; // struct Get

/**
 * @brief Start measurement after boot-up automatically.
*/
struct SDK_EXPORT Post
{
struct SDK_EXPORT Request
{
  Request() = default;

  explicit Request(bool AutoStartMeasure)
    : _AutoStartMeasure(AutoStartMeasure)
  {}

  bool _AutoStartMeasure;
};

}; // struct Post

}; // struct AutoStartMeasure

} // namespace sick::srt::multiScan200
