/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file ContaminationData.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'LRS4000' version '1.9.0.0R'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::LRS4000 {

/**
 * @brief Payloads for endpoint /ContaminationData.
*/
struct SDK_EXPORT ContaminationData
{

  constexpr static const char* variableName = "ContaminationData";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief Returns the contamination state of all contamination sectors.
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  Response() = default;

  explicit Response(std::array<int, 12> ContaminationData)
    : _ContaminationData(ContaminationData)
  {}

  std::array<int, 12> _ContaminationData;
};

}; // struct Get

}; // struct ContaminationData

} // namespace sick::srt::LRS4000
