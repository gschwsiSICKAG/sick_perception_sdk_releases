/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file ScanConfig.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>
#include <sick_perception_sdk/sensor_configuration/api/NumericRange.hpp>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /ScanConfig.
*/
struct SDK_EXPORT ScanConfig
{

  constexpr static const char* variableName = "ScanConfig";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief scanner configuration.
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  struct SDK_EXPORT ScanRange
  {
    struct SDK_EXPORT aThetaAngleRangeItem
    {
      aThetaAngleRangeItem() = default;

      explicit aThetaAngleRangeItem(NumericRange<100, 100000, 4700> udiThetaAngleRes, NumericRange<-1800000, 1800000, -1380000> diThetaStartAngle, NumericRange<-1800000, 1800000, 1380000> diThetaStopAngle)
        : _udiThetaAngleRes(std::move(udiThetaAngleRes)), _diThetaStartAngle(std::move(diThetaStartAngle)), _diThetaStopAngle(std::move(diThetaStopAngle))
      {}

      NumericRange<100, 100000, 4700> _udiThetaAngleRes;
      NumericRange<-1800000, 1800000, -1380000> _diThetaStartAngle;
      NumericRange<-1800000, 1800000, 1380000> _diThetaStopAngle;
    };

    struct SDK_EXPORT aPhiAngleRangeItem
    {
      aPhiAngleRangeItem() = default;

      explicit aPhiAngleRangeItem(NumericRange<100, 100000, 4700> udiPhiAngleRes, NumericRange<-450000, 450000, -225000> diPhiStartAngle, NumericRange<-450000, 450000, 225000> diPhiStopAngle)
        : _udiPhiAngleRes(std::move(udiPhiAngleRes)), _diPhiStartAngle(std::move(diPhiStartAngle)), _diPhiStopAngle(std::move(diPhiStopAngle))
      {}

      NumericRange<100, 100000, 4700> _udiPhiAngleRes;
      NumericRange<-450000, 450000, -225000> _diPhiStartAngle;
      NumericRange<-450000, 450000, 225000> _diPhiStopAngle;
    };

    ScanRange() = default;

    explicit ScanRange(NumericRange<1, 1, 1> uiLength, std::array<aThetaAngleRangeItem, 1> aThetaAngleRange, std::array<aPhiAngleRangeItem, 1> aPhiAngleRange)
      : _uiLength(std::move(uiLength)), _aThetaAngleRange(aThetaAngleRange), _aPhiAngleRange(aPhiAngleRange)
    {}

    NumericRange<1, 1, 1> _uiLength;
    std::array<aThetaAngleRangeItem, 1> _aThetaAngleRange;
    std::array<aPhiAngleRangeItem, 1> _aPhiAngleRange;
  };

  Response() = default;

  explicit Response(NumericRange<100, 2000, 2000> udiScanFreq, ScanRange ScanRange)
    : _udiScanFreq(std::move(udiScanFreq)), _ScanRange(ScanRange)
  {}

  NumericRange<100, 2000, 2000> _udiScanFreq;
  ScanRange _ScanRange;
};

}; // struct Get

}; // struct ScanConfig

} // namespace sick::srt::multiScan200
