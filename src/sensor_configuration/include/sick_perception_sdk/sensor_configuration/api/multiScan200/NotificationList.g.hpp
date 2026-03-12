/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file NotificationList.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>
#include <string>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /NotificationList.
*/
struct SDK_EXPORT NotificationList
{

  constexpr static const char* variableName = "NotificationList";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief List of device status messages which are stored in volatile memory.
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  struct SDK_EXPORT NotificationListItem
  {
    enum class State
    {
      Unknown = 0,
      Active = 1,
      Inactive = 2,
      ActiveBeforeReboot = 3,
    };

    enum class Severity
    {
      Info = 0,
      Warning = 1,
      Error = 2,
      FatalError = 3,
    };

    struct SDK_EXPORT FirstOccurrence
    {
      FirstOccurrence() = default;

      explicit FirstOccurrence(int PowerOnCount, int OpSeconds, int Datetime)
        : _PowerOnCount(PowerOnCount), _OpSeconds(OpSeconds), _Datetime(Datetime)
      {}

      int _PowerOnCount;
      int _OpSeconds;
      int _Datetime;
    };

    struct SDK_EXPORT LastOccurrence
    {
      LastOccurrence() = default;

      explicit LastOccurrence(int PowerOnCount, int OpSeconds, int Datetime)
        : _PowerOnCount(PowerOnCount), _OpSeconds(OpSeconds), _Datetime(Datetime)
      {}

      int _PowerOnCount;
      int _OpSeconds;
      int _Datetime;
    };

    struct SDK_EXPORT LastResolved
    {
      LastResolved() = default;

      explicit LastResolved(int PowerOnCount, int OpSeconds, int Datetime)
        : _PowerOnCount(PowerOnCount), _OpSeconds(OpSeconds), _Datetime(Datetime)
      {}

      int _PowerOnCount;
      int _OpSeconds;
      int _Datetime;
    };

    NotificationListItem() = default;

    explicit NotificationListItem(std::string Id, State State, int NotificationGroup, Severity Severity, FirstOccurrence FirstOccurrence, LastOccurrence LastOccurrence, LastResolved LastResolved, int OccurrenceCount, std::string AdditionalInfo)
      : _Id(std::move(Id)), _State(State), _NotificationGroup(NotificationGroup), _Severity(Severity), _FirstOccurrence(FirstOccurrence), _LastOccurrence(LastOccurrence), _LastResolved(LastResolved), _OccurrenceCount(OccurrenceCount), _AdditionalInfo(std::move(AdditionalInfo))
    {}

    std::string _Id;
    State _State;
    int _NotificationGroup;
    Severity _Severity;
    FirstOccurrence _FirstOccurrence;
    LastOccurrence _LastOccurrence;
    LastResolved _LastResolved;
    int _OccurrenceCount;
    std::string _AdditionalInfo;
  };

  Response() = default;

  explicit Response(std::vector<NotificationListItem> NotificationList)
    : _NotificationList(NotificationList)
  {}

  std::vector<NotificationListItem> _NotificationList;
};

}; // struct Get

}; // struct NotificationList

} // namespace sick::srt::multiScan200
