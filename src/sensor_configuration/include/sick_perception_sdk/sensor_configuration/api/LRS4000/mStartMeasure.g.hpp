/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file mStartMeasure.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'LRS4000' version '1.9.0.0R'.
 * Do not edit manually!
 *
 * @note This class represents the payload of a SOPAS method. Do not use in `write_variable()`!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::LRS4000 {

/**
 * @brief Payloads for endpoint /mStartMeasure.
*/
struct SDK_EXPORT mStartMeasure
{

  constexpr static const char* methodName = "mStartMeasure";
  constexpr static const bool isSopasMethod = true;

/**
 * @brief Start motor, measurement and laser.

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

}; // struct mStartMeasure

} // namespace sick::srt::LRS4000
