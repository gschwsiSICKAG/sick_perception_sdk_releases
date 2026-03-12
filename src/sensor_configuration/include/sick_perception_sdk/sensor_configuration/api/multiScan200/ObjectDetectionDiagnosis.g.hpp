/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file ObjectDetectionDiagnosis.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /ObjectDetectionDiagnosis.
*/
struct SDK_EXPORT ObjectDetectionDiagnosis
{

  constexpr static const char* variableName = "ObjectDetectionDiagnosis";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief Get ObjectDetectionDiagnosis.
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  struct SDK_EXPORT ObjectDetectionDiagnosis
  {
    struct SDK_EXPORT EvaluationDiagnosisListItem
    {
      enum class Diagnosis
      {
        None = 0,
        MinimumObjectSizeTooSmall = 1,
      };

      EvaluationDiagnosisListItem() = default;

      explicit EvaluationDiagnosisListItem(Diagnosis Diagnosis)
        : _Diagnosis(Diagnosis)
      {}

      Diagnosis _Diagnosis;
    };

    ObjectDetectionDiagnosis() = default;

    explicit ObjectDetectionDiagnosis(int Version, int Timestamp, std::vector<EvaluationDiagnosisListItem> EvaluationDiagnosisList)
      : _Version(Version), _Timestamp(Timestamp), _EvaluationDiagnosisList(EvaluationDiagnosisList)
    {}

    int _Version;
    int _Timestamp;
    std::vector<EvaluationDiagnosisListItem> _EvaluationDiagnosisList;
  };

  Response() = default;

  explicit Response(ObjectDetectionDiagnosis ObjectDetectionDiagnosis)
    : _ObjectDetectionDiagnosis(ObjectDetectionDiagnosis)
  {}

  ObjectDetectionDiagnosis _ObjectDetectionDiagnosis;
};

}; // struct Get

}; // struct ObjectDetectionDiagnosis

} // namespace sick::srt::multiScan200
