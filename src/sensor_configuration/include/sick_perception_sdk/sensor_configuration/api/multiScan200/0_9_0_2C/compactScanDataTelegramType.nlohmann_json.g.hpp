/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file compactScanDataTelegramType.nlohmann_json.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0.2C'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/compactScanDataTelegramType.g.hpp>
#include <nlohmann/json.hpp>

namespace sick::multiScan200::v0_9_0_2C::api::rest {

inline void to_json(nlohmann::ordered_json& j, compactScanDataTelegramType::Get::Response const& obj)
{
  j = obj._compactScanDataTelegramType;
}

inline void from_json(const nlohmann::json& j, compactScanDataTelegramType::Get::Response& obj)
{
  j.get_to(obj._compactScanDataTelegramType);
}


inline void to_json(nlohmann::ordered_json& j, compactScanDataTelegramType::Post::Request const& obj)
{
  j = obj._compactScanDataTelegramType;
}

inline void from_json(const nlohmann::json& j, compactScanDataTelegramType::Post::Request& obj)
{
  j.get_to(obj._compactScanDataTelegramType);
}


} // namespace sick::multiScan200::v0_9_0_2C::api::rest
