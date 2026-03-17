/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file ScanMergerSource.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'LRS4000' version '1.9.0.0R'.
 * Do not edit manually!
 *
 * @note This class represents the payload of a SOPAS method. Do not use in `write_variable()`!
 */
#pragma once


namespace sick::LRS4000::v1_9_0_0R::api::rest {

/**
 * @brief Payloads for endpoint /ScanMergerSource.
*/
struct ScanMergerSource
{

  constexpr static const char* methodName = "ScanMergerSource";
  constexpr static const bool isSopasMethod = true;

  /**
   * @brief Select the source of the rotation that should be used to create the 3D point cloud.

 This function requires at least user level: Authorized Client.
   */
  struct Post
  {
    struct Request
    {
      enum class ScanMergerSource
      {
        Imu = 0,
        Encoder = 1,
      };

      Request() = default;

      explicit Request(ScanMergerSource ScanMergerSource)
        : _ScanMergerSource(ScanMergerSource)
      {}

      ScanMergerSource _ScanMergerSource;
    };

  }; // struct Post

}; // struct ScanMergerSource

} // namespace sick::LRS4000::v1_9_0_0R::api::rest
