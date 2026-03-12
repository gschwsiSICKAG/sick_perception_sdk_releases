/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file EMsgDebug.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>
#include <string>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /EMsgDebug.
*/
struct SDK_EXPORT EMsgDebug
{

  constexpr static const char* variableName = "EMsgDebug";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief Error messages or infos on level DEBUG which are stored in volatile memory. They are used as debugging aids.
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  struct SDK_EXPORT EMsgDebugItem
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

    EMsgDebugItem() = default;

    explicit EMsgDebugItem(int ErrorId, int ErrorState, FirstTime FirstTime, LastTime LastTime, int NumberOccurance, int ErrReserved, std::string ExtInfo)
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

  explicit Response(std::array<EMsgDebugItem, 25> EMsgDebug)
    : _EMsgDebug(EMsgDebug)
  {}

  std::array<EMsgDebugItem, 25> _EMsgDebug;
};

}; // struct Get

}; // struct EMsgDebug

} // namespace sick::srt::multiScan200
