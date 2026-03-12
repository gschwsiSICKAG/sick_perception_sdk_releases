/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file SetScanConfigList.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 *
 * @note This class represents the payload of a SOPAS method. Do not use in `write_variable()`!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /SetScanConfigList.
*/
struct SDK_EXPORT SetScanConfigList
{

  constexpr static const char* methodName = "SetScanConfigList";
  constexpr static const bool isSopasMethod = true;

/**
 * @brief Sets the scan and angle resolution configuration from a list.

 This function requires at least user level: Authorized Client.
*/
struct SDK_EXPORT Post
{
struct SDK_EXPORT Request
{
  enum class ScanConfigList
  {
    Allrounder = 0,
    Sharpness1Vertical = 11,
    Sharpness1Horizontal = 12,
    Sharpness2 = 13,
    MaxTemp1 = 21,
    MaxTemp2 = 22,
  };

  Request() = default;

  explicit Request(ScanConfigList ScanConfigList)
    : _ScanConfigList(ScanConfigList)
  {}

  ScanConfigList _ScanConfigList;
};

struct SDK_EXPORT Response
{
  enum class eScanConfigError
  {
    SceOk = 0,
    SceErrorFreq = 1,
    SceErrorRes = 2,
    SceErrorFreqResComb = 3,
    SceErrorNumRange = 4,
    SceError = 5,
  };

  Response() = default;

  explicit Response(eScanConfigError eScanConfigError)
    : _eScanConfigError(eScanConfigError)
  {}

  eScanConfigError _eScanConfigError;
};

}; // struct Post

}; // struct SetScanConfigList

} // namespace sick::srt::multiScan200
