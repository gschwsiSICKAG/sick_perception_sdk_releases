/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file ProgramDataTransferSize.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /ProgramDataTransferSize.
*/
struct SDK_EXPORT ProgramDataTransferSize
{

  constexpr static const char* variableName = "ProgramDataTransferSize";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief The number of how many bytes is accepted by the ProgramData method for each transfer.
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  Response() = default;

  explicit Response(int ProgramDataTransferSize)
    : _ProgramDataTransferSize(ProgramDataTransferSize)
  {}

  int _ProgramDataTransferSize;
};

}; // struct Get

}; // struct ProgramDataTransferSize

} // namespace sick::srt::multiScan200
