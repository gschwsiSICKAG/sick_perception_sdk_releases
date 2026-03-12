/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file SoftReset.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 *
 * @note This class represents the payload of a SOPAS method. Do not use in `write_variable()`!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /SoftReset.
*/
struct SDK_EXPORT SoftReset
{

  constexpr static const char* methodName = "SoftReset";
  constexpr static const bool isSopasMethod = true;

/**
 * @brief Method executes a software reset on the device.

 This function requires at least user level: Authorized Client.
*/
struct SDK_EXPORT Post
{
struct SDK_EXPORT Request
{
  Request() = default;

  explicit Request(int ProcessorNbr)
    : _ProcessorNbr(ProcessorNbr)
  {}

  int _ProcessorNbr;
};

}; // struct Post

}; // struct SoftReset

} // namespace sick::srt::multiScan200
