/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file EncSetting.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'LRS4000' version '1.9.0.0R'.
 * Do not edit manually!
 *
 * @note This class represents the payload of a SOPAS method. Do not use in `write_variable()`!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::LRS4000 {

/**
 * @brief Payloads for endpoint /EncSetting.
*/
struct SDK_EXPORT EncSetting
{

  constexpr static const char* methodName = "EncSetting";
  constexpr static const bool isSopasMethod = true;

/**
 * @brief Select the encoder type.

 This function requires at least user level: Authorized Client.
*/
struct SDK_EXPORT Post
{
struct SDK_EXPORT Request
{
  enum class EncSetting
  {
    TxOff = 0,
    TxIncrement1 = 1,
    TxDirPhase12 = 2,
    TxDirLevel12 = 3,
  };

  Request() = default;

  explicit Request(EncSetting EncSetting)
    : _EncSetting(EncSetting)
  {}

  EncSetting _EncSetting;
};

}; // struct Post

}; // struct EncSetting

} // namespace sick::srt::LRS4000
