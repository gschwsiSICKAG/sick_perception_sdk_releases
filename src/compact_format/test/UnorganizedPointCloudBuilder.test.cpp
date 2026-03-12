/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

#include <sick_perception_sdk/compact_format/PointCloud/UnorganizedPointCloudBuilder.hpp>

#include <gtest/gtest.h>

using DataType     = sick::MultiEchoPointCloud::PointField::DataType;
using Density      = sick::MultiEchoPointCloud::Density;
using FieldType    = sick::MultiEchoPointCloud::PointField::FieldType;
using Organization = sick::MultiEchoPointCloud::Organization;

namespace {

auto createConfiguration() -> sick::PointCloudConfiguration
{
  sick::PointCloudConfiguration config;
  config.organization           = Organization::Unorganized;
  config.fields.enableCartesian = true;
  return config;
}

} // namespace

TEST(UnorganizedPointCloudBuilderTest, constructor_throws_if_organization_is_not_unorganized)
{
  sick::PointCloudConfiguration config;
  config.organization = Organization::Organized;

  EXPECT_THROW(sick::UnorganizedPointCloudBuilder(sick::Timestamp::fromMicrosecondsSinceEpoch(1000), config, 1), std::invalid_argument);
}

TEST(UnorganizedPointCloudBuilderTest, build_returns_empty_point_cloud_when_no_points_added)
{
  auto const config = createConfiguration();
  sick::UnorganizedPointCloudBuilder builder(sick::Timestamp::fromMicrosecondsSinceEpoch(1000), config, 1);

  auto const cloud = builder.build();

  EXPECT_EQ(0, cloud.numberOfPoints());
  EXPECT_EQ(0, cloud.width());
  EXPECT_EQ(1, cloud.height());
  EXPECT_TRUE(cloud.isEmpty());
  EXPECT_EQ(Organization::Unorganized, cloud.organization());
}

TEST(UnorganizedPointCloudBuilderTest, build_returns_point_cloud_with_single_point)
{
  auto const config = createConfiguration();
  sick::UnorganizedPointCloudBuilder builder(sick::Timestamp::fromMicrosecondsSinceEpoch(1000), config, 1);

  builder.beginPoint();
  builder.write(1.0f);
  builder.write(2.0f);
  builder.write(3.0f);

  auto const cloud = builder.build();

  EXPECT_EQ(1, cloud.numberOfPoints());
  EXPECT_EQ(1, cloud.width());
  EXPECT_EQ(1, cloud.height());
  EXPECT_EQ(Density::AllPointsValid, cloud.density());

  EXPECT_FLOAT_EQ(1.0f, cloud.getFieldValue<float>(FieldType::X, 0));
  EXPECT_FLOAT_EQ(2.0f, cloud.getFieldValue<float>(FieldType::Y, 0));
  EXPECT_FLOAT_EQ(3.0f, cloud.getFieldValue<float>(FieldType::Z, 0));
}

TEST(UnorganizedPointCloudBuilderTest, build_returns_point_cloud_with_multiple_points)
{
  constexpr std::size_t numberOfPoints = 5;
  auto const config                    = createConfiguration();
  sick::UnorganizedPointCloudBuilder builder(sick::Timestamp::fromMicrosecondsSinceEpoch(1000), config, numberOfPoints);

  for (auto i = 0; i < numberOfPoints; ++i)
  {
    builder.beginPoint();
    builder.write(static_cast<float>(i));
    builder.write(static_cast<float>(i * 2));
    builder.write(static_cast<float>(i * 3));
  }

  auto const cloud = builder.build();

  EXPECT_EQ(numberOfPoints, cloud.numberOfPoints());
  EXPECT_EQ(numberOfPoints, cloud.width());
  EXPECT_EQ(1, cloud.height());

  EXPECT_FLOAT_EQ(0.0f, cloud.getFieldValue<float>(FieldType::X, 0));
  EXPECT_FLOAT_EQ(0.0f, cloud.getFieldValue<float>(FieldType::Y, 0));
  EXPECT_FLOAT_EQ(0.0f, cloud.getFieldValue<float>(FieldType::Z, 0));

  EXPECT_FLOAT_EQ(4.0f, cloud.getFieldValue<float>(FieldType::X, 4));
  EXPECT_FLOAT_EQ(8.0f, cloud.getFieldValue<float>(FieldType::Y, 4));
  EXPECT_FLOAT_EQ(12.0f, cloud.getFieldValue<float>(FieldType::Z, 4));
}

