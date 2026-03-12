/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file EvaluationConfigState.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /EvaluationConfigState.
*/
struct SDK_EXPORT EvaluationConfigState
{

  constexpr static const char* variableName = "EvaluationConfigState";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief Get EvaluationConfigState.
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

} // namespace sick::srt::multiScan200
