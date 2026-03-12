/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

#include <sick_perception_sdk/compact_format/PointCloud/OrganizedPointCloudBuilder.hpp>

#include <cmath>
#include <gtest/gtest.h>

using DataType  = sick::MultiEchoPointCloud::PointField::DataType;
using Density   = sick::MultiEchoPointCloud::Density;
using FieldType = sick::MultiEchoPointCloud::PointField::FieldType;
using Layout    = sick::OrganizedPointCloudBuilder::Layout;

namespace {

auto createLayout(std::size_t width = 4, std::size_t height = 3, std::size_t numberOfEchoesPerBeam = 2) -> Layout
{
  Layout layout;
  layout.width                 = width;
  layout.height                = height;
  layout.numberOfEchoesPerBeam = numberOfEchoesPerBeam;
  layout.fields                = {
    {FieldType::X, 0, DataType::Float32},
    {FieldType::Y, 4, DataType::Float32},
    {FieldType::Z, 8, DataType::Float32},
  };
  layout.pointSizeBytes = 12;
  return layout;
}

} // namespace

TEST(OrganizedPointCloudBuilderTest, build_fails_if_not_enough_points_are_added)
{
  auto const layout = createLayout();
  sick::OrganizedPointCloudBuilder builder(sick::Timestamp::fromMicrosecondsSinceEpoch(1000), layout);

  // Don't add any points, just call build immediately.
  // This must fail because the builder expects more than 1 point based on the layout.

  EXPECT_THROW(builder.build(), std::runtime_error);

  // Add a point and try again.
  // This must also fail because we still haven't added all points.
  builder.beginPoint();
  builder.write(1.0f);
  builder.write(2.0f);
  builder.write(3.0f);
  EXPECT_THROW(builder.build(), std::runtime_error);
}

TEST(OrganizedPointCloudBuilderTest, build_returns_point_cloud_with_single_point)
{
  auto const width                 = 1;
  auto const height                = 1;
  auto const numberOfEchoesPerBeam = 1;
  auto const layout                = createLayout(width, height, numberOfEchoesPerBeam);
  sick::OrganizedPointCloudBuilder builder(sick::Timestamp::fromMicrosecondsSinceEpoch(1000), layout);

  builder.beginPoint();
  builder.write(1.0f);
  builder.write(2.0f);
  builder.write(3.0f);

  auto const cloud = builder.build();

  EXPECT_EQ(1, cloud.numberOfPoints());
  EXPECT_EQ(1, cloud.width());
  EXPECT_EQ(1, cloud.height());
  EXPECT_EQ(12, cloud.rawByteSize());
  EXPECT_EQ(Density::AllPointsValid, cloud.density());

  EXPECT_FLOAT_EQ(1.0f, cloud.getFieldValue<float>(FieldType::X, 0));
  EXPECT_FLOAT_EQ(2.0f, cloud.getFieldValue<float>(FieldType::Y, 0));
  EXPECT_FLOAT_EQ(3.0f, cloud.getFieldValue<float>(FieldType::Z, 0));
}

TEST(OrganizedPointCloudBuilderTest, build_returns_point_cloud_with_multiple_points)
{
  auto const width                 = 5;
  auto const height                = 1;
  auto const numberOfEchoesPerBeam = 1;
  auto const layout                = createLayout(width, height, numberOfEchoesPerBeam);
  sick::OrganizedPointCloudBuilder builder(sick::Timestamp::fromMicrosecondsSinceEpoch(1000), layout);

  for (int i = 0; i < 5; ++i)
  {
    builder.beginPoint();
    builder.write(static_cast<float>(i));
    builder.write(static_cast<float>(i * 2));
    builder.write(static_cast<float>(i * 3));
  }

  auto const cloud = builder.build();

  EXPECT_EQ(5, cloud.numberOfPoints());
  EXPECT_EQ(5, cloud.width());
  EXPECT_EQ(1, cloud.height());
  EXPECT_EQ(60, cloud.rawByteSize());

  // Verify last point
  EXPECT_FLOAT_EQ(4.0f, cloud.getFieldValue<float>(FieldType::X, 4));
  EXPECT_FLOAT_EQ(8.0f, cloud.getFieldValue<float>(FieldType::Y, 4));
  EXPECT_FLOAT_EQ(12.0f, cloud.getFieldValue<float>(FieldType::Z, 4));
}

