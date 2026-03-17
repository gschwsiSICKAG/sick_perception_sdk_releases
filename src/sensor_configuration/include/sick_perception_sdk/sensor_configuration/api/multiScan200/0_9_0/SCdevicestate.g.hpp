/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file SCdevicestate.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0'.
 * Do not edit manually!
 */
#pragma once


namespace sick::multiScan200::v0_9_0::api::rest {

/**
 * @brief Payloads for endpoint /SCdevicestate.
*/
struct SCdevicestate
{

  constexpr static const char* variableName = "SCdevicestate";
  constexpr static const bool isSopasMethod = false;

  /**
   * @brief Returns the device state (busy, ready, or error).
   */
  struct Get
  {
    struct Response
    {
      enum class SCdevicestate
      {
        Busy = 0,
        Ready = 1,
        Error = 2,
      };

      Response() = default;

      explicit Response(SCdevicestate SCdevicestate)
        : _SCdevicestate(SCdevicestate)
      {}

      SCdevicestate _SCdevicestate;
    };

  }; // struct Get

}; // struct SCdevicestate

} // namespace sick::multiScan200::v0_9_0::api::rest
