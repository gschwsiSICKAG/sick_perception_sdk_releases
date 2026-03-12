/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file PolarProjectionParameters.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /PolarProjectionParameters.
*/
struct SDK_EXPORT PolarProjectionParameters
{

  constexpr static const char* variableName = "PolarProjectionParameters";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief Get PolarProjectionParameters.
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  struct SDK_EXPORT PolarProjectionParametersItem
  {
    PolarProjectionParametersItem() = default;

    explicit PolarProjectionParametersItem(float originAzimuth, float originElevation, float stepSizeAzimuth, float stepSizeElevation, int width, int height)
      : _originAzimuth(originAzimuth), _originElevation(originElevation), _stepSizeAzimuth(stepSizeAzimuth), _stepSizeElevation(stepSizeElevation), _width(width), _height(height)
    {}

    float _originAzimuth;
    float _originElevation;
    float _stepSizeAzimuth;
    float _stepSizeElevation;
    int _width;
    int _height;
  };

  Response() = default;

  explicit Response(std::vector<PolarProjectionParametersItem> PolarProjectionParameters)
    : _PolarProjectionParameters(PolarProjectionParameters)
  {}

  std::vector<PolarProjectionParametersItem> _PolarProjectionParameters;
};

}; // struct Get

}; // struct PolarProjectionParameters

} // namespace sick::srt::multiScan200
