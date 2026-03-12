/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file mStopMeasure.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 *
 * @note This class represents the payload of a SOPAS method. Do not use in `write_variable()`!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /mStopMeasure.
*/
struct SDK_EXPORT mStopMeasure
{

  constexpr static const char* methodName = "mStopMeasure";
  constexpr static const bool isSopasMethod = true;

/**
 * @brief Stops the measurement.

 This function requires at least user level: Authorized Client.
*/
struct SDK_EXPORT Post
{
struct SDK_EXPORT Response
{
  enum class ErrorCode
  {
    SopasErrNoErr = 0,
    SopasErrStateChangeNotPermitted = 1,
  };

  Response() = default;

  explicit Response(ErrorCode ErrorCode)
    : _ErrorCode(ErrorCode)
  {}

  ErrorCode _ErrorCode;
};

}; // struct Post

}; // struct mStopMeasure

} // namespace sick::srt::multiScan200
