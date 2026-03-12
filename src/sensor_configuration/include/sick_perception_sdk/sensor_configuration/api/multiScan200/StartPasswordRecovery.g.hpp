/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file StartPasswordRecovery.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 *
 * @note This class represents the payload of a SOPAS method. Do not use in `write_variable()`!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /StartPasswordRecovery.
*/
struct SDK_EXPORT StartPasswordRecovery
{

  constexpr static const char* methodName = "StartPasswordRecovery";
  constexpr static const bool isSopasMethod = true;

/**
 * @brief Post StartPasswordRecovery.
*/
struct SDK_EXPORT Post
{
struct SDK_EXPORT Response
{
  enum class result
  {
    Success = 0,
    NotAccepted = 2,
    TimelockActive = 5,
  };

  Response() = default;

  explicit Response(result result, std::array<int, 16> challenge)
    : _result(result), _challenge(challenge)
  {}

  result _result;
  std::array<int, 16> _challenge;
};

}; // struct Post

}; // struct StartPasswordRecovery

} // namespace sick::srt::multiScan200
