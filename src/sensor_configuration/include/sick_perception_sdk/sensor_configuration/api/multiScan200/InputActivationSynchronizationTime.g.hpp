/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file InputActivationSynchronizationTime.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /InputActivationSynchronizationTime.
*/
struct SDK_EXPORT InputActivationSynchronizationTime
{

  constexpr static const char* variableName = "InputActivationSynchronizationTime";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief Synchronization time required for activating evaluations via digital ports. All relevant inputs have to stay on the same value until the synchronized states are used for activating the evaluation. Important: A change of this parameter is not applied to existing groups.
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  Response() = default;

  explicit Response(int InputActivationSynchronizationTime)
    : _InputActivationSynchronizationTime(InputActivationSynchronizationTime)
  {}

  int _InputActivationSynchronizationTime;
};

}; // struct Get

/**
 * @brief Synchronization time required for activating evaluations via digital ports. All relevant inputs have to stay on the same value until the synchronized states are used for activating the evaluation. Important: A change of this parameter is not applied to existing groups.

 This function requires at least user level: SICK Service.
*/
struct SDK_EXPORT Post
{
struct SDK_EXPORT Request
{
  Request() = default;

  explicit Request(int InputActivationSynchronizationTime)
    : _InputActivationSynchronizationTime(InputActivationSynchronizationTime)
  {}

  int _InputActivationSynchronizationTime;
};

}; // struct Post

}; // struct InputActivationSynchronizationTime

} // namespace sick::srt::multiScan200
