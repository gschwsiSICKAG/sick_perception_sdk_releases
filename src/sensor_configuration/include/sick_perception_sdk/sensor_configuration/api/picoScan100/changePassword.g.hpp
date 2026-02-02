/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file changePassword.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'picoScan100' version '2.2.0'.
 * Do not edit manually!
 *
 * @note This class represents the payload of a SOPAS method. Do not use in `write_variable()`!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>
#include <string>

namespace sick::srt::picoScan100 {

/**
 * @brief Payloads for endpoint /changePassword.
*/
struct SDK_EXPORT changePassword
{

  constexpr static const char* methodName = "changePassword";
  constexpr static const bool isSopasMethod = true;

/**
 * @brief Sets the password for the REST interface. For more details see https://github.com/SICKAG/sick_scan_rest_client.
*/
struct SDK_EXPORT Post
{
struct SDK_EXPORT Request
{
  Request() = default;

  explicit Request(std::vector<int> encryptedMessage, std::string userLevel)
    : _encryptedMessage(encryptedMessage), _userLevel(std::move(userLevel))
  {}

  std::vector<int> _encryptedMessage;
  std::string _userLevel;
};

struct SDK_EXPORT Response
{
  enum class result
  {
    Success = 0,
    NotAccepted = 2,
    PwdNotChangable = 4,
    TimelockActive = 5,
  };

  Response() = default;

  explicit Response(result result)
    : _result(result)
  {}

  result _result;
};

}; // struct Post

}; // struct changePassword

} // namespace sick::srt::picoScan100
