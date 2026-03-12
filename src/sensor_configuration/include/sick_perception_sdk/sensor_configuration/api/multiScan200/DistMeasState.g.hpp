/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file DistMeasState.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /DistMeasState.
*/
struct SDK_EXPORT DistMeasState
{

  constexpr static const char* variableName = "DistMeasState";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief State of internal state machine.
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  struct SDK_EXPORT DistMeasState
  {
    enum class State
    {
      TxDistmeasstateUndefined = 0,
      TxDistmeasstateInit = 1,
      TxDistmeasstateCfg = 2,
      TxDistmeasstateIdle = 3,
      TxDistmeasstateRotate = 4,
      TxDistmeasstateReady2d = 6,
      TxDistmeasstateMeasure2d = 7,
      TxDistmeasstateUpdatefw = 8,
      TxDistmeasstateProd = 9,
      TxDistmeasstateError = 10,
      TxDistmeasstateWarmup = 12,
      TxDistmeasstateBoot = 13,
      TxDistmeasstateStandby = 17,
      TxDistmeasstatePwrsave = 18,
      TxDistmeasstateMeasstop = 19,
      TxDistmeasstateMaxstate = 22,
    };

    DistMeasState() = default;

    explicit DistMeasState(State State)
      : _State(State)
    {}

    State _State;
  };

  Response() = default;

  explicit Response(DistMeasState DistMeasState)
    : _DistMeasState(DistMeasState)
  {}

  DistMeasState _DistMeasState;
};

}; // struct Get

}; // struct DistMeasState

} // namespace sick::srt::multiScan200
