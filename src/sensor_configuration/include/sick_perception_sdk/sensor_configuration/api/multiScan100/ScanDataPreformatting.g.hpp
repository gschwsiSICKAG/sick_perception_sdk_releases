/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file ScanDataPreformatting.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan100' version '2.4.1'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::multiScan100 {

/**
 * @brief Payloads for endpoint /ScanDataPreformatting.
*/
struct SDK_EXPORT ScanDataPreformatting
{

  constexpr static const char* variableName = "ScanDataPreformatting";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief Reordering of the different layers in azimuth. In Raw mode no reordering is performed, in Rectified mode the layers are reordered such that the azimuth angle range of the different layers match as good.
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  enum class ScanDataPreformatting
  {
    Raw = 1,
    Rectified = 2,
  };

  Response() = default;

  explicit Response(ScanDataPreformatting ScanDataPreformatting)
    : _ScanDataPreformatting(ScanDataPreformatting)
  {}

  ScanDataPreformatting _ScanDataPreformatting;
};

}; // struct Get

/**
 * @brief Reordering of the different layers in azimuth. In Raw mode no reordering is performed, in Rectified mode the layers are reordered such that the azimuth angle range of the different layers match as good.

 This function requires at least user level: Authorized Client.
*/
struct SDK_EXPORT Post
{
struct SDK_EXPORT Request
{
  enum class ScanDataPreformatting
  {
    Raw = 1,
    Rectified = 2,
  };

  Request() = default;

  explicit Request(ScanDataPreformatting ScanDataPreformatting)
    : _ScanDataPreformatting(ScanDataPreformatting)
  {}

  ScanDataPreformatting _ScanDataPreformatting;
};

}; // struct Post

}; // struct ScanDataPreformatting

} // namespace sick::srt::multiScan100
