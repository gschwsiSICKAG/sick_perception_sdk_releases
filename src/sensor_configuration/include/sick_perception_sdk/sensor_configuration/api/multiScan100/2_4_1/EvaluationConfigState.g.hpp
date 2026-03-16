/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file EvaluationConfigState.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan100' version '2.4.1'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::multiScan100::v2_4_1::api::rest {

/**
 * @brief Payloads for endpoint /EvaluationConfigState.
*/
struct SDK_EXPORT EvaluationConfigState
{

  constexpr static const char* variableName = "EvaluationConfigState";
  constexpr static const bool isSopasMethod = false;

  /**
   * @brief Returns the performance state (OK, WWANING, EXEEDED) of an evaluation config.
   */
  struct SDK_EXPORT Get
  {
    struct SDK_EXPORT Response
    {
      enum class ActiveBeamsLimit
      {
        Ok = 0,
        Warning = 1,
        Exceeded = 2,
      };

      enum class ActiveEvaluationsLimit
      {
        Ok = 0,
        Warning = 1,
        Exceeded = 2,
      };

      Response() = default;

      explicit Response(ActiveBeamsLimit ActiveBeamsLimit, ActiveEvaluationsLimit ActiveEvaluationsLimit, std::vector<int> NumberOfIntersectingBeams, std::vector<int> InputIsOutputErrorList)
        : _ActiveBeamsLimit(ActiveBeamsLimit), _ActiveEvaluationsLimit(ActiveEvaluationsLimit), _NumberOfIntersectingBeams(NumberOfIntersectingBeams), _InputIsOutputErrorList(InputIsOutputErrorList)
      {}

      ActiveBeamsLimit _ActiveBeamsLimit;
      ActiveEvaluationsLimit _ActiveEvaluationsLimit;
      std::vector<int> _NumberOfIntersectingBeams;
      std::vector<int> _InputIsOutputErrorList;
    };

  }; // struct Get

}; // struct EvaluationConfigState

} // namespace sick::multiScan100::v2_4_1::api::rest
