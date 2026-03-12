/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file EMsgInfo.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>
#include <string>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /EMsgInfo.
*/
struct SDK_EXPORT EMsgInfo
{

  constexpr static const char* variableName = "EMsgInfo";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief Info messages which are stored in volatile memory. They are informations and do not indicate an error condition.
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  struct SDK_EXPORT EMsgInfoItem
  {
    struct SDK_EXPORT FirstTime
    {
      FirstTime() = default;

      explicit FirstTime(int PwrOnCnt, int OpSecs, int TimeOccur)
        : _PwrOnCnt(PwrOnCnt), _OpSecs(OpSecs), _TimeOccur(TimeOccur)
      {}

      int _PwrOnCnt;
      int _OpSecs;
      int _TimeOccur;
    };

    struct SDK_EXPORT LastTime
    {
      LastTime() = default;

      explicit LastTime(int PwrOnCnt, int OpSecs, int TimeOccur)
        : _PwrOnCnt(PwrOnCnt), _OpSecs(OpSecs), _TimeOccur(TimeOccur)
      {}

      int _PwrOnCnt;
      int _OpSecs;
      int _TimeOccur;
    };

    EMsgInfoItem() = default;

    explicit EMsgInfoItem(int ErrorId, int ErrorState, FirstTime FirstTime, LastTime LastTime, int NumberOccurance, int ErrReserved, std::string ExtInfo)
      : _ErrorId(ErrorId), _ErrorState(ErrorState), _FirstTime(FirstTime), _LastTime(LastTime), _NumberOccurance(NumberOccurance), _ErrReserved(ErrReserved), _ExtInfo(std::move(ExtInfo))
    {}

    int _ErrorId;
    int _ErrorState;
    FirstTime _FirstTime;
    LastTime _LastTime;
    int _NumberOccurance;
    int _ErrReserved;
    std::string _ExtInfo;
  };

  Response() = default;

  explicit Response(std::array<EMsgInfoItem, 25> EMsgInfo)
    : _EMsgInfo(EMsgInfo)
  {}

  std::array<EMsgInfoItem, 25> _EMsgInfo;
};

}; // struct Get

}; // struct EMsgInfo

} // namespace sick::srt::multiScan200
