/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

#include <sick_perception_sdk/compact_format/PointCloud/PointCloudToPcdConverter.hpp>

#include <sick_perception_sdk/compact_format/PointCloud/UnorganizedPointCloudBuilder.hpp>

#include <gtest/gtest.h>
#include <sstream>

namespace {

auto createPointCloud(std::size_t numberOfPoints)
{
  sick::UnorganizedPointCloudBuilder builder(sick::Timestamp::fromMicrosecondsSinceEpoch(123456789), sick::PointCloudConfiguration(), numberOfPoints);
  for (std::size_t i = 0; i < numberOfPoints; ++i)
  {
    builder.beginPoint();
    builder.write<float>(static_cast<float>(i));        // X
    builder.write<float>(static_cast<float>(i) + 0.5f); // Y
    builder.write<float>(static_cast<float>(i) + 1.0f); // Z
  }
  return builder.build();
}

} // namespace

TEST(PointCloudToPcdConverterTest, convertToBinary_works_with_empty_pointcloud)
{
  auto const pc = createPointCloud(0);

  std::ostringstream ss(std::ios::binary);
  sick::pcd::convertToBinary(pc, ss);
  EXPECT_GT(ss.str().size(), 1); // There's always some header data in the PCD, even if the input is empty.
}

TEST(PointCloudToPcdConverterTest, convertToBinary_creates_non_empty_output)
{
  auto const pcEmpty = createPointCloud(0);
  auto const pcFull  = createPointCloud(2);

  std::ostringstream streamEmpty(std::ios::binary);
  sick::pcd::convertToBinary(pcEmpty, streamEmpty);

  std::ostringstream streamFull(std::ios::binary);
  sick::pcd::convertToBinary(pcFull, streamFull);

  // We don't make any assumptions about the exact size of the output,
  // but the output for a point cloud with points must be larger than
  // the output for an empty point cloud.
  EXPECT_GT(streamFull.str().size(), streamEmpty.str().size());
}

TEST(PointCloudToPcdConverterTest, convertToAscii_works_with_empty_pointcloud)
{
  auto const pc = createPointCloud(0);

  std::ostringstream ss(std::ios::binary);
  sick::pcd::convertToAscii(pc, ss);
  EXPECT_GT(ss.str().size(), 1); // There's always some header data in the PCD, even if the input is empty.
}

TEST(PointCloudToPcdConverterTest, convertToAscii_creates_non_empty_output)
{
  auto const pcEmpty = createPointCloud(0);
  auto const pcFull  = createPointCloud(2);

  std::ostringstream streamEmpty(std::ios::binary);
  sick::pcd::convertToAscii(pcEmpty, streamEmpty);

  std::ostringstream streamFull(std::ios::binary);
  sick::pcd::convertToAscii(pcFull, streamFull);

  // We don't make any assumptions about the exact size of the output,
  // but the output for a point cloud with points must be larger than
  // the output for an empty point cloud.
  EXPECT_GT(streamFull.str().size(), streamEmpty.str().size());
}
