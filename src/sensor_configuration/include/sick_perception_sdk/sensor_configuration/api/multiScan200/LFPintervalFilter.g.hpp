/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file LFPintervalFilter.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.6.0'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>
#include <sick_perception_sdk/sensor_configuration/api/NumericRange.hpp>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /LFPintervalFilter.
*/
struct SDK_EXPORT LFPintervalFilter
{

  constexpr static const char* variableName = "LFPintervalFilter";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief Returns/sets the interval filter settings. The filter reduces the scan output rate by a given factor.
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  Response() = default;

  explicit Response(bool bEnable, NumericRange<2, 50, 2> uiReductionFactor)
    : _bEnable(bEnable), _uiReductionFactor(std::move(uiReductionFactor))
  {}

  bool _bEnable;
  NumericRange<2, 50, 2> _uiReductionFactor;
};

}; // struct Get

/**
 * @brief Returns/sets the interval filter settings. The filter reduces the scan output rate by a given factor.

 This function requires at least user level: Authorized Client.
*/
struct SDK_EXPORT Post
{
struct SDK_EXPORT Request
{
  Request() = default;

  explicit Request(bool bEnable, NumericRange<2, 50, 2> uiReductionFactor)
    : _bEnable(bEnable), _uiReductionFactor(std::move(uiReductionFactor))
  {}

  bool _bEnable;
  NumericRange<2, 50, 2> _uiReductionFactor;
};

}; // struct Post

}; // struct LFPintervalFilter

} // namespace sick::srt::multiScan200
