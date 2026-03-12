/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file CreateParameterBackupDev.g.hpp Sensor REST API payload definitions.
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
 * @brief Payloads for endpoint /CreateParameterBackupDev.
*/
struct SDK_EXPORT CreateParameterBackupDev
{

  constexpr static const char* methodName = "CreateParameterBackupDev";
  constexpr static const bool isSopasMethod = true;

/**
 * @brief Post CreateParameterBackupDev.

 This function requires at least user level: Developer.
*/
struct SDK_EXPORT Post
{
struct SDK_EXPORT Request
{
  Request() = default;

  explicit Request(std::string Passphrase)
    : _Passphrase(std::move(Passphrase))
  {}

  std::string _Passphrase;
};

struct SDK_EXPORT Response
{
  Response() = default;

  explicit Response(bool Result)
    : _Result(Result)
  {}

  bool _Result;
};

}; // struct Post

}; // struct CreateParameterBackupDev

} // namespace sick::srt::multiScan200
