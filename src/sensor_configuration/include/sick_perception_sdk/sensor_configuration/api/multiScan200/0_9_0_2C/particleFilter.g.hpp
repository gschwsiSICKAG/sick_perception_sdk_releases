/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file particleFilter.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0.2C'.
 * Do not edit manually!
 */
#pragma once

#include <cstdint>
#include <sick_perception_sdk/sensor_configuration/api/NumericRange.hpp>

namespace sick::multiScan200::v0_9_0_2C::api::rest {

/**
 * @brief Payloads for endpoint /particleFilter.
*/
struct particleFilter
{

  constexpr static const char* variableName = "particleFilter";
  constexpr static const bool isSopasMethod = false;

  /**
   * @brief Returns/sets the particle filter settings. Filters out disturbances in the measurement data caused by particles such as dust, snow, or similar.
   */
  struct Get
  {
    struct Response
    {
      Response() = default;

      explicit Response(bool enable, std::uint16_t minNumberOfNeighbors, NumericRange<std::uint16_t, 20, 2000, 500> distanceThreshold)
        : _enable(enable), _minNumberOfNeighbors(minNumberOfNeighbors), _distanceThreshold(std::move(distanceThreshold))
      {}

      bool _enable;
      std::uint16_t _minNumberOfNeighbors;
      NumericRange<std::uint16_t, 20, 2000, 500> _distanceThreshold;
    };

  }; // struct Get

  /**
   * @brief Returns/sets the particle filter settings. Filters out disturbances in the measurement data caused by particles such as dust, snow, or similar.

 This function requires at least user level: Authorized Client.
   */
  struct Post
  {
    struct Request
    {
      Request() = default;

      explicit Request(bool enable, std::uint16_t minNumberOfNeighbors, NumericRange<std::uint16_t, 20, 2000, 500> distanceThreshold)
        : _enable(enable), _minNumberOfNeighbors(minNumberOfNeighbors), _distanceThreshold(std::move(distanceThreshold))
      {}

      bool _enable;
      std::uint16_t _minNumberOfNeighbors;
      NumericRange<std::uint16_t, 20, 2000, 500> _distanceThreshold;
    };

  }; // struct Post

}; // struct particleFilter

} // namespace sick::multiScan200::v0_9_0_2C::api::rest
