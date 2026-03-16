/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file SetFieldEvaluationContour.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan100' version '2.4.1'.
 * Do not edit manually!
 *
 * @note This class represents the payload of a SOPAS method. Do not use in `write_variable()`!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>
#include <sick_perception_sdk/sensor_configuration/api/NumericRange.hpp>

namespace sick::multiScan100::v2_4_1::api::rest {

/**
 * @brief Payloads for endpoint /SetFieldEvaluationContour.
*/
struct SDK_EXPORT SetFieldEvaluationContour
{

  constexpr static const char* methodName = "SetFieldEvaluationContour";
  constexpr static const bool isSopasMethod = true;

  /**
   * @brief Sets the contour of an existing field.

 This function requires at least user level: Authorized Client.
   */
  struct SDK_EXPORT Post
  {
    struct SDK_EXPORT Request
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

      Request() = default;

      explicit Request(int EvaluationId, std::vector<PointsItem> Points, NumericRange<-100000, 100000, 0> LowerZLimit, NumericRange<-100000, 100000, 0> UpperZLimit)
        : _EvaluationId(EvaluationId), _Points(Points), _LowerZLimit(std::move(LowerZLimit)), _UpperZLimit(std::move(UpperZLimit))
      {}

      int _EvaluationId;
      std::vector<PointsItem> _Points;
      NumericRange<-100000, 100000, 0> _LowerZLimit;
      NumericRange<-100000, 100000, 0> _UpperZLimit;
    };

    struct SDK_EXPORT Response
    {
      enum class ErrorCode
      {
        SopasErrNoErr = 0,
        SopasErrInvalidEvaluationId = 1,
        SopasErrInvalidPolygon = 2,
        SopasErrInvalidZlim = 3,
      };

      Response() = default;

      explicit Response(ErrorCode ErrorCode)
        : _ErrorCode(ErrorCode)
      {}

      ErrorCode _ErrorCode;
    };

  }; // struct Post

}; // struct SetFieldEvaluationContour

} // namespace sick::multiScan100::v2_4_1::api::rest
