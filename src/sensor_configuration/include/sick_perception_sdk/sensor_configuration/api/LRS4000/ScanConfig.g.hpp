/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file ScanConfig.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'LRS4000' version '1.9.0.0R'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>
#include <sick_perception_sdk/sensor_configuration/api/NumericRange.hpp>

namespace sick::srt::LRS4000 {

/**
 * @brief Payloads for endpoint /ScanConfig.
*/
struct SDK_EXPORT ScanConfig
{

  constexpr static const char* variableName = "ScanConfig";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief Configuration of angular resolution, scanning frequency, start- and stop angle.
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  struct SDK_EXPORT ScanRange
  {
    struct SDK_EXPORT aRangeItem
    {
      aRangeItem() = default;

      explicit aRangeItem(NumericRange<200, 5000, 1200> udiAngleRes, NumericRange<-1800000, 1800000, -1800000> diStartAngle, NumericRange<-1800000, 1800000, 1800000> diStopAngle)
        : _udiAngleRes(std::move(udiAngleRes)), _diStartAngle(std::move(diStartAngle)), _diStopAngle(std::move(diStopAngle))
      {}

      NumericRange<200, 5000, 1200> _udiAngleRes;
      NumericRange<-1800000, 1800000, -1800000> _diStartAngle;
      NumericRange<-1800000, 1800000, 1800000> _diStopAngle;
    };

    ScanRange() = default;

    explicit ScanRange(NumericRange<1, 1, 1> uiLength, std::array<aRangeItem, 1> aRange)
      : _uiLength(std::move(uiLength)), _aRange(aRange)
    {}

    NumericRange<1, 1, 1> _uiLength;
    std::array<aRangeItem, 1> _aRange;
  };

  Response() = default;

  explicit Response(NumericRange<500, 2500, 1250> udiScanFreq, ScanRange ScanRange)
    : _udiScanFreq(std::move(udiScanFreq)), _ScanRange(ScanRange)
  {}

  NumericRange<500, 2500, 1250> _udiScanFreq;
  ScanRange _ScanRange;
};

}; // struct Get

}; // struct ScanConfig

} // namespace sick::srt::LRS4000
