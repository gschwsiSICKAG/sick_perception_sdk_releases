/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file PortConfiguration.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'picoScan100' version '2.2.0'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>
#include <sick_perception_sdk/sensor_configuration/api/NumericRange.hpp>
#include <string>

namespace sick::srt::picoScan100 {

/**
 * @brief Payloads for endpoint /PortConfiguration.
*/
struct SDK_EXPORT PortConfiguration
{

  constexpr static const char* variableName = "PortConfiguration";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief Returns/sets the port configuration of all I/Os.
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  struct SDK_EXPORT PortConfigurationItem
  {
    enum class PortType
    {
      Input = 0,
      Output = 1,
      Encoder = 2,
    };

    enum class EncoderPortType
    {
      None = 0,
      EncoderA = 1,
      EncoderB = 2,
      Aux1 = 3,
      Aux2 = 4,
    };

    struct SDK_EXPORT InputSettings
    {
      enum class Logic
      {
        ActiveHigh = 0,
        ActiveLow = 1,
      };

      enum class Sensitivity
      {
        Edge = 0,
        Level = 1,
      };

      InputSettings() = default;

      explicit InputSettings(Logic Logic, NumericRange<1, 1000, 10> Debounce, Sensitivity Sensitivity, int Reserved1, int Reserved2)
        : _Logic(Logic), _Debounce(std::move(Debounce)), _Sensitivity(Sensitivity), _Reserved1(Reserved1), _Reserved2(Reserved2)
      {}

      Logic _Logic;
      NumericRange<1, 1000, 10> _Debounce;
      Sensitivity _Sensitivity;
      int _Reserved1;
      int _Reserved2;
    };

    struct SDK_EXPORT OutputSettings
    {
      enum class Logic
      {
        ActiveHigh = 0,
        ActiveLow = 1,
      };

      enum class OutputMode
      {
        Pnp = 0,
        Npn = 1,
        PushPull = 2,
      };

      enum class RestartType
      {
        RestartImmedate = 0,
        RestartTime = 1,
        RestartInput = 2,
      };

      enum class Combination
      {
        And = 0,
        Or = 1,
        Xor = 2,
      };

      struct SDK_EXPORT SourcesItem
      {
        SourcesItem() = default;

        explicit SourcesItem(std::string Name, bool Invert, int Reserved5, int Reserved6)
          : _Name(std::move(Name)), _Invert(Invert), _Reserved5(Reserved5), _Reserved6(Reserved6)
        {}

        std::string _Name;
        bool _Invert;
        int _Reserved5;
        int _Reserved6;
      };

      OutputSettings() = default;

      explicit OutputSettings(Logic Logic, OutputMode OutputMode, RestartType RestartType, NumericRange<20, 600000, 200> RestartTime, NumericRange<1, 8, 1> RestartInput, Combination Combination, int Reserved3, int Reserved4, std::vector<SourcesItem> Sources)
        : _Logic(Logic), _OutputMode(OutputMode), _RestartType(RestartType), _RestartTime(std::move(RestartTime)), _RestartInput(std::move(RestartInput)), _Combination(Combination), _Reserved3(Reserved3), _Reserved4(Reserved4), _Sources(Sources)
      {}

      Logic _Logic;
      OutputMode _OutputMode;
      RestartType _RestartType;
      NumericRange<20, 600000, 200> _RestartTime;
      NumericRange<1, 8, 1> _RestartInput;
      Combination _Combination;
      int _Reserved3;
      int _Reserved4;
      std::vector<SourcesItem> _Sources;
    };

    PortConfigurationItem() = default;

    explicit PortConfigurationItem(PortType PortType, std::string Name, InputSettings InputSettings, OutputSettings OutputSettings, EncoderPortType EncoderPortType, int Reserved8, int Reserved9, int Reserved10)
      : _PortType(PortType), _Name(std::move(Name)), _InputSettings(InputSettings), _OutputSettings(OutputSettings), _EncoderPortType(EncoderPortType), _Reserved8(Reserved8), _Reserved9(Reserved9), _Reserved10(Reserved10)
    {}

    PortType _PortType;
    std::string _Name;
    InputSettings _InputSettings;
    OutputSettings _OutputSettings;
    EncoderPortType _EncoderPortType;
    int _Reserved8;
    int _Reserved9;
    int _Reserved10;
  };

  Response() = default;

  explicit Response(std::array<PortConfigurationItem, 8> PortConfiguration)
    : _PortConfiguration(PortConfiguration)
  {}