TEST(OrganizedPointCloudBuilderTest, write_invalid_point_sets_sparse_density)
{
  constexpr auto width                = 1;
  constexpr auto height               = 1;
  constexpr std::size_t echoesPerBeam = 1;
  auto const layout                   = createLayout(width, height, echoesPerBeam);
  sick::OrganizedPointCloudBuilder builder(sick::Timestamp::fromMicrosecondsSinceEpoch(2000), layout);

  builder.writeInvalidPoint();

  auto const cloud = builder.build();

  EXPECT_EQ(1, cloud.numberOfPoints());
  EXPECT_EQ(Density::InvalidPointsContained, cloud.density());
}

TEST(OrganizedPointCloudBuilderTest, write_invalid_point_writes_nan_for_floats)
{
  constexpr auto width                = 1;
  constexpr auto height               = 1;
  constexpr std::size_t echoesPerBeam = 1;
  auto const layout                   = createLayout(width, height, echoesPerBeam);
  sick::OrganizedPointCloudBuilder builder(sick::Timestamp::fromMicrosecondsSinceEpoch(1000), layout);

  builder.writeInvalidPoint();

  auto const cloud = builder.build();

  EXPECT_TRUE(std::isnan(cloud.getFieldValue<float>(FieldType::X, 0)));
  EXPECT_TRUE(std::isnan(cloud.getFieldValue<float>(FieldType::Y, 0)));
  EXPECT_TRUE(std::isnan(cloud.getFieldValue<float>(FieldType::Z, 0)));
}

TEST(OrganizedPointCloudBuilderTest, build_handles_mixed_valid_and_invalid_points)
{
  constexpr auto width                = 3;
  constexpr auto height               = 1;
  constexpr std::size_t echoesPerBeam = 1;
  auto const layout                   = createLayout(width, height, echoesPerBeam);
  sick::OrganizedPointCloudBuilder builder(sick::Timestamp::fromMicrosecondsSinceEpoch(2000), layout);

  builder.beginPoint();
  builder.write(1.0f);
  builder.write(2.0f);
  builder.write(3.0f);

  builder.writeInvalidPoint();

  builder.beginPoint();
  builder.write(4.0f);
  builder.write(5.0f);
  builder.write(6.0f);

  auto const cloud = builder.build();

  EXPECT_EQ(3, cloud.numberOfPoints());
  EXPECT_EQ(Density::InvalidPointsContained, cloud.density());

  // Check second point is NaN
  EXPECT_TRUE(std::isnan(cloud.getFieldValue<float>(FieldType::Y, 1)));

  // Check third point
  EXPECT_FLOAT_EQ(4.0f, cloud.getFieldValue<float>(FieldType::X, 2));
}

TEST(OrganizedPointCloudBuilderTest, build_preserves_timestamp)
{
  auto layout   = createLayout(0, 0, 0);
  auto const ts = sick::Timestamp::fromMicrosecondsSinceEpoch(123456789);

  sick::OrganizedPointCloudBuilder builder(ts, layout);
  auto const cloud = builder.build();

  EXPECT_EQ(ts, cloud.timestamp());
}

TEST(OrganizedPointCloudBuilderTest, build_preserves_fields)
{
  auto const layout = createLayout(0, 0, 0);
  sick::OrganizedPointCloudBuilder builder(sick::Timestamp::fromMicrosecondsSinceEpoch(1000), layout);
  auto const cloud = builder.build();

  ASSERT_EQ(3, cloud.fields().size());
  EXPECT_EQ(FieldType::X, cloud.fields()[0].fieldType);
  EXPECT_EQ(FieldType::Y, cloud.fields()[1].fieldType);
  EXPECT_EQ(FieldType::Z, cloud.fields()[2].fieldType);
}

// Tests for buildLayout helper

