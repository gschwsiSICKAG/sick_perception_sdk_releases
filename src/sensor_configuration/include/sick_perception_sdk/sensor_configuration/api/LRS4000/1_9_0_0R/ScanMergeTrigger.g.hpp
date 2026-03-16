/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file ScanMergeTrigger.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'LRS4000' version '1.9.0.0R'.
 * Do not edit manually!
 *
 * @note This class represents the payload of a SOPAS method. Do not use in `write_variable()`!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::LRS4000::v1_9_0_0R::api::rest {

/**
 * @brief Payloads for endpoint /ScanMergeTrigger.
*/
struct SDK_EXPORT ScanMergeTrigger
{

  constexpr static const char* methodName = "ScanMergeTrigger";
  constexpr static const bool isSopasMethod = true;

  /**
   * @brief Select a trigger for the Scan Merger functionality.

 This function requires at least user level: Authorized Client.
   */
  struct SDK_EXPORT Post
  {
    struct SDK_EXPORT Request
    {
      enum class ScanMergeTrigger
      {
        Method = 0,
        DigitalInput = 1,
      };

      Request() = default;

      explicit Request(ScanMergeTrigger ScanMergeTrigger)
        : _ScanMergeTrigger(ScanMergeTrigger)
      {}

      ScanMergeTrigger _ScanMergeTrigger;
    };

  }; // struct Post

}; // struct ScanMergeTrigger

} // namespace sick::LRS4000::v1_9_0_0R::api::rest
