/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file AutoStartMeasure.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan100' version '2.4.1'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::multiScan100 {

/**
 * @brief Payloads for endpoint /AutoStartMeasure.
*/
struct SDK_EXPORT AutoStartMeasure
{

  constexpr static const char* variableName = "AutoStartMeasure";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief Returns/sets the mode for automatic start of measurement after boot-up.
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
 * @brief Returns/sets the mode for automatic start of measurement after boot-up.
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

} // namespace sick::srt::multiScan100