TEST(UnorganizedPointCloudBuilderTest, build_preserves_timestamp)
{
  auto const config = createConfiguration();
  auto const ts     = sick::Timestamp::fromMicrosecondsSinceEpoch(123456789);
  sick::UnorganizedPointCloudBuilder builder(ts, config, 1);

  auto const cloud = builder.build();

  EXPECT_EQ(ts, cloud.timestamp());
}

TEST(UnorganizedPointCloudBuilderTest, build_includes_cartesian_fields_when_enabled)
{
  sick::PointCloudConfiguration config;
  config.organization           = Organization::Unorganized;
  config.fields.enableCartesian = true;

  sick::UnorganizedPointCloudBuilder builder(sick::Timestamp::fromMicrosecondsSinceEpoch(1000), config, 1);
  auto const cloud = builder.build();

  ASSERT_EQ(3, cloud.fields().size());
  EXPECT_EQ(FieldType::X, cloud.fields()[0].fieldType);
  EXPECT_EQ(FieldType::Y, cloud.fields()[1].fieldType);
  EXPECT_EQ(FieldType::Z, cloud.fields()[2].fieldType);
}

TEST(UnorganizedPointCloudBuilderTest, build_includes_spherical_fields_when_enabled)
{
  sick::PointCloudConfiguration config;
  config.organization           = Organization::Unorganized;
  config.fields.enableCartesian = false;
  config.fields.enableSpherical = true;

  sick::UnorganizedPointCloudBuilder builder(sick::Timestamp::fromMicrosecondsSinceEpoch(1000), config, 1);
  auto const cloud = builder.build();

  ASSERT_EQ(3, cloud.fields().size());
  EXPECT_EQ(FieldType::Range, cloud.fields()[0].fieldType);
  EXPECT_EQ(FieldType::Azimuth, cloud.fields()[1].fieldType);
  EXPECT_EQ(FieldType::Elevation, cloud.fields()[2].fieldType);
}

TEST(UnorganizedPointCloudBuilderTest, build_includes_intensity_field_when_enabled)
{
  sick::PointCloudConfiguration config;
  config.organization           = Organization::Unorganized;
  config.fields.enableCartesian = false;
  config.fields.enableIntensity = true;

  sick::UnorganizedPointCloudBuilder builder(sick::Timestamp::fromMicrosecondsSinceEpoch(1000), config, 1);
  auto const cloud = builder.build();

  ASSERT_EQ(1, cloud.fields().size());
  EXPECT_EQ(FieldType::Intensity, cloud.fields()[0].fieldType);
}

TEST(UnorganizedPointCloudBuilderTest, build_includes_time_offset_fields_when_enabled)
{
  sick::PointCloudConfiguration config;
  config.organization            = Organization::Unorganized;
  config.fields.enableCartesian  = false;
  config.fields.enableTimeOffset = true;

  sick::UnorganizedPointCloudBuilder builder(sick::Timestamp::fromMicrosecondsSinceEpoch(1000), config, 1);
  auto const cloud = builder.build();

  ASSERT_EQ(2, cloud.fields().size());
  EXPECT_EQ(FieldType::TimeOffsetNanoseconds, cloud.fields()[0].fieldType);
  EXPECT_EQ(FieldType::TimeOffsetSeconds, cloud.fields()[1].fieldType);
}

TEST(UnorganizedPointCloudBuilderTest, build_includes_all_fields_when_all_enabled)
{
  sick::PointCloudConfiguration config;
  config.organization             = Organization::Unorganized;
  config.fields.enableCartesian   = true;
  config.fields.enableSpherical   = true;
  config.fields.enableIntensity   = true;
  config.fields.enableTimeOffset  = true;
  config.fields.enableRing        = true;
  config.fields.enableLayer       = true;
  config.fields.enableEcho        = true;
  config.fields.enableIsReflector = true;
  config.fields.enableHasBlooming = true;
  config.fields.enablePulseWidth  = true;

  sick::UnorganizedPointCloudBuilder builder(sick::Timestamp::fromMicrosecondsSinceEpoch(1000), config, 1);
  auto const cloud = builder.build();

  // 3 (xyz) + 3 (spherical) + 1 (intensity) + 2 (time offset) + 1 (ring) + 1 (layer) + 1 (echo) + 1 (reflector) + 1 (blooming) + 1 (pulse width) = 15
  EXPECT_EQ(15, cloud.fields().size());
}

