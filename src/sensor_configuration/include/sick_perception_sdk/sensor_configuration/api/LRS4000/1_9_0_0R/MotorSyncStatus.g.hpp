/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file MotorSyncStatus.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'LRS4000' version '1.9.0.0R'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::LRS4000::v1_9_0_0R::api::rest {

/**
 * @brief Payloads for endpoint /MotorSyncStatus.
*/
struct SDK_EXPORT MotorSyncStatus
{

  constexpr static const char* variableName = "MotorSyncStatus";
  constexpr static const bool isSopasMethod = false;

  /**
   * @brief Check if PTP master and slave are synced.

 This function requires at least user level: Authorized Client.
   */
  struct SDK_EXPORT Get
  {
    struct SDK_EXPORT Response
    {
      enum class MotorSyncStatus
      {
        NoClockAndRotSync = 0,
        OnlyTimeSynced = 1,
        Synced = 2,
      };

      Response() = default;

      explicit Response(MotorSyncStatus MotorSyncStatus)
        : _MotorSyncStatus(MotorSyncStatus)
      {}

      MotorSyncStatus _MotorSyncStatus;
    };

  }; // struct Get

}; // struct MotorSyncStatus

} // namespace sick::LRS4000::v1_9_0_0R::api::rest
