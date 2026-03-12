/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file GetSessionTokenInfo.g.hpp Sensor REST API payload definitions.
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
 * @brief Payloads for endpoint /GetSessionTokenInfo.
*/
struct SDK_EXPORT GetSessionTokenInfo
{

  constexpr static const char* methodName = "GetSessionTokenInfo";
  constexpr static const bool isSopasMethod = true;

/**
 * @brief Post GetSessionTokenInfo.
*/
struct SDK_EXPORT Post
{
struct SDK_EXPORT Request
{
  Request() = default;

  explicit Request(std::string token)
    : _token(std::move(token))
  {}

  std::string _token;
};

struct SDK_EXPORT Response
{
  enum class status
  {
    ValidToken = 0,
    InvalidToken = 1,
  };

  Response() = default;

  explicit Response(status status, std::string userlevel, int timeToLive)
    : _status(status), _userlevel(std::move(userlevel)), _timeToLive(timeToLive)
  {}

  status _status;
  std::string _userlevel;
  int _timeToLive;
};

}; // struct Post

}; // struct GetSessionTokenInfo

} // namespace sick::srt::multiScan200
