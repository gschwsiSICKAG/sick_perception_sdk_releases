/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file FieldEvaluationApplicationState.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan100' version '2.4.1'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::multiScan100 {

/**
 * @brief Payloads for endpoint /FieldEvaluationApplicationState.
*/
struct SDK_EXPORT FieldEvaluationApplicationState
{

  constexpr static const char* variableName = "FieldEvaluationApplicationState";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief Returns the state (DEACTIVATED, ACTIVE, CONFIGURING, ERROR) of the field evaluation.
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

} // namespace sick::srt::multiScan100
