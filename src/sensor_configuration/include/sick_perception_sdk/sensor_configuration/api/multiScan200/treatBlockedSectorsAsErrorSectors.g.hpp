/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file treatBlockedSectorsAsErrorSectors.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /treatBlockedSectorsAsErrorSectors.
*/
struct SDK_EXPORT treatBlockedSectorsAsErrorSectors
{

  constexpr static const char* variableName = "treatBlockedSectorsAsErrorSectors";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief If true, interpret blocked sectors as error sectors for contamination strategy evaluation.
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  Response() = default;

  explicit Response(bool treatBlockedSectorsAsErrorSectors)
    : _treatBlockedSectorsAsErrorSectors(treatBlockedSectorsAsErrorSectors)
  {}

  bool _treatBlockedSectorsAsErrorSectors;
};

}; // struct Get

/**
 * @brief If true, interpret blocked sectors as error sectors for contamination strategy evaluation.

 This function requires at least user level: Authorized Client.
*/
struct SDK_EXPORT Post
{
struct SDK_EXPORT Request
{
  Request() = default;

  explicit Request(bool treatBlockedSectorsAsErrorSectors)
    : _treatBlockedSectorsAsErrorSectors(treatBlockedSectorsAsErrorSectors)
  {}

  bool _treatBlockedSectorsAsErrorSectors;
};

}; // struct Post

}; // struct treatBlockedSectorsAsErrorSectors

} // namespace sick::srt::multiScan200
