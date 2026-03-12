/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file ContaminationActiveSectors.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /ContaminationActiveSectors.
*/
struct SDK_EXPORT ContaminationActiveSectors
{

  constexpr static const char* variableName = "ContaminationActiveSectors";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief Element i is true, if the sector result i is included in the computation of the contamination results and false otherwise.
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  Response() = default;

  explicit Response(std::vector<bool> ContaminationActiveSectors)
    : _ContaminationActiveSectors(ContaminationActiveSectors)
  {}

  std::vector<bool> _ContaminationActiveSectors;
};

}; // struct Get

}; // struct ContaminationActiveSectors

} // namespace sick::srt::multiScan200