TEST(UnorganizedPointCloudBuilderTest, build_sets_sequential_field_offsets)
{
  sick::PointCloudConfiguration config;
  config.organization           = Organization::Unorganized;
  config.fields.enableCartesian = true;
  config.fields.enableIntensity = true;
  config.fields.enableRing      = true;

  sick::UnorganizedPointCloudBuilder builder(sick::Timestamp::fromMicrosecondsSinceEpoch(1000), config, 1);
  auto const cloud = builder.build();

  ASSERT_EQ(5, cloud.fields().size());
  EXPECT_EQ(0, cloud.fields()[0].offset);  // X
  EXPECT_EQ(4, cloud.fields()[1].offset);  // Y
  EXPECT_EQ(8, cloud.fields()[2].offset);  // Z
  EXPECT_EQ(12, cloud.fields()[3].offset); // Intensity
  EXPECT_EQ(16, cloud.fields()[4].offset); // Ring
}

TEST(UnorganizedPointCloudBuilderTest, build_sets_correct_data_types_for_fields)
{
  sick::PointCloudConfiguration config;
  config.organization            = Organization::Unorganized;
  config.fields.enableCartesian  = true;
  config.fields.enableTimeOffset = true;
  config.fields.enableRing       = true;

  sick::UnorganizedPointCloudBuilder builder(sick::Timestamp::fromMicrosecondsSinceEpoch(1000), config, 1);
  auto const cloud = builder.build();

  ASSERT_EQ(6, cloud.fields().size());
  EXPECT_EQ(DataType::Float32, cloud.fields()[0].dataType); // X
  EXPECT_EQ(DataType::Float32, cloud.fields()[1].dataType); // Y
  EXPECT_EQ(DataType::Float32, cloud.fields()[2].dataType); // Z
  EXPECT_EQ(DataType::Uint32, cloud.fields()[3].dataType);  // TimeOffsetNanoseconds
  EXPECT_EQ(DataType::Uint32, cloud.fields()[4].dataType);  // TimeOffsetSeconds
  EXPECT_EQ(DataType::Uint8, cloud.fields()[5].dataType);   // Ring
}

TEST(UnorganizedPointCloudBuilderTest, write_handles_different_value_types)
{
  sick::PointCloudConfiguration config;
  config.organization            = Organization::Unorganized;
  config.fields.enableCartesian  = true;
  config.fields.enableTimeOffset = true;
  config.fields.enableRing       = true;

  sick::UnorganizedPointCloudBuilder builder(sick::Timestamp::fromMicrosecondsSinceEpoch(1000), config, 1);

  builder.beginPoint();
  builder.write(1.0f);              // X (float32)
  builder.write(2.0f);              // Y (float32)
  builder.write(3.0f);              // Z (float32)
  builder.write(std::uint32_t {4}); // TimeOffsetNanoseconds (uint32)
  builder.write(std::uint32_t {5}); // TimeOffsetSeconds (uint32)
  builder.write(std::uint8_t {6});  // Ring (uint8)

  auto const cloud = builder.build();

  EXPECT_FLOAT_EQ(1.0f, cloud.getFieldValue<float>(FieldType::X, 0));
  EXPECT_FLOAT_EQ(2.0f, cloud.getFieldValue<float>(FieldType::Y, 0));
  EXPECT_FLOAT_EQ(3.0f, cloud.getFieldValue<float>(FieldType::Z, 0));
  EXPECT_EQ(4, cloud.getFieldValue<std::uint32_t>(FieldType::TimeOffsetNanoseconds, 0));
  EXPECT_EQ(5, cloud.getFieldValue<std::uint32_t>(FieldType::TimeOffsetSeconds, 0));
  EXPECT_EQ(6, cloud.getFieldValue<std::uint8_t>(FieldType::Ring, 0));
}

TEST(UnorganizedPointCloudBuilderTest, build_sets_height_to_one)
{
  constexpr std::size_t numberOfPoints = 10;
  auto const config                    = createConfiguration();
  sick::UnorganizedPointCloudBuilder builder(sick::Timestamp::fromMicrosecondsSinceEpoch(1000), config, numberOfPoints);

  for (auto i = 0; i < numberOfPoints; ++i)
  {
    builder.beginPoint();
    builder.write(static_cast<float>(i));
    builder.write(static_cast<float>(i));
    builder.write(static_cast<float>(i));
  }

  auto const cloud = builder.build();

  EXPECT_EQ(numberOfPoints, cloud.width());
  EXPECT_EQ(1, cloud.height());
}

