/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file PerformanceProfileNumber.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.6.0'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /PerformanceProfileNumber.
*/
struct SDK_EXPORT PerformanceProfileNumber
{

  constexpr static const char* variableName = "PerformanceProfileNumber";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief Returns/sets the scan configuration (scanning frequency and angular resolution).
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  enum class PerformanceProfileNumber
  {
    Allrounder = 0,
    Sharpness1Vertical = 11,
    Sharpness1Horizontal = 12,
    Sharpness2 = 13,
    MaxTemp1 = 21,
    MaxTemp2 = 22,
  };

  Response() = default;

  explicit Response(PerformanceProfileNumber PerformanceProfileNumber)
    : _PerformanceProfileNumber(PerformanceProfileNumber)
  {}

  PerformanceProfileNumber _PerformanceProfileNumber;
};

}; // struct Get

/**
 * @brief Returns/sets the scan configuration (scanning frequency and angular resolution).

 This function requires at least user level: Authorized Client.
*/
struct SDK_EXPORT Post
{
struct SDK_EXPORT Request
{
  enum class PerformanceProfileNumber
  {
    Allrounder = 0,
    Sharpness1Vertical = 11,
    Sharpness1Horizontal = 12,
    Sharpness2 = 13,
    MaxTemp1 = 21,
    MaxTemp2 = 22,
  };

  Request() = default;

  explicit Request(PerformanceProfileNumber PerformanceProfileNumber)
    : _PerformanceProfileNumber(PerformanceProfileNumber)
  {}

  PerformanceProfileNumber _PerformanceProfileNumber;
};

}; // struct Post

}; // struct PerformanceProfileNumber

} // namespace sick::srt::multiScan200
