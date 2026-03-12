/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file EMsgFatal.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>
#include <string>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /EMsgFatal.
*/
struct SDK_EXPORT EMsgFatal
{

  constexpr static const char* variableName = "EMsgFatal";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief Error message on level FATAL which is stored in non volatile memory (EEPROM) TODO: storing.
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  struct SDK_EXPORT EMsgFatalItem
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

    EMsgFatalItem() = default;

    explicit EMsgFatalItem(int ErrorId, int ErrorState, FirstTime FirstTime, LastTime LastTime, int NumberOccurance, int ErrReserved, std::string ExtInfo)
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

  explicit Response(std::array<EMsgFatalItem, 10> EMsgFatal)
    : _EMsgFatal(EMsgFatal)
  {}

  std::array<EMsgFatalItem, 10> _EMsgFatal;
};

}; // struct Get

}; // struct EMsgFatal

} // namespace sick::srt::multiScan200
