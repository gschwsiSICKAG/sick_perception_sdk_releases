/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file ScanDataScaleFactor.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'LRS4000' version '1.9.0.0R'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::LRS4000 {

/**
 * @brief Payloads for endpoint /ScanDataScaleFactor.
*/
struct SDK_EXPORT ScanDataScaleFactor
{

  constexpr static const char* variableName = "ScanDataScaleFactor";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief Configure the scaling factor for distance measurements when LMDscandata or Compact is selected as the data output format.
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  Response() = default;

  explicit Response(float ScanDataScaleFactor)
    : _ScanDataScaleFactor(ScanDataScaleFactor)
  {}

  float _ScanDataScaleFactor;
};

}; // struct Get

/**
 * @brief Configure the scaling factor for distance measurements when LMDscandata or Compact is selected as the data output format.

 This function requires at least user level: Authorized Client.
*/
struct SDK_EXPORT Post
{
struct SDK_EXPORT Request
{
  Request() = default;

  explicit Request(float ScanDataScaleFactor)
    : _ScanDataScaleFactor(ScanDataScaleFactor)
  {}

  float _ScanDataScaleFactor;
};

}; // struct Post

}; // struct ScanDataScaleFactor

} // namespace sick::srt::LRS4000
