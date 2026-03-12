/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file ClearErrorMessagesSickService.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 *
 * @note This class represents the payload of a SOPAS method. Do not use in `write_variable()`!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /ClearErrorMessagesSickService.
*/
struct SDK_EXPORT ClearErrorMessagesSickService
{

  constexpr static const char* methodName = "ClearErrorMessagesSickService";
  constexpr static const bool isSopasMethod = true;

/**
 * @brief Clears information, warning and error messages. Fatal errors are not cleard.

 This function requires at least user level: SICK Service.
*/
struct SDK_EXPORT Post
{
struct SDK_EXPORT Response
{
  Response() = default;

  explicit Response(int ulError)
    : _ulError(ulError)
  {}

  int _ulError;
};

}; // struct Post

}; // struct ClearErrorMessagesSickService

} // namespace sick::srt::multiScan200
