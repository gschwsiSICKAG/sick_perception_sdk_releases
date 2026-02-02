/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file EvaluationsToLog.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan100' version '2.4.1'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::multiScan100 {

/**
 * @brief Payloads for endpoint /EvaluationsToLog.
*/
struct SDK_EXPORT EvaluationsToLog
{

  constexpr static const char* variableName = "EvaluationsToLog";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief Returns/sets the evaluations which are logged (if they are in use).
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  Response() = default;

  explicit Response(std::array<bool, 48> EvaluationsToLog)
    : _EvaluationsToLog(EvaluationsToLog)
  {}

  std::array<bool, 48> _EvaluationsToLog;
};

}; // struct Get

/**
 * @brief Returns/sets the evaluations which are logged (if they are in use).

 This function requires at least user level: Authorized Client.
*/
struct SDK_EXPORT Post
{
struct SDK_EXPORT Request
{
  Request() = default;

  explicit Request(std::array<bool, 48> EvaluationsToLog)
    : _EvaluationsToLog(EvaluationsToLog)
  {}

  std::array<bool, 48> _EvaluationsToLog;
};

}; // struct Post

}; // struct EvaluationsToLog

} // namespace sick::srt::multiScan100
