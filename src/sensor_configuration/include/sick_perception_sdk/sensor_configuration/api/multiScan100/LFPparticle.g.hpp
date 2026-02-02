/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file LFPparticle.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan100' version '2.4.1'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>
#include <sick_perception_sdk/sensor_configuration/api/NumericRange.hpp>

namespace sick::srt::multiScan100 {

/**
 * @brief Payloads for endpoint /LFPparticle.
*/
struct SDK_EXPORT LFPparticle
{

  constexpr static const char* variableName = "LFPparticle";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief Returns/sets the particle filter settings. Filters out disturbances in the measurement data caused by particles such as dust, snowflakes, or similar. Configure the minimal threshold of the required distance step (mm) between the echo to be filtered and the echoes of surrounding beam angles.
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  Response() = default;

  explicit Response(bool bEnable, NumericRange<20, 5000, 500> uiThreshold)
    : _bEnable(bEnable), _uiThreshold(std::move(uiThreshold))
  {}

  bool _bEnable;
  NumericRange<20, 5000, 500> _uiThreshold;
};

}; // struct Get

/**
 * @brief Returns/sets the particle filter settings. Filters out disturbances in the measurement data caused by particles such as dust, snowflakes, or similar. Configure the minimal threshold of the required distance step (mm) between the echo to be filtered and the echoes of surrounding beam angles.

 This function requires at least user level: Authorized Client.
*/
struct SDK_EXPORT Post
{
struct SDK_EXPORT Request
{
  Request() = default;

  explicit Request(bool bEnable, NumericRange<20, 5000, 500> uiThreshold)
    : _bEnable(bEnable), _uiThreshold(std::move(uiThreshold))
  {}

  bool _bEnable;
  NumericRange<20, 5000, 500> _uiThreshold;
};

}; // struct Post

}; // struct LFPparticle

} // namespace sick::srt::multiScan100
