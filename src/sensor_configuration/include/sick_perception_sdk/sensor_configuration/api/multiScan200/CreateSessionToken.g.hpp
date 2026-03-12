/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file CreateSessionToken.g.hpp Sensor REST API payload definitions.
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
 * @brief Payloads for endpoint /CreateSessionToken.
*/
struct SDK_EXPORT CreateSessionToken
{

  constexpr static const char* methodName = "CreateSessionToken";
  constexpr static const bool isSopasMethod = true;

/**
 * @brief Post CreateSessionToken.
*/
struct SDK_EXPORT Post
{
struct SDK_EXPORT Response
{
  Response() = default;

  explicit Response(std::string token, int timeToLive)
    : _token(std::move(token)), _timeToLive(timeToLive)
  {}

  std::string _token;
  int _timeToLive;
};

}; // struct Post

}; // struct CreateSessionToken

} // namespace sick::srt::multiScan200
