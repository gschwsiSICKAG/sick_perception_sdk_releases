/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file CidVersion.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /CidVersion.
*/
struct SDK_EXPORT CidVersion
{

  constexpr static const char* variableName = "CidVersion";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief Version of communication interface description.
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  struct SDK_EXPORT CidVersionStruct
  {
    enum class VersionClassifier
    {
      C = 0,
      A = 1,
      B = 2,
      R = 3,
      S = 4,
    };

    CidVersionStruct() = default;

    explicit CidVersionStruct(int MajorVersion, int MinorVersion, int PatchVersion, int BuildNumber, VersionClassifier VersionClassifier)
      : _MajorVersion(MajorVersion), _MinorVersion(MinorVersion), _PatchVersion(PatchVersion), _BuildNumber(BuildNumber), _VersionClassifier(VersionClassifier)
    {}

    int _MajorVersion;
    int _MinorVersion;
    int _PatchVersion;
    int _BuildNumber;
    VersionClassifier _VersionClassifier;
  };

  Response() = default;

  explicit Response(CidVersionStruct CidVersionStruct)
    : _CidVersionStruct(CidVersionStruct)
  {}

  CidVersionStruct _CidVersionStruct;
};

}; // struct Get

}; // struct CidVersion

} // namespace sick::srt::multiScan200
