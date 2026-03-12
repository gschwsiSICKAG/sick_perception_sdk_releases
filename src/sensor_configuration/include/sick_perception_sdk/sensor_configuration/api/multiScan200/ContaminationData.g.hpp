/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file ContaminationData.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /ContaminationData.
*/
struct SDK_EXPORT ContaminationData
{

  constexpr static const char* variableName = "ContaminationData";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief States about several contamination segments.
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  Response() = default;

  explicit Response(std::vector<int> ContaminationData)
    : _ContaminationData(ContaminationData)
  {}

  std::vector<int> _ContaminationData;
};

}; // struct Get

}; // struct ContaminationData

} // namespace sick::srt::multiScan200
