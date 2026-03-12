/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file SetUserLevel.g.hpp Sensor REST API payload definitions.
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
 * @brief Payloads for endpoint /SetUserLevel.
*/
struct SDK_EXPORT SetUserLevel
{

  constexpr static const char* methodName = "SetUserLevel";
  constexpr static const bool isSopasMethod = true;

/**
 * @brief Post SetUserLevel.
*/
struct SDK_EXPORT Post
{
struct SDK_EXPORT Request
{
  Request() = default;

  explicit Request(std::array<int, 32> challengeResponse, std::string userLevel)
    : _challengeResponse(challengeResponse), _userLevel(std::move(userLevel))
  {}

  std::array<int, 32> _challengeResponse;
  std::string _userLevel;
};

struct SDK_EXPORT Response
{
  enum class result
  {
    Success = 0,
    NotAccepted = 2,
    UnknownChallenge = 3,
    TimelockActive = 5,
  };

  Response() = default;

  explicit Response(result result)
    : _result(result)
  {}

  result _result;
};

}; // struct Post

}; // struct SetUserLevel

} // namespace sick::srt::multiScan200
