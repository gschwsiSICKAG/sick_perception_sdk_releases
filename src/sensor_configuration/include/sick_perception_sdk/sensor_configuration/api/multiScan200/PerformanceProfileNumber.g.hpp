/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file PerformanceProfileNumber.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
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
 * @brief Read and write the number of the performance profile.
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
 * @brief Read and write the number of the performance profile.

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
