/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file FieldEvaluationResult.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /FieldEvaluationResult.
*/
struct SDK_EXPORT FieldEvaluationResult
{

  constexpr static const char* variableName = "FieldEvaluationResult";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief Get FieldEvaluationResult.
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  struct SDK_EXPORT FieldEvaluationResult
  {
    struct SDK_EXPORT EvaluationResultListItem
    {
      enum class State
      {
        NotConfigured = 0,
        Inactive = 1,
        Free = 2,
        DetectingInfringed = 3,
        Infringed = 4,
        DetectingFree = 5,
      };

      EvaluationResultListItem() = default;

      explicit EvaluationResultListItem(State State)
        : _State(State)
      {}

      State _State;
    };

    FieldEvaluationResult() = default;

    explicit FieldEvaluationResult(int Version, int Timestamp, std::vector<EvaluationResultListItem> EvaluationResultList)
      : _Version(Version), _Timestamp(Timestamp), _EvaluationResultList(EvaluationResultList)
    {}

    int _Version;
    int _Timestamp;
    std::vector<EvaluationResultListItem> _EvaluationResultList;
  };

  Response() = default;

  explicit Response(FieldEvaluationResult FieldEvaluationResult)
    : _FieldEvaluationResult(FieldEvaluationResult)
  {}

  FieldEvaluationResult _FieldEvaluationResult;
};

}; // struct Get

}; // struct FieldEvaluationResult

} // namespace sick::srt::multiScan200
