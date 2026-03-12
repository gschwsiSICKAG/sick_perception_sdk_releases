/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file bloomingFilter.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /bloomingFilter.
*/
struct SDK_EXPORT bloomingFilter
{

  constexpr static const char* variableName = "bloomingFilter";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief Blooming Filter.
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  enum class strength
  {
    Low = 0,
    Medium = 1,
    Strong = 2,
  };

  Response() = default;

  explicit Response(strength strength, bool enable)
    : _strength(strength), _enable(enable)
  {}

  strength _strength;
  bool _enable;
};

}; // struct Get

/**
 * @brief Blooming Filter.

 This function requires at least user level: Authorized Client.
*/
struct SDK_EXPORT Post
{
struct SDK_EXPORT Request
{
  enum class strength
  {
    Low = 0,
    Medium = 1,
    Strong = 2,
  };

  Request() = default;

  explicit Request(strength strength, bool enable)
    : _strength(strength), _enable(enable)
  {}

  strength _strength;
  bool _enable;
};

}; // struct Post

}; // struct bloomingFilter

} // namespace sick::srt::multiScan200
