/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file ContaminationData.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'picoScan150' version '2.2.1'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::picoScan150::v2_2_1::api::rest {

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

      explicit Response(std::vector<int> ContaminationData)
        : _ContaminationData(ContaminationData)
      {}

      std::vector<int> _ContaminationData;
    };

  }; // struct Get

}; // struct ContaminationData

} // namespace sick::picoScan150::v2_2_1::api::rest
