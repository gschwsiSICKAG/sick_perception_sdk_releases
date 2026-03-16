/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file ScanConfig.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'picoScan150' version '2.2.1'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>
#include <sick_perception_sdk/sensor_configuration/api/NumericRange.hpp>

namespace sick::picoScan150::v2_2_1::api::rest {

/**
 * @brief Payloads for endpoint /ScanConfig.
*/
struct SDK_EXPORT ScanConfig
{

  constexpr static const char* variableName = "ScanConfig";
  constexpr static const bool isSopasMethod = false;

  /**
   * @brief Returns the configuration of angular resolution, scanning frequency, start and stop angle.
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

          explicit aRangeItem(NumericRange<500, 10000, 2500> udiAngleRes, NumericRange<-1380000, 1380000, -1380000> diStartAngle, NumericRange<-1380000, 1380000, 1380000> diStopAngle)
            : _udiAngleRes(std::move(udiAngleRes)), _diStartAngle(std::move(diStartAngle)), _diStopAngle(std::move(diStopAngle))
          {}

          NumericRange<500, 10000, 2500> _udiAngleRes;
          NumericRange<-1380000, 1380000, -1380000> _diStartAngle;
          NumericRange<-1380000, 1380000, 1380000> _diStopAngle;
        };

        ScanRange() = default;

        explicit ScanRange(NumericRange<1, 1, 1> uiLength, std::array<aRangeItem, 1> aRange)
          : _uiLength(std::move(uiLength)), _aRange(aRange)
        {}

        NumericRange<1, 1, 1> _uiLength;
        std::array<aRangeItem, 1> _aRange;
      };

      Response() = default;

      explicit Response(NumericRange<1500, 5000, 4000> udiScanFreq, ScanRange ScanRange)
        : _udiScanFreq(std::move(udiScanFreq)), _ScanRange(ScanRange)
      {}

      NumericRange<1500, 5000, 4000> _udiScanFreq;
      ScanRange _ScanRange;
    };

  }; // struct Get

}; // struct ScanConfig

} // namespace sick::picoScan150::v2_2_1::api::rest
