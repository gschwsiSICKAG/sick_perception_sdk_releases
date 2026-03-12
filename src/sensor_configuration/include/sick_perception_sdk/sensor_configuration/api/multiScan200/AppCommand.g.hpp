/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file AppCommand.g.hpp Sensor REST API payload definitions.
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
 * @brief Payloads for endpoint /AppCommand.
*/
struct SDK_EXPORT AppCommand
{

  constexpr static const char* methodName = "AppCommand";
  constexpr static const bool isSopasMethod = true;

/**
 * @brief Runs a App command.
*/
struct SDK_EXPORT Post
{
struct SDK_EXPORT Request
{
  Request() = default;

  explicit Request(std::string SLCmd)
    : _SLCmd(std::move(SLCmd))
  {}

  std::string _SLCmd;
};

struct SDK_EXPORT Response
{
  Response() = default;

  explicit Response(bool Success)
    : _Success(Success)
  {}

  bool _Success;
};

}; // struct Post

}; // struct AppCommand

} // namespace sick::srt::multiScan200
