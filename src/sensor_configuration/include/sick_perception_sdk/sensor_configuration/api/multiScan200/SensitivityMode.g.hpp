/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file SensitivityMode.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.6.0'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /SensitivityMode.
*/
struct SDK_EXPORT SensitivityMode
{

  constexpr static const char* variableName = "SensitivityMode";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief Returns/sets the sensitivity of the receiver unit.
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  enum class SensitivityMode
  {
    MaximumRobustness = 0,
    Standard = 1,
    MaximumDetectivity = 2,
  };

  Response() = default;

  explicit Response(SensitivityMode SensitivityMode)
    : _SensitivityMode(SensitivityMode)
  {}

  SensitivityMode _SensitivityMode;
};

}; // struct Get

/**
 * @brief Returns/sets the sensitivity of the receiver unit.

 This function requires at least user level: Authorized Client.
*/
struct SDK_EXPORT Post
{
struct SDK_EXPORT Request
{
  enum class SensitivityMode
  {
    MaximumRobustness = 0,
    Standard = 1,
    MaximumDetectivity = 2,
  };

  Request() = default;

  explicit Request(SensitivityMode SensitivityMode)
    : _SensitivityMode(SensitivityMode)
  {}

  SensitivityMode _SensitivityMode;
};

}; // struct Post

}; // struct SensitivityMode

} // namespace sick::srt::multiScan200
