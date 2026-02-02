/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file verticalAngleRangeFilter.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.6.0'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>
#include <sick_perception_sdk/sensor_configuration/api/NumericRange.hpp>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /verticalAngleRangeFilter.
*/
struct SDK_EXPORT verticalAngleRangeFilter
{

  constexpr static const char* variableName = "verticalAngleRangeFilter";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief Returns/sets the vertical angle range filter settings.
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  Response() = default;

  explicit Response(bool enable, NumericRange<-900000, 900000, -250000> outerRoiStartAngle, NumericRange<-900000, 900000, 250000> outerRoiStopAngle, NumericRange<-900000, 900000, -100000> innerRoiStartAngle, NumericRange<-900000, 900000, 100000> innerRoiStopAngle, NumericRange<1, 50, 2> outerRoiIndexIncrement, NumericRange<1, 50, 1> innerRoiIndexIncrement)
    : _enable(enable), _outerRoiStartAngle(std::move(outerRoiStartAngle)), _outerRoiStopAngle(std::move(outerRoiStopAngle)), _innerRoiStartAngle(std::move(innerRoiStartAngle)), _innerRoiStopAngle(std::move(innerRoiStopAngle)), _outerRoiIndexIncrement(std::move(outerRoiIndexIncrement)), _innerRoiIndexIncrement(std::move(innerRoiIndexIncrement))
  {}

  bool _enable;
  NumericRange<-900000, 900000, -250000> _outerRoiStartAngle;
  NumericRange<-900000, 900000, 250000> _outerRoiStopAngle;
  NumericRange<-900000, 900000, -100000> _innerRoiStartAngle;
  NumericRange<-900000, 900000, 100000> _innerRoiStopAngle;
  NumericRange<1, 50, 2> _outerRoiIndexIncrement;
  NumericRange<1, 50, 1> _innerRoiIndexIncrement;
};

}; // struct Get

/**
 * @brief Returns/sets the vertical angle range filter settings.

 This function requires at least user level: Authorized Client.
*/
struct SDK_EXPORT Post
{
struct SDK_EXPORT Request
{
  Request() = default;

  explicit Request(bool enable, NumericRange<-900000, 900000, -250000> outerRoiStartAngle, NumericRange<-900000, 900000, 250000> outerRoiStopAngle, NumericRange<-900000, 900000, -100000> innerRoiStartAngle, NumericRange<-900000, 900000, 100000> innerRoiStopAngle, NumericRange<1, 50, 2> outerRoiIndexIncrement, NumericRange<1, 50, 1> innerRoiIndexIncrement)
    : _enable(enable), _outerRoiStartAngle(std::move(outerRoiStartAngle)), _outerRoiStopAngle(std::move(outerRoiStopAngle)), _innerRoiStartAngle(std::move(innerRoiStartAngle)), _innerRoiStopAngle(std::move(innerRoiStopAngle)), _outerRoiIndexIncrement(std::move(outerRoiIndexIncrement)), _innerRoiIndexIncrement(std::move(innerRoiIndexIncrement))
  {}

  bool _enable;
  NumericRange<-900000, 900000, -250000> _outerRoiStartAngle;
  NumericRange<-900000, 900000, 250000> _outerRoiStopAngle;
  NumericRange<-900000, 900000, -100000> _innerRoiStartAngle;
  NumericRange<-900000, 900000, 100000> _innerRoiStopAngle;
  NumericRange<1, 50, 2> _outerRoiIndexIncrement;
  NumericRange<1, 50, 1> _innerRoiIndexIncrement;
};

}; // struct Post

}; // struct verticalAngleRangeFilter

} // namespace sick::srt::multiScan200
