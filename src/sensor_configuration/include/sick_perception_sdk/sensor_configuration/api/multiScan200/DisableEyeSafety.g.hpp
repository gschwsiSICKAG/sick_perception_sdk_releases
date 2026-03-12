/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file DisableEyeSafety.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /DisableEyeSafety.
*/
struct SDK_EXPORT DisableEyeSafety
{

  constexpr static const char* variableName = "DisableEyeSafety";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief ATTENTION: this could disable internal eye safety checks!.
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  Response() = default;

  explicit Response(bool DisableEyeSafety)
    : _DisableEyeSafety(DisableEyeSafety)
  {}

  bool _DisableEyeSafety;
};

}; // struct Get

/**
 * @brief ATTENTION: this could disable internal eye safety checks!.

 This function requires at least user level: Production.
*/
struct SDK_EXPORT Post
{
struct SDK_EXPORT Request
{
  Request() = default;

  explicit Request(bool DisableEyeSafety)
    : _DisableEyeSafety(DisableEyeSafety)
  {}

  bool _DisableEyeSafety;
};

}; // struct Post

}; // struct DisableEyeSafety

} // namespace sick::srt::multiScan200
