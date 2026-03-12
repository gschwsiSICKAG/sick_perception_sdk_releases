/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file PRODSetDeliveryState.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 *
 * @note This class represents the payload of a SOPAS method. Do not use in `write_variable()`!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /PRODSetDeliveryState.
*/
struct SDK_EXPORT PRODSetDeliveryState
{

  constexpr static const char* methodName = "PRODSetDeliveryState";
  constexpr static const bool isSopasMethod = true;

/**
 * @brief Sets/Resets all delivery state variables (e.g. poweron-counter).

 This function requires at least user level: Production.
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

}; // struct PRODSetDeliveryState

} // namespace sick::srt::multiScan200
