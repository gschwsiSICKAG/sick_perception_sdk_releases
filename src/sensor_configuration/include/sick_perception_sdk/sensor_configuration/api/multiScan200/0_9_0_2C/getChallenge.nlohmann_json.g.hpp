/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file getChallenge.nlohmann_json.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0.2C'.
 * Do not edit manually!
 *
 * @note This class represents the payload of a SOPAS method. Do not use in `write_variable()`!
 */
#pragma once

#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/getChallenge.g.hpp>
#include <nlohmann/json.hpp>

namespace sick::multiScan200::v0_9_0_2C::api::rest {

inline void to_json(nlohmann::ordered_json& j, getChallenge::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"user", obj._user},
  };
}

inline void from_json(const nlohmann::json& j, getChallenge::Post::Request& obj)
{
  j.at("user").get_to(obj._user);
}


} // namespace sick::multiScan200::v0_9_0_2C::api::rest
