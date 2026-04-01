/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file ScanConfig.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0.2C'.
 * Do not edit manually!
 */
#pragma once

#include <cstdint>
#include <sick_perception_sdk/sensor_configuration/api/NumericRange.hpp>

namespace sick::multiScan200::v0_9_0_2C::api::rest {

/**
 * @brief Payloads for endpoint /ScanConfig.
*/
struct ScanConfig
{

  constexpr static const char* variableName = "ScanConfig";
  constexpr static const bool isSopasMethod = false;

  /**
   * @brief Returns the configuration of angular resolution, scanning frequency and start angle.
   */
  struct Get
  {
    struct Response
    {
      struct ScanRange
      {
        struct aThetaAngleRangeItem
        {
          aThetaAngleRangeItem() = default;

          explicit aThetaAngleRangeItem(NumericRange<std::uint32_t, 100, 100000, 4700> udiThetaAngleRes, NumericRange<std::int32_t, -1800000, 1800000, -1380000> diThetaStartAngle, NumericRange<std::int32_t, -1800000, 1800000, 1380000> diThetaStopAngle)
            : _udiThetaAngleRes(std::move(udiThetaAngleRes)), _diThetaStartAngle(std::move(diThetaStartAngle)), _diThetaStopAngle(std::move(diThetaStopAngle))
          {}

          NumericRange<std::uint32_t, 100, 100000, 4700> _udiThetaAngleRes;
          NumericRange<std::int32_t, -1800000, 1800000, -1380000> _diThetaStartAngle;
          NumericRange<std::int32_t, -1800000, 1800000, 1380000> _diThetaStopAngle;
        };

        struct aPhiAngleRangeItem
        {
          aPhiAngleRangeItem() = default;

          explicit aPhiAngleRangeItem(NumericRange<std::uint32_t, 100, 100000, 4700> udiPhiAngleRes, NumericRange<std::int32_t, -450000, 450000, -225000> diPhiStartAngle, NumericRange<std::int32_t, -450000, 450000, 225000> diPhiStopAngle)
            : _udiPhiAngleRes(std::move(udiPhiAngleRes)), _diPhiStartAngle(std::move(diPhiStartAngle)), _diPhiStopAngle(std::move(diPhiStopAngle))
          {}

          NumericRange<std::uint32_t, 100, 100000, 4700> _udiPhiAngleRes;
          NumericRange<std::int32_t, -450000, 450000, -225000> _diPhiStartAngle;
          NumericRange<std::int32_t, -450000, 450000, 225000> _diPhiStopAngle;
        };

        ScanRange() = default;

        explicit ScanRange(NumericRange<std::uint16_t, 1, 1, 1> uiLength, std::array<aThetaAngleRangeItem, 1> aThetaAngleRange, std::array<aPhiAngleRangeItem, 1> aPhiAngleRange)
          : _uiLength(std::move(uiLength)), _aThetaAngleRange(aThetaAngleRange), _aPhiAngleRange(aPhiAngleRange)
        {}

        NumericRange<std::uint16_t, 1, 1, 1> _uiLength;
        std::array<aThetaAngleRangeItem, 1> _aThetaAngleRange;
        std::array<aPhiAngleRangeItem, 1> _aPhiAngleRange;
      };

      Response() = default;

      explicit Response(NumericRange<std::uint32_t, 100, 2000, 2000> udiScanFreq, ScanRange ScanRange)
        : _udiScanFreq(std::move(udiScanFreq)), _ScanRange(ScanRange)
      {}

      NumericRange<std::uint32_t, 100, 2000, 2000> _udiScanFreq;
      ScanRange _ScanRange;
    };

  }; // struct Get

}; // struct ScanConfig

} // namespace sick::multiScan200::v0_9_0_2C::api::rest
