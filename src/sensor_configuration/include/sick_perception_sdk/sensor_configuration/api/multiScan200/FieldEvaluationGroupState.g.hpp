/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file FieldEvaluationGroupState.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /FieldEvaluationGroupState.
*/
struct SDK_EXPORT FieldEvaluationGroupState
{

  constexpr static const char* variableName = "FieldEvaluationGroupState";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief Contains the current activation state of all available groups (not configured, active or inactive).
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  Response() = default;

  explicit Response(std::array<int, 48> FieldEvaluationGroupState)
    : _FieldEvaluationGroupState(FieldEvaluationGroupState)
  {}

  std::array<int, 48> _FieldEvaluationGroupState;
};

}; // struct Get

}; // struct FieldEvaluationGroupState

} // namespace sick::srt::multiScan200
