/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file GetFieldEvaluationContour.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'picoScan150' version '2.2.1'.
 * Do not edit manually!
 *
 * @note This class represents the payload of a SOPAS method. Do not use in `write_variable()`!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>
#include <sick_perception_sdk/sensor_configuration/api/NumericRange.hpp>

namespace sick::picoScan150::v2_2_1::api::rest {

/**
 * @brief Payloads for endpoint /GetFieldEvaluationContour.
*/
struct SDK_EXPORT GetFieldEvaluationContour
{

  constexpr static const char* methodName = "GetFieldEvaluationContour";
  constexpr static const bool isSopasMethod = true;

  /**
   * @brief Returns the contour of an existing field.

 This function requires at least user level: Authorized Client.
   */
  struct SDK_EXPORT Post
  {
    struct SDK_EXPORT Request
    {
      Request() = default;

      explicit Request(int EvaluationId)
        : _EvaluationId(EvaluationId)
      {}

      int _EvaluationId;
    };

    struct SDK_EXPORT Response
    {
      struct SDK_EXPORT ContourItem
      {
        struct SDK_EXPORT PointsItem
        {
          PointsItem() = default;

          explicit PointsItem(int x, int y)
            : _x(x), _y(y)
          {}

          int _x;
          int _y;
        };

        ContourItem() = default;

        explicit ContourItem(int EvaluationId, std::vector<PointsItem> Points, NumericRange<-100000, 100000, 0> LowerZLimit, NumericRange<-100000, 100000, 0> UpperZLimit)
          : _EvaluationId(EvaluationId), _Points(Points), _LowerZLimit(std::move(LowerZLimit)), _UpperZLimit(std::move(UpperZLimit))
        {}

        int _EvaluationId;
        std::vector<PointsItem> _Points;
        NumericRange<-100000, 100000, 0> _LowerZLimit;
        NumericRange<-100000, 100000, 0> _UpperZLimit;
      };

      Response() = default;

      explicit Response(std::vector<ContourItem> Contour)
        : _Contour(Contour)
      {}

      std::vector<ContourItem> _Contour;
    };

  }; // struct Post

}; // struct GetFieldEvaluationContour

} // namespace sick::picoScan150::v2_2_1::api::rest
