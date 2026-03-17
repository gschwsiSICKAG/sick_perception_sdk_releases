/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file perpendicularDistanceResult.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan100' version '2.4.1'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/sensor_configuration/api/NumericRange.hpp>

namespace sick::multiScan100::v2_4_1::api::rest {

/**
 * @brief Payloads for endpoint /perpendicularDistanceResult.
*/
struct perpendicularDistanceResult
{

  constexpr static const char* variableName = "perpendicularDistanceResult";
  constexpr static const bool isSopasMethod = false;

  /**
   * @brief Returs the perpendicular distance within a field.
   */
  struct Get
  {
    struct Response
    {
      struct evaluationsItem
      {
        struct minimumDistancePosition
        {
          minimumDistancePosition() = default;

          explicit minimumDistancePosition(NumericRange<-500000, 500000, 0> x, NumericRange<-500000, 500000, 0> y, NumericRange<-500000, 500000, 0> z)
            : _x(std::move(x)), _y(std::move(y)), _z(std::move(z))
          {}

          NumericRange<-500000, 500000, 0> _x;
          NumericRange<-500000, 500000, 0> _y;
          NumericRange<-500000, 500000, 0> _z;
        };

        struct maximumDistancePosition
        {
          maximumDistancePosition() = default;

          explicit maximumDistancePosition(NumericRange<-500000, 500000, 0> x, NumericRange<-500000, 500000, 0> y, NumericRange<-500000, 500000, 0> z)
            : _x(std::move(x)), _y(std::move(y)), _z(std::move(z))
          {}

          NumericRange<-500000, 500000, 0> _x;
          NumericRange<-500000, 500000, 0> _y;
          NumericRange<-500000, 500000, 0> _z;
        };

        evaluationsItem() = default;

        explicit evaluationsItem(int evaluationId, int minimumDistance, int maximumDistance, minimumDistancePosition minimumDistancePosition, maximumDistancePosition maximumDistancePosition)
          : _evaluationId(evaluationId), _minimumDistance(minimumDistance), _maximumDistance(maximumDistance), _minimumDistancePosition(minimumDistancePosition), _maximumDistancePosition(maximumDistancePosition)
        {}

        int _evaluationId;
        int _minimumDistance;
        int _maximumDistance;
        minimumDistancePosition _minimumDistancePosition;
        maximumDistancePosition _maximumDistancePosition;
      };

      Response() = default;

      explicit Response(int timestamp, std::vector<evaluationsItem> evaluations)
        : _timestamp(timestamp), _evaluations(evaluations)
      {}

      int _timestamp;
      std::vector<evaluationsItem> _evaluations;
    };

  }; // struct Get

}; // struct perpendicularDistanceResult

} // namespace sick::multiScan100::v2_4_1::api::rest
