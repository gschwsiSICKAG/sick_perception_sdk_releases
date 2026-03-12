/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file LogInfo.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 *
 * @note This class represents the payload of a SOPAS method. Do not use in `write_variable()`!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /LogInfo.
*/
struct SDK_EXPORT LogInfo
{

  constexpr static const char* methodName = "LogInfo";
  constexpr static const bool isSopasMethod = true;

/**
 * @brief Informs about free logging space.

 This function requires at least user level: Service.
*/
struct SDK_EXPORT Post
{
struct SDK_EXPORT Response
{
  Response() = default;

  explicit Response(int Size)
    : _Size(Size)
  {}

  int _Size;
};

}; // struct Post

}; // struct LogInfo

} // namespace sick::srt::multiScan200
