/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file SyncPhase.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'LRS4000' version '1.9.0.0R'.
 * Do not edit manually!
 *
 * @note This class represents the payload of a SOPAS method. Do not use in `write_variable()`!
 */
#pragma once

#include <sick_perception_sdk/sensor_configuration/api/NumericRange.hpp>

namespace sick::LRS4000::v1_9_0_0R::api::rest {

/**
 * @brief Payloads for endpoint /SyncPhase.
*/
struct SyncPhase
{

  constexpr static const char* methodName = "SyncPhase";
  constexpr static const bool isSopasMethod = true;

  /**
   * @brief synchronisation phase difference between master and slave.

 This function requires at least user level: Authorized Client.
   */
  struct Post
  {
    struct Request
    {
      Request() = default;

      explicit Request(NumericRange<-180, 180, 180> SyncPhase)
        : _SyncPhase(std::move(SyncPhase))
      {}

      NumericRange<-180, 180, 180> _SyncPhase;
    };

  }; // struct Post

}; // struct SyncPhase

} // namespace sick::LRS4000::v1_9_0_0R::api::rest
