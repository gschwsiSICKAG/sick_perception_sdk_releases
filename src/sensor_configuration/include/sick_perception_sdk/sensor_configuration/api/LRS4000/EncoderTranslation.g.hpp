/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file EncoderTranslation.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'LRS4000' version '1.9.0.0R'.
 * Do not edit manually!
 *
 * @note This class represents the payload of a SOPAS method. Do not use in `write_variable()`!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>
#include <sick_perception_sdk/sensor_configuration/api/NumericRange.hpp>

namespace sick::srt::LRS4000 {

/**
 * @brief Payloads for endpoint /EncoderTranslation.
*/
struct SDK_EXPORT EncoderTranslation
{

  constexpr static const char* methodName = "EncoderTranslation";
  constexpr static const bool isSopasMethod = true;

/**
 * @brief Set the start orientation when the encoder transformation type is set to translation.

 This function requires at least user level: Authorized Client.
*/
struct SDK_EXPORT Post
{
struct SDK_EXPORT Request
{
  Request() = default;

  explicit Request(NumericRange<-100000, 100000, 0> x, NumericRange<-100000, 100000, 0> y, NumericRange<-100000, 100000, 0> z)
    : _x(std::move(x)), _y(std::move(y)), _z(std::move(z))
  {}

  NumericRange<-100000, 100000, 0> _x;
  NumericRange<-100000, 100000, 0> _y;
  NumericRange<-100000, 100000, 0> _z;
};

}; // struct Post

}; // struct EncoderTranslation

} // namespace sick::srt::LRS4000
