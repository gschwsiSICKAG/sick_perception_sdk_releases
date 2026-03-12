/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file FieldEvaluationApplicationState.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /FieldEvaluationApplicationState.
*/
struct SDK_EXPORT FieldEvaluationApplicationState
{

  constexpr static const char* variableName = "FieldEvaluationApplicationState";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief Get FieldEvaluationApplicationState.
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  enum class FieldEvaluationApplicationState
  {
    Deactivated = 0,
    Active = 1,
    Configuring = 2,
    Error = 3,
  };

  Response() = default;

  explicit Response(FieldEvaluationApplicationState FieldEvaluationApplicationState)
    : _FieldEvaluationApplicationState(FieldEvaluationApplicationState)
  {}

  FieldEvaluationApplicationState _FieldEvaluationApplicationState;
};

}; // struct Get

}; // struct FieldEvaluationApplicationState

} // namespace sick::srt::multiScan200
