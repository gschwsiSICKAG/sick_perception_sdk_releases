/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file mStartMeasure.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'picoScan150' version '2.2.1'.
 * Do not edit manually!
 *
 * @note This class represents the payload of a SOPAS method. Do not use in `write_variable()`!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::picoScan150::v2_2_1::api::rest {

/**
 * @brief Payloads for endpoint /mStartMeasure.
*/
struct SDK_EXPORT mStartMeasure
{

  constexpr static const char* methodName = "mStartMeasure";
  constexpr static const bool isSopasMethod = true;

  /**
   * @brief Starts motor and measurement.

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

} // namespace sick::picoScan150::v2_2_1::api::rest
