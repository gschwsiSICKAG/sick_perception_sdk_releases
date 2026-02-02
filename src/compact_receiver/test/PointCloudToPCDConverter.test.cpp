/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

#include <sick_perception_sdk/compact_receiver/PointCloudToPCDConverter.hpp>

#include <gtest/gtest.h>
#include <sstream>

namespace {

auto createPointCloud(std::size_t numberOfPoints)
{
  sick::PointCloud pc;
  pc.header.timestamp = sick::Timestamp::fromNanoseconds(123456789);
  pc.numberOfPoints   = numberOfPoints;
  pc.fields =
    {{"x", 0, sick::PointField::Datatype::FLOAT32, 1}, {"y", 4, sick::PointField::Datatype::FLOAT32, 1}, {"z", 8, sick::PointField::Datatype::FLOAT32, 1}};
  pc.pointStep = 12; // 3 * sizeof(float)
  pc.data.resize(pc.pointStep * pc.numberOfPoints, 0);
  return pc;
}

} // namespace

TEST(PointCloudToPCDConverterTest, convertToPCDBinary_works_with_empty_pointcloud)
{
  sick::PointCloudToPCDConverter converter;

  sick::PointCloud pc;

  std::ostringstream ss(std::ios::binary);
  converter.convertToPCDBinary(pc, ss);
  EXPECT_GT(ss.str().size(), 1); // There's always some header data in the PCD, even if the input is empty.
}

TEST(PointCloudToPCDConverterTest, convertToPCDBinary_creates_non_empty_output)
{
  sick::PointCloudToPCDConverter converter;

  auto const pcEmpty = sick::PointCloud {};
  auto const pcFull  = createPointCloud(2);

  std::ostringstream streamEmpty(std::ios::binary);
  converter.convertToPCDBinary(pcEmpty, streamEmpty);

  std::ostringstream streamFull(std::ios::binary);
  converter.convertToPCDBinary(pcFull, streamFull);

  // We don't make any assumptions about the exact size of the output,
  // but the output for a point cloud with points must be larger than
  // the output for an empty point cloud.
  EXPECT_GT(streamFull.str().size(), streamEmpty.str().size());
}

TEST(PointCloudToPCDConverterTest, convertToPCDASCII_works_with_empty_pointcloud)
{
  sick::PointCloudToPCDConverter converter;

  sick::PointCloud pc;

  std::ostringstream ss(std::ios::binary);
  converter.convertToPCDASCII(pc, ss);
  EXPECT_GT(ss.str().size(), 1); // There's always some header data in the PCD, even if the input is empty.
}

TEST(PointCloudToPCDConverterTest, convertToPCDASCII_creates_non_empty_output)
{
  sick::PointCloudToPCDConverter converter;

  auto const pcEmpty = sick::PointCloud {};
  auto const pcFull  = createPointCloud(2);

  std::ostringstream streamEmpty(std::ios::binary);
  converter.convertToPCDASCII(pcEmpty, streamEmpty);

  std::ostringstream streamFull(std::ios::binary);
  converter.convertToPCDASCII(pcFull, streamFull);

  // We don't make any assumptions about the exact size of the output,
  // but the output for a point cloud with points must be larger than
  // the output for an empty point cloud.
  EXPECT_GT(streamFull.str().size(), streamEmpty.str().size());
}
