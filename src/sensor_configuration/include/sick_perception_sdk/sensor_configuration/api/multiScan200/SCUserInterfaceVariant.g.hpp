/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file SCUserInterfaceVariant.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /SCUserInterfaceVariant.
*/
struct SDK_EXPORT SCUserInterfaceVariant
{

  constexpr static const char* variableName = "SCUserInterfaceVariant";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief Defines which kind of User interface has been used for parametrization. Variable may be set by the OnDeviceAdded-Hook.
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  enum class SCUserInterfaceVariant
  {
    TxNotDefined = 0,
    TxSopasEtStandard = 1,
  };

  Response() = default;

  explicit Response(SCUserInterfaceVariant SCUserInterfaceVariant)
    : _SCUserInterfaceVariant(SCUserInterfaceVariant)
  {}

  SCUserInterfaceVariant _SCUserInterfaceVariant;
};

}; // struct Get

/**
 * @brief Defines which kind of User interface has been used for parametrization. Variable may be set by the OnDeviceAdded-Hook.
*/
struct SDK_EXPORT Post
{
struct SDK_EXPORT Request
{
  enum class SCUserInterfaceVariant
  {
    TxNotDefined = 0,
    TxSopasEtStandard = 1,
  };

  Request() = default;

  explicit Request(SCUserInterfaceVariant SCUserInterfaceVariant)
    : _SCUserInterfaceVariant(SCUserInterfaceVariant)
  {}

  SCUserInterfaceVariant _SCUserInterfaceVariant;
};

}; // struct Post

}; // struct SCUserInterfaceVariant

} // namespace sick::srt::multiScan200
