/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file horizontalAngleRangeFilter.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>
#include <sick_perception_sdk/sensor_configuration/api/NumericRange.hpp>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /horizontalAngleRangeFilter.
*/
struct SDK_EXPORT horizontalAngleRangeFilter
{

  constexpr static const char* variableName = "horizontalAngleRangeFilter";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief Restriction of the streaming data output to a specified horizontal field of view. If the blind spot of the sensors field of view lies within the configured range (thetaStart, thetaStop) the device will raise a parameterization error.
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  Response() = default;

  explicit Response(bool enable, NumericRange<-1800000, 1800000, -900000> thetaStart, NumericRange<-1800000, 1800000, 900000> thetaStop, NumericRange<1, 50, 1> thetaIndexIncrement)
    : _enable(enable), _thetaStart(std::move(thetaStart)), _thetaStop(std::move(thetaStop)), _thetaIndexIncrement(std::move(thetaIndexIncrement))
  {}

  bool _enable;
  NumericRange<-1800000, 1800000, -900000> _thetaStart;
  NumericRange<-1800000, 1800000, 900000> _thetaStop;
  NumericRange<1, 50, 1> _thetaIndexIncrement;
};

}; // struct Get

/**
 * @brief Restriction of the streaming data output to a specified horizontal field of view. If the blind spot of the sensors field of view lies within the configured range (thetaStart, thetaStop) the device will raise a parameterization error.

 This function requires at least user level: Authorized Client.
*/
struct SDK_EXPORT Post
{
struct SDK_EXPORT Request
{
  Request() = default;

  explicit Request(bool enable, NumericRange<-1800000, 1800000, -900000> thetaStart, NumericRange<-1800000, 1800000, 900000> thetaStop, NumericRange<1, 50, 1> thetaIndexIncrement)
    : _enable(enable), _thetaStart(std::move(thetaStart)), _thetaStop(std::move(thetaStop)), _thetaIndexIncrement(std::move(thetaIndexIncrement))
  {}

  bool _enable;
  NumericRange<-1800000, 1800000, -900000> _thetaStart;
  NumericRange<-1800000, 1800000, 900000> _thetaStop;
  NumericRange<1, 50, 1> _thetaIndexIncrement;
};

}; // struct Post

}; // struct horizontalAngleRangeFilter

} // namespace sick::srt::multiScan200
