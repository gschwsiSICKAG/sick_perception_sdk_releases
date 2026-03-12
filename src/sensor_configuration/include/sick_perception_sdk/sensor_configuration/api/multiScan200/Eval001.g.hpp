/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file Eval001.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>
#include <sick_perception_sdk/sensor_configuration/api/NumericRange.hpp>
#include <string>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /Eval001.
*/
struct SDK_EXPORT Eval001
{

  constexpr static const char* variableName = "Eval001";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief Get Eval001.
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  struct SDK_EXPORT Eval001
  {
    enum class Source
    {
      Standard = 0,
      Highres6 = 1,
      Highres14 = 2,
    };

    struct SDK_EXPORT EvaluationParamsMaskBasedItem
    {
      EvaluationParamsMaskBasedItem() = default;

      explicit EvaluationParamsMaskBasedItem(NumericRange<1, 100, 80> InfringementThresholdFactor)
        : _InfringementThresholdFactor(std::move(InfringementThresholdFactor))
      {}

      NumericRange<1, 100, 80> _InfringementThresholdFactor;
    };

    struct SDK_EXPORT EvaluationParamsSegmentationBasedItem
    {
      EvaluationParamsSegmentationBasedItem() = default;

      explicit EvaluationParamsSegmentationBasedItem(int SampleParam1)
        : _SampleParam1(SampleParam1)
      {}

      int _SampleParam1;
    };

    struct SDK_EXPORT EvaluationParamsCommonItem
    {
      EvaluationParamsCommonItem() = default;

      explicit EvaluationParamsCommonItem(NumericRange<0, 5000, 200> MinimumObjectSizeHorizontal, NumericRange<0, 5000, 200> MinimumObjectSizeVertical, bool OcclusionHandling, bool TreatMissingDataAsInfringed, NumericRange<1, 10000, 50> TimeForInfringedState, NumericRange<1, 10000, 50> TimeForFreeState, int Reserved3, int Reserved4)
        : _MinimumObjectSizeHorizontal(std::move(MinimumObjectSizeHorizontal)), _MinimumObjectSizeVertical(std::move(MinimumObjectSizeVertical)), _OcclusionHandling(OcclusionHandling), _TreatMissingDataAsInfringed(TreatMissingDataAsInfringed), _TimeForInfringedState(std::move(TimeForInfringedState)), _TimeForFreeState(std::move(TimeForFreeState)), _Reserved3(Reserved3), _Reserved4(Reserved4)
      {}

      NumericRange<0, 5000, 200> _MinimumObjectSizeHorizontal;
      NumericRange<0, 5000, 200> _MinimumObjectSizeVertical;
      bool _OcclusionHandling;
      bool _TreatMissingDataAsInfringed;
      NumericRange<1, 10000, 50> _TimeForInfringedState;
      NumericRange<1, 10000, 50> _TimeForFreeState;
      int _Reserved3;
      int _Reserved4;
    };

    struct SDK_EXPORT EvaluationParamsExitSizeItem
    {
      EvaluationParamsExitSizeItem() = default;

      explicit EvaluationParamsExitSizeItem(bool disableExitSize, NumericRange<0, 100, 70> exitSizeVertical, NumericRange<0, 100, 100> exitSizeHorizontal)
        : _disableExitSize(disableExitSize), _exitSizeVertical(std::move(exitSizeVertical)), _exitSizeHorizontal(std::move(exitSizeHorizontal))
      {}

      bool _disableExitSize;
      NumericRange<0, 100, 70> _exitSizeVertical;
      NumericRange<0, 100, 100> _exitSizeHorizontal;
    };

    Eval001() = default;

    explicit Eval001(int Version, Source Source, std::string Name, int ID, std::vector<EvaluationParamsMaskBasedItem> EvaluationParamsMaskBased, std::vector<EvaluationParamsSegmentationBasedItem> EvaluationParamsSegmentationBased, std::vector<EvaluationParamsCommonItem> EvaluationParamsCommon, std::vector<EvaluationParamsExitSizeItem> EvaluationParamsExitSize, std::vector<int> VolumeList)
      : _Version(Version), _Source(Source), _Name(std::move(Name)), _ID(ID), _EvaluationParamsMaskBased(EvaluationParamsMaskBased), _EvaluationParamsSegmentationBased(EvaluationParamsSegmentationBased), _EvaluationParamsCommon(EvaluationParamsCommon), _EvaluationParamsExitSize(EvaluationParamsExitSize), _VolumeList(VolumeList)
    {}

    int _Version;
    Source _Source;
    std::string _Name;
    int _ID;
    std::vector<EvaluationParamsMaskBasedItem> _EvaluationParamsMaskBased;
    std::vector<EvaluationParamsSegmentationBasedItem> _EvaluationParamsSegmentationBased;
    std::vector<EvaluationParamsCommonItem> _EvaluationParamsCommon;
    std::vector<EvaluationParamsExitSizeItem> _EvaluationParamsExitSize;
    std::vector<int> _VolumeList;
  };

