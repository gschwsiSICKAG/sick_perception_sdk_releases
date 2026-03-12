/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file InertialMeasurementUnit.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /InertialMeasurementUnit.
*/
struct SDK_EXPORT InertialMeasurementUnit
{

  constexpr static const char* variableName = "InertialMeasurementUnit";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief Provides access to the data of an InertialMeasurementUnit (IMU) which offers - depending on the used hardware - information about acceleration, angular velocity, magnetic field and the orientation. If one of these quantities is not available the respective values are set to 0. The data is given in the following coordinate system which is based on the DIN70000 system: The x-axis lies on the 90° beam of the 0° layer. The y-axis is perpendicular to the x-axis and lies in the 0° layer. The y-values are rising in the counter clock wise rotation direction (right handed system). The z-axis is perpendicular to the x-y-plane and the scanner top points to rising z-values. If no magnetic field sensor is available the heading.
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  Response() = default;

  explicit Response(std::vector<float> Acceleration, std::vector<float> AngularVelocity, std::vector<float> Orientation, int TimeStamp)
    : _Acceleration(Acceleration), _AngularVelocity(AngularVelocity), _Orientation(Orientation), _TimeStamp(TimeStamp)
  {}

  std::vector<float> _Acceleration;
  std::vector<float> _AngularVelocity;
  std::vector<float> _Orientation;
  int _TimeStamp;
};

}; // struct Get

/**
 * @brief Provides access to the data of an InertialMeasurementUnit (IMU) which offers - depending on the used hardware - information about acceleration, angular velocity, magnetic field and the orientation. If one of these quantities is not available the respective values are set to 0. The data is given in the following coordinate system which is based on the DIN70000 system: The x-axis lies on the 90° beam of the 0° layer. The y-axis is perpendicular to the x-axis and lies in the 0° layer. The y-values are rising in the counter clock wise rotation direction (right handed system). The z-axis is perpendicular to the x-y-plane and the scanner top points to rising z-values. If no magnetic field sensor is available the heading.
*/
struct SDK_EXPORT Post
{
struct SDK_EXPORT Request
{
  Request() = default;

  explicit Request(std::vector<float> Acceleration, std::vector<float> AngularVelocity, std::vector<float> Orientation, int TimeStamp)
    : _Acceleration(Acceleration), _AngularVelocity(AngularVelocity), _Orientation(Orientation), _TimeStamp(TimeStamp)
  {}

  std::vector<float> _Acceleration;
  std::vector<float> _AngularVelocity;
  std::vector<float> _Orientation;
  int _TimeStamp;
};

}; // struct Post

}; // struct InertialMeasurementUnit

} // namespace sick::srt::multiScan200