TEST(OrganizedPointCloudBuilderTest, buildLayout_includes_cartesian_fields_when_enabled)
{
  sick::PointCloudConfiguration config;
  config.fields.enableCartesian = true;
  config.organization           = sick::MultiEchoPointCloud::Organization::Organized;

  auto const layout = sick::OrganizedPointCloudBuilder::buildLayout(config, 10, 1, 1);

  ASSERT_EQ(3, layout.fields.size());
  EXPECT_EQ(FieldType::X, layout.fields[0].fieldType);
  EXPECT_EQ(FieldType::Y, layout.fields[1].fieldType);
  EXPECT_EQ(FieldType::Z, layout.fields[2].fieldType);
  EXPECT_EQ(12, layout.pointSizeBytes);
}

TEST(OrganizedPointCloudBuilderTest, buildLayout_includes_spherical_fields_when_enabled)
{
  sick::PointCloudConfiguration config;
  config.fields.enableCartesian = false;
  config.fields.enableSpherical = true;
  config.organization           = sick::MultiEchoPointCloud::Organization::Organized;

  auto const layout = sick::OrganizedPointCloudBuilder::buildLayout(config, 10, 1, 1);

  ASSERT_EQ(3, layout.fields.size());
  EXPECT_EQ(FieldType::Range, layout.fields[0].fieldType);
  EXPECT_EQ(FieldType::Azimuth, layout.fields[1].fieldType);
  EXPECT_EQ(FieldType::Elevation, layout.fields[2].fieldType);
  EXPECT_EQ(12, layout.pointSizeBytes);
}

TEST(OrganizedPointCloudBuilderTest, buildLayout_includes_all_fields_when_all_enabled)
{
  sick::PointCloudConfiguration config;
  config.fields.enableCartesian   = true;
  config.fields.enableSpherical   = true;
  config.fields.enableIntensity   = true;
  config.fields.enableTimeOffset  = true;
  config.fields.enableRing        = true;
  config.fields.enableLayer       = true;
  config.fields.enableEcho        = true;
  config.fields.enableIsReflector = true;
  config.fields.enableHasBlooming = true;
  config.organization             = sick::MultiEchoPointCloud::Organization::Organized;

  auto const layout = sick::OrganizedPointCloudBuilder::buildLayout(config, 10, 1, 1);

  // 3 (xyz) + 3 (spherical) + 1 (intensity) + 1 (t_ns) + 1 (t_s) + 1 (ring) + 1 (layer) + 1 (echo) + 1 (reflector) + 1 (blooming) = 14
  EXPECT_EQ(14, layout.fields.size());

  // Expected size: 3*4 + 3*4 + 4 + 4 + 4 + 1 + 1 + 1 + 1 + 1 = 12 + 12 + 12 + 5 = 41
  EXPECT_EQ(41, layout.pointSizeBytes);
}

TEST(OrganizedPointCloudBuilderTest, buildLayout_sets_sequential_field_offsets)
{
  sick::PointCloudConfiguration config;
  config.fields.enableCartesian = true;
  config.fields.enableIntensity = true;
  config.fields.enableRing      = true;
  config.organization           = sick::MultiEchoPointCloud::Organization::Organized;

  auto const layout = sick::OrganizedPointCloudBuilder::buildLayout(config, 10, 1, 1);

  ASSERT_EQ(5, layout.fields.size());
  EXPECT_EQ(0, layout.fields[0].offset);  // X
  EXPECT_EQ(4, layout.fields[1].offset);  // Y
  EXPECT_EQ(8, layout.fields[2].offset);  // Z
  EXPECT_EQ(12, layout.fields[3].offset); // Intensity
  EXPECT_EQ(16, layout.fields[4].offset); // Ring
}

TEST(OrganizedPointCloudBuilderTest, buildLayout_preserves_metadata)
{
  sick::PointCloudConfiguration config;
  config.organization = sick::MultiEchoPointCloud::Organization::Organized;

  auto const layout = sick::OrganizedPointCloudBuilder::buildLayout(config, 100, 16, 3);

  EXPECT_EQ(100, layout.width);
  EXPECT_EQ(16, layout.height);
  EXPECT_EQ(3, layout.numberOfEchoesPerBeam);
}

TEST(OrganizedPointCloudBuilderTest, buildLayout_fails_if_organization_is_not_organized)
{
  sick::PointCloudConfiguration config;
  config.organization = sick::MultiEchoPointCloud::Organization::Unorganized;

  EXPECT_THROW(sick::OrganizedPointCloudBuilder::buildLayout(config, 100, 16, 3), std::invalid_argument);
}