  Response() = default;

  explicit Response(Eval001 Eval001)
    : _Eval001(Eval001)
  {}

  Eval001 _Eval001;
};

}; // struct Get

/**
 * @brief Post Eval001.

 This function requires at least user level: Authorized Client.
*/
struct SDK_EXPORT Post
{
struct SDK_EXPORT Request
{
  enum class Source
  {
    Standard = 0,
    Highres6 = 1,
    Highres14 = 2,
  };

  struct SDK_EXPORT EvaluationParamsMaskBasedItem
  {
    EvaluationParamsMaskBasedItem() = default;

    explicit EvaluationParamsMaskBasedItem(NumericRange<1, 100, 80> InfringementThresholdFactor)
      : _InfringementThresholdFactor(std::move(InfringementThresholdFactor))
    {}

    NumericRange<1, 100, 80> _InfringementThresholdFactor;
  };

  struct SDK_EXPORT EvaluationParamsSegmentationBasedItem
  {
    EvaluationParamsSegmentationBasedItem() = default;

    explicit EvaluationParamsSegmentationBasedItem(int SampleParam1)
      : _SampleParam1(SampleParam1)
    {}

    int _SampleParam1;
  };

  struct SDK_EXPORT EvaluationParamsCommonItem
  {
    EvaluationParamsCommonItem() = default;

    explicit EvaluationParamsCommonItem(NumericRange<0, 5000, 200> MinimumObjectSizeHorizontal, NumericRange<0, 5000, 200> MinimumObjectSizeVertical, bool OcclusionHandling, bool TreatMissingDataAsInfringed, NumericRange<1, 10000, 50> TimeForInfringedState, NumericRange<1, 10000, 50> TimeForFreeState, int Reserved3, int Reserved4)
      : _MinimumObjectSizeHorizontal(std::move(MinimumObjectSizeHorizontal)), _MinimumObjectSizeVertical(std::move(MinimumObjectSizeVertical)), _OcclusionHandling(OcclusionHandling), _TreatMissingDataAsInfringed(TreatMissingDataAsInfringed), _TimeForInfringedState(std::move(TimeForInfringedState)), _TimeForFreeState(std::move(TimeForFreeState)), _Reserved3(Reserved3), _Reserved4(Reserved4)
    {}

    NumericRange<0, 5000, 200> _MinimumObjectSizeHorizontal;
    NumericRange<0, 5000, 200> _MinimumObjectSizeVertical;
    bool _OcclusionHandling;
    bool _TreatMissingDataAsInfringed;
    NumericRange<1, 10000, 50> _TimeForInfringedState;
    NumericRange<1, 10000, 50> _TimeForFreeState;
    int _Reserved3;
    int _Reserved4;
  };

  struct SDK_EXPORT EvaluationParamsExitSizeItem
  {
    EvaluationParamsExitSizeItem() = default;

    explicit EvaluationParamsExitSizeItem(bool disableExitSize, NumericRange<0, 100, 70> exitSizeVertical, NumericRange<0, 100, 100> exitSizeHorizontal)
      : _disableExitSize(disableExitSize), _exitSizeVertical(std::move(exitSizeVertical)), _exitSizeHorizontal(std::move(exitSizeHorizontal))
    {}

    bool _disableExitSize;
    NumericRange<0, 100, 70> _exitSizeVertical;
    NumericRange<0, 100, 100> _exitSizeHorizontal;
  };

  Request() = default;

  explicit Request(int Version, Source Source, std::string Name, int ID, std::vector<EvaluationParamsMaskBasedItem> EvaluationParamsMaskBased, std::vector<EvaluationParamsSegmentationBasedItem> EvaluationParamsSegmentationBased, std::vector<EvaluationParamsCommonItem> EvaluationParamsCommon, std::vector<EvaluationParamsExitSizeItem> EvaluationParamsExitSize, std::vector<int> VolumeList)
    : _Version(Version), _Source(Source), _Name(std::move(Name)), _ID(ID), _EvaluationParamsMaskBased(EvaluationParamsMaskBased), _EvaluationParamsSegmentationBased(EvaluationParamsSegmentationBased), _EvaluationParamsCommon(EvaluationParamsCommon), _EvaluationParamsExitSize(EvaluationParamsExitSize), _VolumeList(VolumeList)
  {}

  int _Version;
  Source _Source;
  std::string _Name;
  int _ID;
  std::vector<EvaluationParamsMaskBasedItem> _EvaluationParamsMaskBased;
  std::vector<EvaluationParamsSegmentationBasedItem> _EvaluationParamsSegmentationBased;
  std::vector<EvaluationParamsCommonItem> _EvaluationParamsCommon;
  std::vector<EvaluationParamsExitSizeItem> _EvaluationParamsExitSize;
  std::vector<int> _VolumeList;
};

}; // struct Post

}; // struct Eval001

} // namespace sick::srt::multiScan200
