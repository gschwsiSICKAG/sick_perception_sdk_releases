/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file EtherLinkState.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /EtherLinkState.
*/
struct SDK_EXPORT EtherLinkState
{

  constexpr static const char* variableName = "EtherLinkState";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief Linkstate of the Cable, up or down.
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  Response() = default;

  explicit Response(bool EtherLinkState)
    : _EtherLinkState(EtherLinkState)
  {}

  bool _EtherLinkState;
};

}; // struct Get

}; // struct EtherLinkState

} // namespace sick::srt::multiScan200
