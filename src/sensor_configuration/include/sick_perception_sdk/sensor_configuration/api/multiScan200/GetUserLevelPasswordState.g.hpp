/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file GetUserLevelPasswordState.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 *
 * @note This class represents the payload of a SOPAS method. Do not use in `write_variable()`!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>
#include <string>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /GetUserLevelPasswordState.
*/
struct SDK_EXPORT GetUserLevelPasswordState
{

  constexpr static const char* methodName = "GetUserLevelPasswordState";
  constexpr static const bool isSopasMethod = true;

/**
 * @brief Post GetUserLevelPasswordState.

 This function requires at least user level: Maintenance.
*/
struct SDK_EXPORT Post
{
struct SDK_EXPORT Request
{
  Request() = default;

  explicit Request(std::string userLevel)
    : _userLevel(std::move(userLevel))
  {}

  std::string _userLevel;
};

struct SDK_EXPORT Response
{
  enum class state
  {
    PasswordChanged = 0,
    PasswordIsDefault = 1,
    PasswordIsDefaultReported = 2,
    PasswordStateUndefined = 3,
  };

  Response() = default;

  explicit Response(state state)
    : _state(state)
  {}

  state _state;
};

}; // struct Post

}; // struct GetUserLevelPasswordState

} // namespace sick::srt::multiScan200
