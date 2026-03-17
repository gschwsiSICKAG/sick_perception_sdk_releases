/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file parameterbackup.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0'.
 * Do not edit manually!
 */
#pragma once


namespace sick::multiScan200::v0_9_0::api::rest {

/**
 * @brief Payloads for endpoint /parameterbackup.
*/
struct parameterbackup
{

  constexpr static const char* variableName = "parameterbackup";
  constexpr static const bool isSopasMethod = false;

  /**
   * @brief Reads/transfers the backup file (.json) from/to the device.
   */
  struct Get
  {
  }; // struct Get

}; // struct parameterbackup

} // namespace sick::multiScan200::v0_9_0::api::rest
