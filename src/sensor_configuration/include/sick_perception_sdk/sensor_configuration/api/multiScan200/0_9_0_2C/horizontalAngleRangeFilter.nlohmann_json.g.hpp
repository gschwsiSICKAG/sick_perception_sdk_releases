/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file horizontalAngleRangeFilter.nlohmann_json.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0.2C'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/horizontalAngleRangeFilter.g.hpp>
#include <nlohmann/json.hpp>

namespace sick::multiScan200::v0_9_0_2C::api::rest {

inline void to_json(nlohmann::ordered_json& j, horizontalAngleRangeFilter::Get::Response const& obj)
{
  j = nlohmann::ordered_json{
      {"enable", obj._enable},
      {"thetaStart", obj._thetaStart.value()},
      {"thetaStop", obj._thetaStop.value()},
      {"thetaIndexIncrement", obj._thetaIndexIncrement.value()},
  };
}

inline void from_json(const nlohmann::json& j, horizontalAngleRangeFilter::Get::Response& obj)
{
  j.at("enable").get_to(obj._enable);
  j.at("thetaStart").get_to(obj._thetaStart);
  j.at("thetaStop").get_to(obj._thetaStop);
  j.at("thetaIndexIncrement").get_to(obj._thetaIndexIncrement);
}


inline void to_json(nlohmann::ordered_json& j, horizontalAngleRangeFilter::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"enable", obj._enable},
      {"thetaStart", obj._thetaStart.value()},
      {"thetaStop", obj._thetaStop.value()},
      {"thetaIndexIncrement", obj._thetaIndexIncrement.value()},
  };
}

inline void from_json(const nlohmann::json& j, horizontalAngleRangeFilter::Post::Request& obj)
{
  j.at("enable").get_to(obj._enable);
  j.at("thetaStart").get_to(obj._thetaStart);
  j.at("thetaStop").get_to(obj._thetaStop);
  j.at("thetaIndexIncrement").get_to(obj._thetaIndexIncrement);
}


} // namespace sick::multiScan200::v0_9_0_2C::api::rest
