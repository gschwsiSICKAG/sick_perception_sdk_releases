/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file LogWrite.g.hpp Sensor REST API payload definitions.
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
 * @brief Payloads for endpoint /LogWrite.
*/
struct SDK_EXPORT LogWrite
{

  constexpr static const char* methodName = "LogWrite";
  constexpr static const bool isSopasMethod = true;

/**
 * @brief Transfer logging data.

 This function requires at least user level: Service.
*/
struct SDK_EXPORT Post
{
struct SDK_EXPORT Request
{
  Request() = default;

  explicit Request(int Handle, std::string LogData)
    : _Handle(Handle), _LogData(std::move(LogData))
  {}

  int _Handle;
  std::string _LogData;
};

struct SDK_EXPORT Response
{
  Response() = default;

  explicit Response(int Result)
    : _Result(Result)
  {}

  int _Result;
};

}; // struct Post

}; // struct LogWrite

} // namespace sick::srt::multiScan200
