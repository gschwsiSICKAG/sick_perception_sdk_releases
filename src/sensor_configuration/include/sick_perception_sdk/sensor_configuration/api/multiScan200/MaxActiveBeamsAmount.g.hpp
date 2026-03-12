/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file MaxActiveBeamsAmount.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /MaxActiveBeamsAmount.
*/
struct SDK_EXPORT MaxActiveBeamsAmount
{

  constexpr static const char* variableName = "MaxActiveBeamsAmount";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief Get MaxActiveBeamsAmount.
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  Response() = default;

  explicit Response(int MaxActiveBeamsAmount)
    : _MaxActiveBeamsAmount(MaxActiveBeamsAmount)
  {}

  int _MaxActiveBeamsAmount;
};

}; // struct Get

}; // struct MaxActiveBeamsAmount

} // namespace sick::srt::multiScan200
