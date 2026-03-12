/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file FDSignature.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>
#include <string>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /FDSignature.
*/
struct SDK_EXPORT FDSignature
{

  constexpr static const char* variableName = "FDSignature";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief Defines the Signature of the device. Variable is read only and can only be changed by writing an encrypted signature using the method WriteSignature.
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  Response() = default;

  explicit Response(std::string FDSignature)
    : _FDSignature(std::move(FDSignature))
  {}

  std::string _FDSignature;
};

}; // struct Get

}; // struct FDSignature

} // namespace sick::srt::multiScan200
