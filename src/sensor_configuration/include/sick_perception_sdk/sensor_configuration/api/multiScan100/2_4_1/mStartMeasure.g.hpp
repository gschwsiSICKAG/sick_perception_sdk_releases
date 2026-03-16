/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file mStartMeasure.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan100' version '2.4.1'.
 * Do not edit manually!
 *
 * @note This class represents the payload of a SOPAS method. Do not use in `write_variable()`!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::multiScan100::v2_4_1::api::rest {

/**
 * @brief Payloads for endpoint /mStartMeasure.
*/
struct SDK_EXPORT mStartMeasure
{

  constexpr static const char* methodName = "mStartMeasure";
  constexpr static const bool isSopasMethod = true;

  /**
   * @brief Start motor and measurement.

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

} // namespace sick::multiScan100::v2_4_1::api::rest
