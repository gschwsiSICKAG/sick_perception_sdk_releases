/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file OutputState.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'picoScan150' version '2.2.1'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/sensor_configuration/api/NumericRange.hpp>

namespace sick::picoScan150::v2_2_1::api::rest {

/**
 * @brief Payloads for endpoint /OutputState.
*/
struct OutputState
{

  constexpr static const char* variableName = "OutputState";
  constexpr static const bool isSopasMethod = false;

  /**
   * @brief Returns the state of all outputs.
   */
  struct Get
  {
    struct Response
    {
      struct aDigitalOutItem
      {
        struct IOState
        {
          enum class eIOState
          {
            IosLow = 0,
            IosHigh = 1,
            IosTristate = 2,
          };

          IOState() = default;

          explicit IOState(eIOState eIOState)
            : _eIOState(eIOState)
          {}

          eIOState _eIOState;
        };

        aDigitalOutItem() = default;

        explicit aDigitalOutItem(IOState IOState, int udiCounter)
          : _IOState(IOState), _udiCounter(udiCounter)
        {}

        IOState _IOState;
        int _udiCounter;
      };

      struct aTimeBlockItem
      {
        aTimeBlockItem() = default;

        explicit aTimeBlockItem(NumericRange<0, 2105, 0> uiYear, NumericRange<0, 12, 1> usiMonth, NumericRange<0, 31, 1> usiDay, NumericRange<0, 23, 0> usiHour, NumericRange<0, 59, 0> usiMinute, NumericRange<0, 59, 0> usiSec, NumericRange<0, 999999, 0> udiUSec)
          : _uiYear(std::move(uiYear)), _usiMonth(std::move(usiMonth)), _usiDay(std::move(usiDay)), _usiHour(std::move(usiHour)), _usiMinute(std::move(usiMinute)), _usiSec(std::move(usiSec)), _udiUSec(std::move(udiUSec))
        {}

        NumericRange<0, 2105, 0> _uiYear;
        NumericRange<0, 12, 1> _usiMonth;
        NumericRange<0, 31, 1> _usiDay;
        NumericRange<0, 23, 0> _usiHour;
        NumericRange<0, 59, 0> _usiMinute;
        NumericRange<0, 59, 0> _usiSec;
        NumericRange<0, 999999, 0> _udiUSec;
      };

      Response() = default;

      explicit Response(int uiVersionNumber, int udiSystCount, std::array<aDigitalOutItem, 8> aDigitalOut, std::vector<aTimeBlockItem> aTimeBlock)
        : _uiVersionNumber(uiVersionNumber), _udiSystCount(udiSystCount), _aDigitalOut(aDigitalOut), _aTimeBlock(aTimeBlock)
      {}

      int _uiVersionNumber;
      int _udiSystCount;
      std::array<aDigitalOutItem, 8> _aDigitalOut;
      std::vector<aTimeBlockItem> _aTimeBlock;
    };

  }; // struct Get

}; // struct OutputState

} // namespace sick::picoScan150::v2_2_1::api::rest
