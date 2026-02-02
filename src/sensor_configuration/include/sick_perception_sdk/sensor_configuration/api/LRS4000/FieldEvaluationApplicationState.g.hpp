/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file FieldEvaluationApplicationState.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'LRS4000' version '1.9.0.0R'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::LRS4000 {

/**
 * @brief Payloads for endpoint /FieldEvaluationApplicationState.
*/
struct SDK_EXPORT FieldEvaluationApplicationState
{

  constexpr static const char* variableName = "FieldEvaluationApplicationState";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief Get the field evaluation application state. It returns the information whether the field evaluation application is active, configuring or deactivated. 0 - Deactivated - no evaluation is set up. 1 - Activated - at least one active evaluation (group activation has no influence on that). 2 - Configuring - new calculation of the e.g. field geometries.
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

} // namespace sick::srt::LRS4000
