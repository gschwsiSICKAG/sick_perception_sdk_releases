/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file ContaminationActiveSectors.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'LRS4000' version '1.9.0.0R'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::LRS4000::v1_9_0_0R::api::rest {

/**
 * @brief Payloads for endpoint /ContaminationActiveSectors.
*/
struct SDK_EXPORT ContaminationActiveSectors
{

  constexpr static const char* variableName = "ContaminationActiveSectors";
  constexpr static const bool isSopasMethod = false;

  /**
   * @brief Returns the active contamination sectors. Starts with right backside of the sensor when looking to the device on topside view and continues counterclockwise.
   */
  struct SDK_EXPORT Get
  {
    struct SDK_EXPORT Response
    {
      Response() = default;

      explicit Response(std::array<bool, 12> ContaminationActiveSectors)
        : _ContaminationActiveSectors(ContaminationActiveSectors)
      {}

      std::array<bool, 12> _ContaminationActiveSectors;
    };

  }; // struct Get

}; // struct ContaminationActiveSectors

} // namespace sick::LRS4000::v1_9_0_0R::api::rest
