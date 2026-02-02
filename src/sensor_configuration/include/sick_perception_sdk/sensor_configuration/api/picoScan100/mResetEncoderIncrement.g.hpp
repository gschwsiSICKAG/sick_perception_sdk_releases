/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file mResetEncoderIncrement.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'picoScan100' version '2.2.0'.
 * Do not edit manually!
 *
 * @note This class represents the payload of a SOPAS method. Do not use in `write_variable()`!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::picoScan100 {

/**
 * @brief Payloads for endpoint /mResetEncoderIncrement.
*/
struct SDK_EXPORT mResetEncoderIncrement
{

  constexpr static const char* methodName = "mResetEncoderIncrement";
  constexpr static const bool isSopasMethod = true;

/**
 * @brief Resets the encoder tick value.

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

}; // struct mResetEncoderIncrement

} // namespace sick::srt::picoScan100
