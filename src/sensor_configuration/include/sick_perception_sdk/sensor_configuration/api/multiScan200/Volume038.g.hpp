/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file Volume038.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>
#include <sick_perception_sdk/sensor_configuration/api/NumericRange.hpp>
#include <string>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /Volume038.
*/
struct SDK_EXPORT Volume038
{

  constexpr static const char* variableName = "Volume038";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief Get Volume038.
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  struct SDK_EXPORT Volume038
  {
    struct SDK_EXPORT ExtrudedPolygonListItem
    {
      struct SDK_EXPORT PointsItem
      {
        PointsItem() = default;

        explicit PointsItem(int x, int y)
          : _x(x), _y(y)
        {}

        int _x;
        int _y;
      };

      ExtrudedPolygonListItem() = default;

      explicit ExtrudedPolygonListItem(int Version, NumericRange<-100000, 100000, 0> LowerZLimit, NumericRange<-100000, 100000, 0> UpperZLimit, std::vector<PointsItem> Points)
        : _Version(Version), _LowerZLimit(std::move(LowerZLimit)), _UpperZLimit(std::move(UpperZLimit)), _Points(Points)
      {}

      int _Version;
      NumericRange<-100000, 100000, 0> _LowerZLimit;
      NumericRange<-100000, 100000, 0> _UpperZLimit;
      std::vector<PointsItem> _Points;
    };

    Volume038() = default;

    explicit Volume038(int Version, std::string Name, int ID, std::vector<ExtrudedPolygonListItem> ExtrudedPolygonList)
      : _Version(Version), _Name(std::move(Name)), _ID(ID), _ExtrudedPolygonList(ExtrudedPolygonList)
    {}

    int _Version;
    std::string _Name;
    int _ID;
    std::vector<ExtrudedPolygonListItem> _ExtrudedPolygonList;
  };

  Response() = default;

  explicit Response(Volume038 Volume038)
    : _Volume038(Volume038)
  {}

  Volume038 _Volume038;
};

}; // struct Get

/**
 * @brief Post Volume038.

 This function requires at least user level: Authorized Client.
*/
struct SDK_EXPORT Post
{
struct SDK_EXPORT Request
{
  struct SDK_EXPORT ExtrudedPolygonListItem
  {
    struct SDK_EXPORT PointsItem
    {
      PointsItem() = default;

      explicit PointsItem(int x, int y)
        : _x(x), _y(y)
      {}

      int _x;
      int _y;
    };

    ExtrudedPolygonListItem() = default;

    explicit ExtrudedPolygonListItem(int Version, NumericRange<-100000, 100000, 0> LowerZLimit, NumericRange<-100000, 100000, 0> UpperZLimit, std::vector<PointsItem> Points)
      : _Version(Version), _LowerZLimit(std::move(LowerZLimit)), _UpperZLimit(std::move(UpperZLimit)), _Points(Points)
    {}

    int _Version;
    NumericRange<-100000, 100000, 0> _LowerZLimit;
    NumericRange<-100000, 100000, 0> _UpperZLimit;
    std::vector<PointsItem> _Points;
  };

  Request() = default;

  explicit Request(int Version, std::string Name, int ID, std::vector<ExtrudedPolygonListItem> ExtrudedPolygonList)
    : _Version(Version), _Name(std::move(Name)), _ID(ID), _ExtrudedPolygonList(ExtrudedPolygonList)
  {}

  int _Version;
  std::string _Name;
  int _ID;
  std::vector<ExtrudedPolygonListItem> _ExtrudedPolygonList;
};

}; // struct Post

}; // struct Volume038

} // namespace sick::srt::multiScan200
