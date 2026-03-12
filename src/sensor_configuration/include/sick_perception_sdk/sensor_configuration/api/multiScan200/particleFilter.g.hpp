/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file particleFilter.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>
#include <sick_perception_sdk/sensor_configuration/api/NumericRange.hpp>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /particleFilter.
*/
struct SDK_EXPORT particleFilter
{

  constexpr static const char* variableName = "particleFilter";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief Particle filter.
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  Response() = default;

  explicit Response(bool enable, int minNumberOfNeighbors, NumericRange<20, 2000, 500> distanceThreshold)
    : _enable(enable), _minNumberOfNeighbors(minNumberOfNeighbors), _distanceThreshold(std::move(distanceThreshold))
  {}

  bool _enable;
  int _minNumberOfNeighbors;
  NumericRange<20, 2000, 500> _distanceThreshold;
};

}; // struct Get

/**
 * @brief Particle filter.

 This function requires at least user level: Authorized Client.
*/
struct SDK_EXPORT Post
{
struct SDK_EXPORT Request
{
  Request() = default;

  explicit Request(bool enable, int minNumberOfNeighbors, NumericRange<20, 2000, 500> distanceThreshold)
    : _enable(enable), _minNumberOfNeighbors(minNumberOfNeighbors), _distanceThreshold(std::move(distanceThreshold))
  {}

  bool _enable;
  int _minNumberOfNeighbors;
  NumericRange<20, 2000, 500> _distanceThreshold;
};

}; // struct Post

}; // struct particleFilter

} // namespace sick::srt::multiScan200
