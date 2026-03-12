/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file SopasInfo.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /SopasInfo.
*/
struct SDK_EXPORT SopasInfo
{

  constexpr static const char* variableName = "SopasInfo";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief Configuration and all supported SOPAS features by this device.
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  enum class SegmentSize
  {
    Segsize4 = 0,
    Segsize8 = 1,
    Segsize16 = 2,
    Segsize64 = 3,
    Segsize256 = 4,
    Segsize1024 = 5,
    Segsize4096 = 6,
    Segsize16384 = 7,
  };

  enum class hubFunctionality
  {
    Nosubdevices = 0,
    Subdeviceswithdetails = 1,
    Subdeviceswithmaxaddr = 2,
    Subdevicesextended = 3,
  };

  Response() = default;

  explicit Response(bool CIDUploadSupported, bool ShortUDDUploadSupported, bool PMDUploadSupported, bool LocationNameExists, SegmentSize SegmentSize, bool SupportsEventPolling, bool hasProcIndex, bool CIDChecksumProvided, bool CheckPasswordProvided, hubFunctionality hubFunctionality, bool JarUploadSupported, bool hasFirmwareDownloadAlgorithm, bool SimultaneousMethodsSupport, bool HashValueSupport, bool HasAdditionalTimeout, bool BulkTransferSupported, bool isSystemCapable, bool SystemSDDUploadSupported)
    : _CIDUploadSupported(CIDUploadSupported), _ShortUDDUploadSupported(ShortUDDUploadSupported), _PMDUploadSupported(PMDUploadSupported), _LocationNameExists(LocationNameExists), _SegmentSize(SegmentSize), _SupportsEventPolling(SupportsEventPolling), _hasProcIndex(hasProcIndex), _CIDChecksumProvided(CIDChecksumProvided), _CheckPasswordProvided(CheckPasswordProvided), _hubFunctionality(hubFunctionality), _JarUploadSupported(JarUploadSupported), _hasFirmwareDownloadAlgorithm(hasFirmwareDownloadAlgorithm), _SimultaneousMethodsSupport(SimultaneousMethodsSupport), _HashValueSupport(HashValueSupport), _HasAdditionalTimeout(HasAdditionalTimeout), _BulkTransferSupported(BulkTransferSupported), _isSystemCapable(isSystemCapable), _SystemSDDUploadSupported(SystemSDDUploadSupported)
  {}

  bool _CIDUploadSupported;
  bool _ShortUDDUploadSupported;
  bool _PMDUploadSupported;
  bool _LocationNameExists;
  SegmentSize _SegmentSize;
  bool _SupportsEventPolling;
  bool _hasProcIndex;
  bool _CIDChecksumProvided;
  bool _CheckPasswordProvided;
  hubFunctionality _hubFunctionality;
  bool _JarUploadSupported;
  bool _hasFirmwareDownloadAlgorithm;
  bool _SimultaneousMethodsSupport;
  bool _HashValueSupport;
  bool _HasAdditionalTimeout;
  bool _BulkTransferSupported;
  bool _isSystemCapable;
  bool _SystemSDDUploadSupported;
};

}; // struct Get

}; // struct SopasInfo

} // namespace sick::srt::multiScan200
