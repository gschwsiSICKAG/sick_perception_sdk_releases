/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file FieldEvaluationResult.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'LRS4000' version '1.9.0.0R'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::LRS4000::v1_9_0_0R::api::rest {

/**
 * @brief Payloads for endpoint /FieldEvaluationResult.
*/
struct SDK_EXPORT FieldEvaluationResult
{

  constexpr static const char* variableName = "FieldEvaluationResult";
  constexpr static const bool isSopasMethod = false;

  /**
   * @brief Returns the state of all possible fields.
   */
  struct SDK_EXPORT Get
  {
    struct SDK_EXPORT Response
    {
      struct SDK_EXPORT FieldEvaluationResult
      {
        struct SDK_EXPORT EvaluationResultListItem
        {
          enum class State
          {
            NotConfigured = 0,
            Inactive = 1,
            Free = 2,
            DetectingInfringed = 3,
            Infringed = 4,
            DetectingFree = 5,
          };

          struct SDK_EXPORT PositionsItem
          {
            PositionsItem() = default;

            explicit PositionsItem(int x, int y)
              : _x(x), _y(y)
            {}

            int _x;
            int _y;
          };

          EvaluationResultListItem() = default;

          explicit EvaluationResultListItem(State State, std::vector<PositionsItem> Positions)
            : _State(State), _Positions(Positions)
          {}

          State _State;
          std::vector<PositionsItem> _Positions;
        };

        FieldEvaluationResult() = default;

        explicit FieldEvaluationResult(int Version, int Timestamp, std::vector<EvaluationResultListItem> EvaluationResultList)
          : _Version(Version), _Timestamp(Timestamp), _EvaluationResultList(EvaluationResultList)
        {}

        int _Version;
        int _Timestamp;
        std::vector<EvaluationResultListItem> _EvaluationResultList;
      };

      Response() = default;

      explicit Response(FieldEvaluationResult FieldEvaluationResult)
        : _FieldEvaluationResult(FieldEvaluationResult)
      {}

      FieldEvaluationResult _FieldEvaluationResult;
    };

  }; // struct Get

}; // struct FieldEvaluationResult

} // namespace sick::LRS4000::v1_9_0_0R::api::rest
