/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file EvaluationGroupType.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'picoScan100' version '2.2.0'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::picoScan100 {

/**
 * @brief Payloads for endpoint /EvaluationGroupType.
*/
struct SDK_EXPORT EvaluationGroupType
{

  constexpr static const char* variableName = "EvaluationGroupType";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief Returns the evaluation group type, whether it is a field evaluation or a perpendicular distance field.
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  Response() = default;

  explicit Response(std::array<int, 48> EvaluationGroupType)
    : _EvaluationGroupType(EvaluationGroupType)
  {}

  std::array<int, 48> _EvaluationGroupType;
};

}; // struct Get

}; // struct EvaluationGroupType

} // namespace sick::srt::picoScan100
