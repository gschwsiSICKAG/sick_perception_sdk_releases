/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file SensorPosition.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'picoScan120' version '2.2.1'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>
#include <sick_perception_sdk/sensor_configuration/api/NumericRange.hpp>

namespace sick::picoScan120::v2_2_1::api::rest {

/**
 * @brief Payloads for endpoint /SensorPosition.
*/
struct SDK_EXPORT SensorPosition
{

  constexpr static const char* variableName = "SensorPosition";
  constexpr static const bool isSopasMethod = false;

  /**
   * @brief Returns/sets the mounting position in 1/10000 deg. This only affects the PointCloud2 format output by native ROS2.
   */
  struct SDK_EXPORT Get
  {
    struct SDK_EXPORT Response
    {
      Response() = default;

      explicit Response(NumericRange<-100000, 100000, 0> x, NumericRange<-100000, 100000, 0> y, NumericRange<-100000, 100000, 0> z, NumericRange<-3600000, 3600000, 0> yaw, NumericRange<-3600000, 3600000, 0> pitch, NumericRange<-3600000, 3600000, 0> roll)
        : _x(std::move(x)), _y(std::move(y)), _z(std::move(z)), _yaw(std::move(yaw)), _pitch(std::move(pitch)), _roll(std::move(roll))
      {}

      NumericRange<-100000, 100000, 0> _x;
      NumericRange<-100000, 100000, 0> _y;
      NumericRange<-100000, 100000, 0> _z;
      NumericRange<-3600000, 3600000, 0> _yaw;
      NumericRange<-3600000, 3600000, 0> _pitch;
      NumericRange<-3600000, 3600000, 0> _roll;
    };

  }; // struct Get

}; // struct SensorPosition

} // namespace sick::picoScan120::v2_2_1::api::rest
