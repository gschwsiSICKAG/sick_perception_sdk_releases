/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file PowerOnCnt.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'LRS4000' version '1.9.0.0R'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::LRS4000 {

/**
 * @brief Payloads for endpoint /PowerOnCnt.
*/
struct SDK_EXPORT PowerOnCnt
{

  constexpr static const char* variableName = "PowerOnCnt";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief Returns the number of power on cycles.
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  Response() = default;

  explicit Response(int PowerOnCnt)
    : _PowerOnCnt(PowerOnCnt)
  {}

  int _PowerOnCnt;
};

}; // struct Get

}; // struct PowerOnCnt

} // namespace sick::srt::LRS4000
