/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file LFPcubicareafilter.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'picoScan150' version '2.2.1'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>
#include <sick_perception_sdk/sensor_configuration/api/NumericRange.hpp>

namespace sick::picoScan150::v2_2_1::api::rest {

/**
 * @brief Payloads for endpoint /LFPcubicareafilter.
*/
struct SDK_EXPORT LFPcubicareafilter
{

  constexpr static const char* variableName = "LFPcubicareafilter";
  constexpr static const bool isSopasMethod = false;

  /**
   * @brief Returns/sets the cuboid area filter settings. The cuboid area filter limits the measurement data to a box defined by its extension in the x- and y-axis.
   */
  struct SDK_EXPORT Get
  {
    struct SDK_EXPORT Response
    {
      Response() = default;

      explicit Response(bool bEnable, NumericRange<-200000, 200000, 0> lXMin, NumericRange<-200000, 200000, 5000> lXMax, NumericRange<-200000, 200000, -5000> lYMin, NumericRange<-200000, 200000, 5000> lYMax, NumericRange<-200000, 200000, -20000> lZMin, NumericRange<-200000, 200000, 20000> lZMax)
        : _bEnable(bEnable), _lXMin(std::move(lXMin)), _lXMax(std::move(lXMax)), _lYMin(std::move(lYMin)), _lYMax(std::move(lYMax)), _lZMin(std::move(lZMin)), _lZMax(std::move(lZMax))
      {}

      bool _bEnable;
      NumericRange<-200000, 200000, 0> _lXMin;
      NumericRange<-200000, 200000, 5000> _lXMax;
      NumericRange<-200000, 200000, -5000> _lYMin;
      NumericRange<-200000, 200000, 5000> _lYMax;
      NumericRange<-200000, 200000, -20000> _lZMin;
      NumericRange<-200000, 200000, 20000> _lZMax;
    };

  }; // struct Get

  /**
   * @brief Returns/sets the cuboid area filter settings. The cuboid area filter limits the measurement data to a box defined by its extension in the x- and y-axis.

 This function requires at least user level: Authorized Client.
   */
  struct SDK_EXPORT Post
  {
    struct SDK_EXPORT Request
    {
      Request() = default;

      explicit Request(bool bEnable, NumericRange<-200000, 200000, 0> lXMin, NumericRange<-200000, 200000, 5000> lXMax, NumericRange<-200000, 200000, -5000> lYMin, NumericRange<-200000, 200000, 5000> lYMax, NumericRange<-200000, 200000, -20000> lZMin, NumericRange<-200000, 200000, 20000> lZMax)
        : _bEnable(bEnable), _lXMin(std::move(lXMin)), _lXMax(std::move(lXMax)), _lYMin(std::move(lYMin)), _lYMax(std::move(lYMax)), _lZMin(std::move(lZMin)), _lZMax(std::move(lZMax))
      {}

      bool _bEnable;
      NumericRange<-200000, 200000, 0> _lXMin;
      NumericRange<-200000, 200000, 5000> _lXMax;
      NumericRange<-200000, 200000, -5000> _lYMin;
      NumericRange<-200000, 200000, 5000> _lYMax;
      NumericRange<-200000, 200000, -20000> _lZMin;
      NumericRange<-200000, 200000, 20000> _lZMax;
    };

  }; // struct Post

}; // struct LFPcubicareafilter

} // namespace sick::picoScan150::v2_2_1::api::rest
