/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file GetPasswordRecoveryStatus.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 *
 * @note This class represents the payload of a SOPAS method. Do not use in `write_variable()`!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /GetPasswordRecoveryStatus.
*/
struct SDK_EXPORT GetPasswordRecoveryStatus
{

  constexpr static const char* methodName = "GetPasswordRecoveryStatus";
  constexpr static const bool isSopasMethod = true;

/**
 * @brief Post GetPasswordRecoveryStatus.
*/
struct SDK_EXPORT Post
{
struct SDK_EXPORT Response
{
  enum class status
  {
    RecoveryInactive = 0,
    RecoveryActive = 1,
  };

  Response() = default;

  explicit Response(status status, int remainingLoginAttempts, std::array<int, 16> challenge)
    : _status(status), _remainingLoginAttempts(remainingLoginAttempts), _challenge(challenge)
  {}

  status _status;
  int _remainingLoginAttempts;
  std::array<int, 16> _challenge;
};

}; // struct Post

}; // struct GetPasswordRecoveryStatus

} // namespace sick::srt::multiScan200
