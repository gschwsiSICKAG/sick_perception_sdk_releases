/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file SetLastUser.g.hpp Sensor REST API payload definitions.
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
 * @brief Payloads for endpoint /SetLastUser.
*/
struct SDK_EXPORT SetLastUser
{

  constexpr static const char* methodName = "SetLastUser";
  constexpr static const bool isSopasMethod = true;

/**
 * @brief Method defines the last user and last date parameters.

 This function requires at least user level: Authorized Client.
*/
struct SDK_EXPORT Post
{
struct SDK_EXPORT Request
{
  Request() = default;

  explicit Request(std::string LastUser, std::string LastParaDate, std::string LastParaTime)
    : _LastUser(std::move(LastUser)), _LastParaDate(std::move(LastParaDate)), _LastParaTime(std::move(LastParaTime))
  {}

  std::string _LastUser;
  std::string _LastParaDate;
  std::string _LastParaTime;
};

}; // struct Post

}; // struct SetLastUser

} // namespace sick::srt::multiScan200
