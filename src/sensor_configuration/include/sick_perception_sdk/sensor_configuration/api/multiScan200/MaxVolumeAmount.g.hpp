/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file MaxVolumeAmount.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /MaxVolumeAmount.
*/
struct SDK_EXPORT MaxVolumeAmount
{

  constexpr static const char* variableName = "MaxVolumeAmount";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief Get MaxVolumeAmount.
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  Response() = default;

  explicit Response(int MaxVolumeAmount)
    : _MaxVolumeAmount(MaxVolumeAmount)
  {}

  int _MaxVolumeAmount;
};

}; // struct Get

}; // struct MaxVolumeAmount

} // namespace sick::srt::multiScan200
