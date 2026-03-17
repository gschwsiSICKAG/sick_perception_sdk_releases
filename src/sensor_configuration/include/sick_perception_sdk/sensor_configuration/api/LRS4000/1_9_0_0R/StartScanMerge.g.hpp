/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file StartScanMerge.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'LRS4000' version '1.9.0.0R'.
 * Do not edit manually!
 *
 * @note This class represents the payload of a SOPAS method. Do not use in `write_variable()`!
 */
#pragma once


namespace sick::LRS4000::v1_9_0_0R::api::rest {

/**
 * @brief Payloads for endpoint /StartScanMerge.
*/
struct StartScanMerge
{

  constexpr static const char* methodName = "StartScanMerge";
  constexpr static const bool isSopasMethod = true;

  /**
   * @brief Start the recording of a scan merge when the Scan Merger functionality is enabled. The recording time is limited to 15 or 30 seconds, depending on the selected scan configuration.

 This function requires at least user level: Authorized Client.
   */
  struct Post
  {
  }; // struct Post

}; // struct StartScanMerge

} // namespace sick::LRS4000::v1_9_0_0R::api::rest
