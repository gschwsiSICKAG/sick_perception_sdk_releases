/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file PolarProjectionVectors.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /PolarProjectionVectors.
*/
struct SDK_EXPORT PolarProjectionVectors
{

  constexpr static const char* variableName = "PolarProjectionVectors";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief Get PolarProjectionVectors.
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  struct SDK_EXPORT PolarProjectionVectorsItem
  {
    PolarProjectionVectorsItem() = default;

    explicit PolarProjectionVectorsItem(std::vector<float> AzimuthAngles, std::vector<float> ElevationAngles)
      : _AzimuthAngles(AzimuthAngles), _ElevationAngles(ElevationAngles)
    {}

    std::vector<float> _AzimuthAngles;
    std::vector<float> _ElevationAngles;
  };

  Response() = default;

  explicit Response(std::vector<PolarProjectionVectorsItem> PolarProjectionVectors)
    : _PolarProjectionVectors(PolarProjectionVectors)
  {}

  std::vector<PolarProjectionVectorsItem> _PolarProjectionVectors;
};

}; // struct Get

}; // struct PolarProjectionVectors

} // namespace sick::srt::multiScan200
