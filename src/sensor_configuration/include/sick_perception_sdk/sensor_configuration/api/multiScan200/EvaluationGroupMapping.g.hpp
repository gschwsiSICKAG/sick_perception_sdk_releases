/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file EvaluationGroupMapping.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>
#include <sick_perception_sdk/sensor_configuration/api/NumericRange.hpp>
#include <string>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /EvaluationGroupMapping.
*/
struct SDK_EXPORT EvaluationGroupMapping
{

  constexpr static const char* variableName = "EvaluationGroupMapping";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief Get EvaluationGroupMapping.
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  struct SDK_EXPORT EvaluationGroupMappingItem
  {
    struct SDK_EXPORT Activation
    {
      enum class Type
      {
        Deactivated = 0,
        Always = 1,
        Inputs = 2,
        Telegram = 3,
      };

      Activation() = default;

      explicit Activation(Type Type, std::array<int, 8> Inputs, bool InitialActivationStateTelegram)
        : _Type(Type), _Inputs(Inputs), _InitialActivationStateTelegram(InitialActivationStateTelegram)
      {}

      Type _Type;
      std::array<int, 8> _Inputs;
      bool _InitialActivationStateTelegram;
    };

    EvaluationGroupMappingItem() = default;

    explicit EvaluationGroupMappingItem(std::string Name, NumericRange<1, 48, 1> Id, Activation Activation, std::vector<int> EvalIds)
      : _Name(std::move(Name)), _Id(std::move(Id)), _Activation(Activation), _EvalIds(EvalIds)
    {}

    std::string _Name;
    NumericRange<1, 48, 1> _Id;
    Activation _Activation;
    std::vector<int> _EvalIds;
  };

  Response() = default;

  explicit Response(std::vector<EvaluationGroupMappingItem> EvaluationGroupMapping)
    : _EvaluationGroupMapping(EvaluationGroupMapping)
  {}

  std::vector<EvaluationGroupMappingItem> _EvaluationGroupMapping;
};

}; // struct Get

/**
 * @brief Post EvaluationGroupMapping.

 This function requires at least user level: Authorized Client.
*/
struct SDK_EXPORT Post
{
struct SDK_EXPORT Request
{
  struct SDK_EXPORT EvaluationGroupMappingItem
  {
    struct SDK_EXPORT Activation
    {
      enum class Type
      {
        Deactivated = 0,
        Always = 1,
        Inputs = 2,
        Telegram = 3,
      };

      Activation() = default;

      explicit Activation(Type Type, std::array<int, 8> Inputs, bool InitialActivationStateTelegram)
        : _Type(Type), _Inputs(Inputs), _InitialActivationStateTelegram(InitialActivationStateTelegram)
      {}

      Type _Type;
      std::array<int, 8> _Inputs;
      bool _InitialActivationStateTelegram;
    };

    EvaluationGroupMappingItem() = default;

    explicit EvaluationGroupMappingItem(std::string Name, NumericRange<1, 48, 1> Id, Activation Activation, std::vector<int> EvalIds)
      : _Name(std::move(Name)), _Id(std::move(Id)), _Activation(Activation), _EvalIds(EvalIds)
    {}

    std::string _Name;
    NumericRange<1, 48, 1> _Id;
    Activation _Activation;
    std::vector<int> _EvalIds;
  };

  Request() = default;

  explicit Request(std::vector<EvaluationGroupMappingItem> EvaluationGroupMapping)
    : _EvaluationGroupMapping(EvaluationGroupMapping)
  {}

  std::vector<EvaluationGroupMappingItem> _EvaluationGroupMapping;
};

}; // struct Post

}; // struct EvaluationGroupMapping

} // namespace sick::srt::multiScan200
