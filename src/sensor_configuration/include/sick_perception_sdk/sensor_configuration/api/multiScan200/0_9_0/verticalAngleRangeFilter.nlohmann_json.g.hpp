/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file verticalAngleRangeFilter.nlohmann_json.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0/verticalAngleRangeFilter.g.hpp>
#include <nlohmann/json.hpp>

namespace sick::multiScan200::v0_9_0::api::rest {

inline void to_json(nlohmann::ordered_json& j, verticalAngleRangeFilter::Get::Response const& obj)
{
  j = nlohmann::ordered_json{
      {"enable", obj._enable},
      {"outerRoiStartAngle", obj._outerRoiStartAngle.value()},
      {"outerRoiStopAngle", obj._outerRoiStopAngle.value()},
      {"innerRoiStartAngle", obj._innerRoiStartAngle.value()},
      {"innerRoiStopAngle", obj._innerRoiStopAngle.value()},
      {"outerRoiIndexIncrement", obj._outerRoiIndexIncrement.value()},
      {"innerRoiIndexIncrement", obj._innerRoiIndexIncrement.value()},
  };
}

inline void from_json(const nlohmann::json& j, verticalAngleRangeFilter::Get::Response& obj)
{
  j.at("enable").get_to(obj._enable);
  j.at("outerRoiStartAngle").get_to(obj._outerRoiStartAngle);
  j.at("outerRoiStopAngle").get_to(obj._outerRoiStopAngle);
  j.at("innerRoiStartAngle").get_to(obj._innerRoiStartAngle);
  j.at("innerRoiStopAngle").get_to(obj._innerRoiStopAngle);
  j.at("outerRoiIndexIncrement").get_to(obj._outerRoiIndexIncrement);
  j.at("innerRoiIndexIncrement").get_to(obj._innerRoiIndexIncrement);
}


inline void to_json(nlohmann::ordered_json& j, verticalAngleRangeFilter::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"enable", obj._enable},
      {"outerRoiStartAngle", obj._outerRoiStartAngle.value()},
      {"outerRoiStopAngle", obj._outerRoiStopAngle.value()},
      {"innerRoiStartAngle", obj._innerRoiStartAngle.value()},
      {"innerRoiStopAngle", obj._innerRoiStopAngle.value()},
      {"outerRoiIndexIncrement", obj._outerRoiIndexIncrement.value()},
      {"innerRoiIndexIncrement", obj._innerRoiIndexIncrement.value()},
  };
}

inline void from_json(const nlohmann::json& j, verticalAngleRangeFilter::Post::Request& obj)
{
  j.at("enable").get_to(obj._enable);
  j.at("outerRoiStartAngle").get_to(obj._outerRoiStartAngle);
  j.at("outerRoiStopAngle").get_to(obj._outerRoiStopAngle);
  j.at("innerRoiStartAngle").get_to(obj._innerRoiStartAngle);
  j.at("innerRoiStopAngle").get_to(obj._innerRoiStopAngle);
  j.at("outerRoiIndexIncrement").get_to(obj._outerRoiIndexIncrement);
  j.at("innerRoiIndexIncrement").get_to(obj._innerRoiIndexIncrement);
}


} // namespace sick::multiScan200::v0_9_0::api::rest
