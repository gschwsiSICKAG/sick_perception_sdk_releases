/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file Start2ndStageLoader.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 *
 * @note This class represents the payload of a SOPAS method. Do not use in `write_variable()`!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /Start2ndStageLoader.
*/
struct SDK_EXPORT Start2ndStageLoader
{

  constexpr static const char* methodName = "Start2ndStageLoader";
  constexpr static const bool isSopasMethod = true;

/**
 * @brief Method starts the second-stage loader and publishes for which processor the following the following data are intended.

 This function requires at least user level: Service.
*/
struct SDK_EXPORT Post
{
struct SDK_EXPORT Request
{
  Request() = default;

  explicit Request(int Parameter)
    : _Parameter(Parameter)
  {}

  int _Parameter;
};

struct SDK_EXPORT Response
{
  Response() = default;

  explicit Response(int Handle)
    : _Handle(Handle)
  {}

  int _Handle;
};

}; // struct Post

}; // struct Start2ndStageLoader

} // namespace sick::srt::multiScan200
