/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

#pragma once

#include <sick_perception_sdk/common/export.hpp>
#include <sick_perception_sdk/common/quantities/Timestamp.hpp>

#include <chrono>
#include <cstdint>
#include <string>
#include <vector>

namespace sick {

struct SDK_EXPORT PointField
{
  enum class Datatype : std::uint8_t
  {
    BOOL    = 0,
    INT8    = 1,
    UINT8   = 2,
    INT16   = 3,
    UINT16  = 4,
    INT32   = 5,
    UINT32  = 6,
    FLOAT32 = 7,
    FLOAT64 = 8
  };
  std::string name;
  std::uint32_t offset = 0;
  Datatype datatype    = Datatype::UINT8;
  std::uint32_t count  = 0; // number of elements in the field; is called `count` in PCL and ROS.
};

struct SDK_EXPORT PointCloud
{
  struct Header
  {
    Timestamp timestamp = Timestamp::fromMicrosecondsSinceEpoch(0);
  };

  Header header;
  std::size_t numberOfPoints = 0;
  std::vector<PointField> fields; // describes data
  std::uint32_t pointStep = 0;    // length of a point in bytes
  std::vector<std::uint8_t> data; // actual point data, size is (number of points * point step)
};

} // namespace sick
