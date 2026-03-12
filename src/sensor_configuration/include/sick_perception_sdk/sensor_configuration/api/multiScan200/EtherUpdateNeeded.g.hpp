/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file EtherUpdateNeeded.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /EtherUpdateNeeded.
*/
struct SDK_EXPORT EtherUpdateNeeded
{

  constexpr static const char* variableName = "EtherUpdateNeeded";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief Signs that due to parameter changes a update is meaningful.
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  Response() = default;

  explicit Response(bool EtherUpdateNeeded)
    : _EtherUpdateNeeded(EtherUpdateNeeded)
  {}

  bool _EtherUpdateNeeded;
};

}; // struct Get

/**
 * @brief Signs that due to parameter changes a update is meaningful.
*/
struct SDK_EXPORT Post
{
struct SDK_EXPORT Request
{
  Request() = default;

  explicit Request(bool EtherUpdateNeeded)
    : _EtherUpdateNeeded(EtherUpdateNeeded)
  {}

  bool _EtherUpdateNeeded;
};

}; // struct Post

}; // struct EtherUpdateNeeded

} // namespace sick::srt::multiScan200
