/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file horizontalFieldOfViewStartAngle.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>
#include <sick_perception_sdk/sensor_configuration/api/NumericRange.hpp>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /horizontalFieldOfViewStartAngle.
*/
struct SDK_EXPORT horizontalFieldOfViewStartAngle
{

  constexpr static const char* variableName = "horizontalFieldOfViewStartAngle";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief Configure horizontal field of view.
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  Response() = default;

  explicit Response(NumericRange<-1800000, 1790000, -1380000> horizontalFieldOfViewStartAngle)
    : _horizontalFieldOfViewStartAngle(std::move(horizontalFieldOfViewStartAngle))
  {}

  NumericRange<-1800000, 1790000, -1380000> _horizontalFieldOfViewStartAngle;
};

}; // struct Get

/**
 * @brief Configure horizontal field of view.

 This function requires at least user level: Authorized Client.
*/
struct SDK_EXPORT Post
{
struct SDK_EXPORT Request
{
  Request() = default;

  explicit Request(NumericRange<-1800000, 1790000, -1380000> horizontalFieldOfViewStartAngle)
    : _horizontalFieldOfViewStartAngle(std::move(horizontalFieldOfViewStartAngle))
  {}

  NumericRange<-1800000, 1790000, -1380000> _horizontalFieldOfViewStartAngle;
};

}; // struct Post

}; // struct horizontalFieldOfViewStartAngle

} // namespace sick::srt::multiScan200