  std::array<PortConfigurationItem, 8> _PortConfiguration;
};

}; // struct Get

/**
 * @brief Returns/sets the port configuration of all I/Os.

 This function requires at least user level: Authorized Client.
*/
struct SDK_EXPORT Post
{
struct SDK_EXPORT Request
{
  struct SDK_EXPORT PortConfigurationItem
  {
    enum class PortType
    {
      Input = 0,
      Output = 1,
      Encoder = 2,
    };

    enum class EncoderPortType
    {
      None = 0,
      EncoderA = 1,
      EncoderB = 2,
      Aux1 = 3,
      Aux2 = 4,
    };

    struct SDK_EXPORT InputSettings
    {
      enum class Logic
      {
        ActiveHigh = 0,
        ActiveLow = 1,
      };

      enum class Sensitivity
      {
        Edge = 0,
        Level = 1,
      };

      InputSettings() = default;

      explicit InputSettings(Logic Logic, NumericRange<1, 1000, 10> Debounce, Sensitivity Sensitivity, int Reserved1, int Reserved2)
        : _Logic(Logic), _Debounce(std::move(Debounce)), _Sensitivity(Sensitivity), _Reserved1(Reserved1), _Reserved2(Reserved2)
      {}

      Logic _Logic;
      NumericRange<1, 1000, 10> _Debounce;
      Sensitivity _Sensitivity;
      int _Reserved1;
      int _Reserved2;
    };

    struct SDK_EXPORT OutputSettings
    {
      enum class Logic
      {
        ActiveHigh = 0,
        ActiveLow = 1,
      };

      enum class OutputMode
      {
        Pnp = 0,
        Npn = 1,
        PushPull = 2,
      };

      enum class RestartType
      {
        RestartImmedate = 0,
        RestartTime = 1,
        RestartInput = 2,
      };

      enum class Combination
      {
        And = 0,
        Or = 1,
        Xor = 2,
      };

      struct SDK_EXPORT SourcesItem
      {
        SourcesItem() = default;

        explicit SourcesItem(std::string Name, bool Invert, int Reserved5, int Reserved6)
          : _Name(std::move(Name)), _Invert(Invert), _Reserved5(Reserved5), _Reserved6(Reserved6)
        {}

        std::string _Name;
        bool _Invert;
        int _Reserved5;
        int _Reserved6;
      };

      OutputSettings() = default;

      explicit OutputSettings(Logic Logic, OutputMode OutputMode, RestartType RestartType, NumericRange<20, 600000, 200> RestartTime, NumericRange<1, 8, 1> RestartInput, Combination Combination, int Reserved3, int Reserved4, std::vector<SourcesItem> Sources)
        : _Logic(Logic), _OutputMode(OutputMode), _RestartType(RestartType), _RestartTime(std::move(RestartTime)), _RestartInput(std::move(RestartInput)), _Combination(Combination), _Reserved3(Reserved3), _Reserved4(Reserved4), _Sources(Sources)
      {}

      Logic _Logic;
      OutputMode _OutputMode;
      RestartType _RestartType;
      NumericRange<20, 600000, 200> _RestartTime;
      NumericRange<1, 8, 1> _RestartInput;
      Combination _Combination;
      int _Reserved3;
      int _Reserved4;
      std::vector<SourcesItem> _Sources;
    };

    PortConfigurationItem() = default;

    explicit PortConfigurationItem(PortType PortType, std::string Name, InputSettings InputSettings, OutputSettings OutputSettings, EncoderPortType EncoderPortType, int Reserved8, int Reserved9, int Reserved10)
      : _PortType(PortType), _Name(std::move(Name)), _InputSettings(InputSettings), _OutputSettings(OutputSettings), _EncoderPortType(EncoderPortType), _Reserved8(Reserved8), _Reserved9(Reserved9), _Reserved10(Reserved10)
    {}

    PortType _PortType;
    std::string _Name;
    InputSettings _InputSettings;
    OutputSettings _OutputSettings;
    EncoderPortType _EncoderPortType;
    int _Reserved8;
    int _Reserved9;
    int _Reserved10;
  };

  Request() = default;

  explicit Request(std::array<PortConfigurationItem, 8> PortConfiguration)
    : _PortConfiguration(PortConfiguration)
  {}

  std::array<PortConfigurationItem, 8> _PortConfiguration;
};

}; // struct Post

}; // struct PortConfiguration

} // namespace sick::srt::picoScan100
