/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file GetDescription.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 *
 * @note This class represents the payload of a SOPAS method. Do not use in `write_variable()`!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /GetDescription.
*/
struct SDK_EXPORT GetDescription
{

  constexpr static const char* methodName = "GetDescription";
  constexpr static const bool isSopasMethod = true;

/**
 * @brief Post GetDescription.
*/
struct SDK_EXPORT Post
{
struct SDK_EXPORT Request
{
  enum class eType
  {
    Cid = 1,
    Shortudd = 2,
    Pmd = 3,
    Jar = 4,
    Cidpmd = 5,
    Eip2pmd = 6,
    Chinfo = 7,
    Avc = 8,
    Profibus = 9,
    Profibus2 = 10,
    Canopen = 11,
    Ecatpmd = 12,
    Profibus3 = 13,
  };

  Request() = default;

  explicit Request(eType eType, int uiSegmentNumber)
    : _eType(eType), _uiSegmentNumber(uiSegmentNumber)
  {}

  eType _eType;
  int _uiSegmentNumber;
};

struct SDK_EXPORT Response
{
  enum class eState
  {
    Typenotsupported = 0,
    Segmentoutofrange = 1,
    Firstsegment = 2,
    Normalsegment = 3,
    Lastsegment = 4,
  };

  Response() = default;

  explicit Response(eState eState, int uiSegmentNumber, std::vector<int> aByteStream)
    : _eState(eState), _uiSegmentNumber(uiSegmentNumber), _aByteStream(aByteStream)
  {}

  eState _eState;
  int _uiSegmentNumber;
  std::vector<int> _aByteStream;
};

}; // struct Post

}; // struct GetDescription

} // namespace sick::srt::multiScan200