TEST(UnorganizedPointCloudBuilderTest, build_sets_density_to_all_points_valid)
{
  auto const config = createConfiguration();
  sick::UnorganizedPointCloudBuilder builder(sick::Timestamp::fromMicrosecondsSinceEpoch(1000), config, 1);

  builder.beginPoint();
  builder.write(1.0f);
  builder.write(2.0f);
  builder.write(3.0f);

  auto const cloud = builder.build();

  EXPECT_EQ(Density::AllPointsValid, cloud.density());
}

TEST(UnorganizedPointCloudBuilderTest, build_sets_number_of_echoes_per_beam_to_one)
{
  auto const config = createConfiguration();
  sick::UnorganizedPointCloudBuilder builder(sick::Timestamp::fromMicrosecondsSinceEpoch(1000), config, 1);

  builder.beginPoint();
  builder.write(1.0f);
  builder.write(2.0f);
  builder.write(3.0f);

  auto const cloud = builder.build();

  EXPECT_EQ(1, cloud.numberOfEchoesPerBeam());
}

TEST(UnorganizedPointCloudBuilderTest, setPointCloudTimestamp_updates_timestamp)
{
  auto const config    = createConfiguration();
  auto const initialTs = sick::Timestamp::fromMicrosecondsSinceEpoch(100);
  auto const updatedTs = sick::Timestamp::fromMicrosecondsSinceEpoch(999999);
  sick::UnorganizedPointCloudBuilder builder(initialTs, config, 1);

  builder.setPointCloudTimestamp(updatedTs);
  auto const cloud = builder.build();

  EXPECT_EQ(updatedTs, cloud.timestamp());
}

TEST(UnorganizedPointCloudBuilderTest, beginPoint_throws_if_max_number_of_points_exceeded)
{
  auto const config = createConfiguration();
  sick::UnorganizedPointCloudBuilder builder(sick::Timestamp::fromMicrosecondsSinceEpoch(1000), config, 1);

  builder.beginPoint();
  builder.write(1.0f);
  builder.write(2.0f);
  builder.write(3.0f);

  EXPECT_THROW(builder.beginPoint(), std::runtime_error);
}

TEST(UnorganizedPointCloudBuilderTest, growBy_allows_adding_more_points)
{
  auto const config = createConfiguration();
  sick::UnorganizedPointCloudBuilder builder(sick::Timestamp::fromMicrosecondsSinceEpoch(1000), config, 1);

  builder.beginPoint();
  builder.write(1.0f);
  builder.write(2.0f);
  builder.write(3.0f);

  builder.growBy(2); // Increase max number of points to 3

  builder.beginPoint();
  builder.write(4.0f);
  builder.write(5.0f);
  builder.write(6.0f);

  builder.beginPoint();
  builder.write(7.0f);
  builder.write(8.0f);
  builder.write(9.0f);

  auto const cloud = builder.build();

  EXPECT_EQ(3, cloud.numberOfPoints());
  EXPECT_FLOAT_EQ(1.0f, cloud.getFieldValue<float>(FieldType::X, 0));
  EXPECT_FLOAT_EQ(2.0f, cloud.getFieldValue<float>(FieldType::Y, 0));
  EXPECT_FLOAT_EQ(3.0f, cloud.getFieldValue<float>(FieldType::Z, 0));

  EXPECT_FLOAT_EQ(4.0f, cloud.getFieldValue<float>(FieldType::X, 1));
  EXPECT_FLOAT_EQ(5.0f, cloud.getFieldValue<float>(FieldType::Y, 1));
  EXPECT_FLOAT_EQ(6.0f, cloud.getFieldValue<float>(FieldType::Z, 1));

  EXPECT_FLOAT_EQ(7.0f, cloud.getFieldValue<float>(FieldType::X, 2));
  EXPECT_FLOAT_EQ(8.0f, cloud.getFieldValue<float>(FieldType::Y, 2));
  EXPECT_FLOAT_EQ(9.0f, cloud.getFieldValue<float>(FieldType::Z, 2));
}

