/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file CompletePasswordRecovery.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 *
 * @note This class represents the payload of a SOPAS method. Do not use in `write_variable()`!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /CompletePasswordRecovery.
*/
struct SDK_EXPORT CompletePasswordRecovery
{

  constexpr static const char* methodName = "CompletePasswordRecovery";
  constexpr static const bool isSopasMethod = true;

/**
 * @brief Post CompletePasswordRecovery.
*/
struct SDK_EXPORT Post
{
struct SDK_EXPORT Request
{
  Request() = default;

  explicit Request(std::array<int, 32> response)
    : _response(response)
  {}

  std::array<int, 32> _response;
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

}; // struct CompletePasswordRecovery

} // namespace sick::srt::multiScan200
