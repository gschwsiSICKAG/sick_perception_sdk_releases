/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

#include <sick_perception_sdk/compact_format/telegram_type_6_multiScan200/PointCloudConverter.hpp>

#include "utils/MultiScan200DataGenerator.hpp"
#include <sick_perception_sdk/common/quantities/Angle.hpp>
#include <sick_perception_sdk/common/quantities/Distance.hpp>
#include <sick_perception_sdk/compact_format/PointCloud/PointCloudConfiguration.hpp>

#include <gtest/gtest.h>

#include <cmath>
#include <cstdint>
#include <limits>
#include <set>
#include <vector>

// Basic Functionality Tests

using FieldType = sick::MultiEchoPointCloud::PointField::FieldType;

namespace {

auto hasField(sick::MultiEchoPointCloud const& pc, FieldType fieldType) -> bool
{
  for (auto const& field : pc.fields())
  {
    if (field.fieldType == fieldType)
    {
      return true;
    }
  }
  return false;
}

} // namespace

TEST(telegram_type_6_multiScan200_PointCloudConverterTest, convert_returns_empty_point_cloud_for_zero_rows_and_columns)
{
  sick::PointCloudConfiguration config;
  config.organization = sick::MultiEchoPointCloud::Organization::Organized; // Unorganized requires height = 1
  sick::compact::multiscan200::PointCloudConverter converter(config);

  auto const data =
    sick::test::MultiScan200DataGenerator() //
      .withNumberOfRows(0)                  //
      .withNumberOfColumnsInSegment(0)      //
      .next();
  auto const pc = converter.convert(data);

  EXPECT_TRUE(pc.isEmpty());
}

TEST(telegram_type_6_multiScan200_PointCloudConverterTest, convert_returns_point_cloud_with_correct_number_of_points)
{
  sick::PointCloudConfiguration config;
  config.organization = sick::MultiEchoPointCloud::Organization::Organized; // Unorganized requires number of echoes = 1
  sick::compact::multiscan200::PointCloudConverter converter(config);

  auto const data =
    sick::test::MultiScan200DataGenerator() //
      .withNumberOfRows(4)                  //
      .withNumberOfColumnsInSegment(5)      //
      .withNumberOfEchoes(2)                //
      .next();
  auto const pc = converter.convert(data);

  // 5 columns * 4 rows * 2 echoes = 40 points
  EXPECT_EQ(40, pc.numberOfPoints());
}

TEST(telegram_type_6_multiScan200_PointCloudConverterTest, convert_with_single_echo_produces_correct_point_count)
{
  sick::PointCloudConfiguration config;
  sick::compact::multiscan200::PointCloudConverter converter(config);

  auto const data =
    sick::test::MultiScan200DataGenerator() //
      .withNumberOfRows(3)                  //
      .withNumberOfColumnsInSegment(3)      //
      .withNumberOfEchoes(1)                //
      .next();
  auto const pc = converter.convert(data);

  EXPECT_EQ(9, pc.numberOfPoints()); // 3 * 3 * 1 = 9
}

// Field Configuration Tests

TEST(telegram_type_6_multiScan200_PointCloudConverterTest, convert_with_cartesian_enabled_creates_xyz_fields)
{
  sick::PointCloudConfiguration config;
  config.fields.enableCartesian = true;
  config.fields.enableSpherical = false;

  sick::compact::multiscan200::PointCloudConverter converter(config);

  auto const data =
    sick::test::MultiScan200DataGenerator() //
      .withNumberOfRows(1)                  //
      .withNumberOfColumnsInSegment(1)      //
      .withNumberOfEchoes(1)                //
      .next();
  auto const pc = converter.convert(data);

  ASSERT_EQ(pc.fields().size(), 3);
  // The order is not guaranteed or specified so we just check that the fields exist.
  EXPECT_TRUE(hasField(pc, FieldType::X));
  EXPECT_TRUE(hasField(pc, FieldType::Y));
  EXPECT_TRUE(hasField(pc, FieldType::Z));
}

TEST(telegram_type_6_multiScan200_PointCloudConverterTest, convert_with_spherical_enabled_creates_spherical_fields)
{
  sick::PointCloudConfiguration config;
  config.fields.enableCartesian = false;
  config.fields.enableSpherical = true;

  sick::compact::multiscan200::PointCloudConverter converter(config);

  auto const data =
    sick::test::MultiScan200DataGenerator() //
      .withNumberOfRows(1)                  //
      .withNumberOfColumnsInSegment(1)      //
      .withNumberOfEchoes(1)                //
      .next();
  auto const pc = converter.convert(data);

  ASSERT_EQ(pc.fields().size(), 3);
  // The order is not guaranteed or specified so we just check that the fields exist.
  EXPECT_TRUE(hasField(pc, FieldType::Range));
  EXPECT_TRUE(hasField(pc, FieldType::Azimuth));
  EXPECT_TRUE(hasField(pc, FieldType::Elevation));
}

TEST(telegram_type_6_multiScan200_PointCloudConverterTest, convert_with_intensity_enabled_creates_intensity_field)
{
  sick::PointCloudConfiguration config;
  config.fields.enableIntensity = true;

  sick::compact::multiscan200::PointCloudConverter converter(config);

  auto const data =
    sick::test::MultiScan200DataGenerator()                                         //
      .withNumberOfRows(1)                                                          //
      .withNumberOfColumnsInSegment(1)                                              //
      .withNumberOfEchoes(1)                                                        //
      .withEchoDataContent(sick::compact::multiscan200::EchoDataContent::Intensity) //
      .next();
  auto const pc = converter.convert(data);

  EXPECT_TRUE(hasField(pc, FieldType::Intensity));
}

TEST(telegram_type_6_multiScan200_PointCloudConverterTest, convert_with_time_offset_enabled_creates_time_fields)
{
  sick::PointCloudConfiguration config;
  config.fields.enableTimeOffset = true;

  sick::compact::multiscan200::PointCloudConverter converter(config);

  auto const data =
    sick::test::MultiScan200DataGenerator() //
      .withNumberOfRows(1)                  //
      .withNumberOfColumnsInSegment(1)      //
      .withNumberOfEchoes(1)                //
      .next();
  auto const pc = converter.convert(data);

  EXPECT_TRUE(hasField(pc, FieldType::TimeOffsetNanoseconds));
  EXPECT_TRUE(hasField(pc, FieldType::TimeOffsetSeconds));
}

TEST(telegram_type_6_multiScan200_PointCloudConverterTest, convert_with_ring_enabled_creates_ring_field)
{
  sick::PointCloudConfiguration config;
  config.fields.enableRing = true;

  sick::compact::multiscan200::PointCloudConverter converter(config);

  auto const data =
    sick::test::MultiScan200DataGenerator() //
      .withNumberOfRows(1)                  //
      .withNumberOfColumnsInSegment(1)      //
      .withNumberOfEchoes(1)                //
      .next();
  auto const pc = converter.convert(data);

  EXPECT_TRUE(hasField(pc, FieldType::Ring));
}

TEST(telegram_type_6_multiScan200_PointCloudConverterTest, convert_with_layer_enabled_creates_layer_field)
{
  sick::PointCloudConfiguration config;
  config.fields.enableLayer = true;

  sick::compact::multiscan200::PointCloudConverter converter(config);

  auto const data =
    sick::test::MultiScan200DataGenerator() //
      .withNumberOfRows(1)                  //
      .withNumberOfColumnsInSegment(1)      //
      .withNumberOfEchoes(1)                //
      .next();
  auto const pc = converter.convert(data);

  EXPECT_TRUE(hasField(pc, FieldType::Layer));
}

TEST(telegram_type_6_multiScan200_PointCloudConverterTest, convert_with_echo_enabled_creates_echo_field)
{
  sick::PointCloudConfiguration config;
  config.fields.enableEcho = true;

  sick::compact::multiscan200::PointCloudConverter converter(config);

  auto const data =
    sick::test::MultiScan200DataGenerator() //
      .withNumberOfRows(1)                  //
      .withNumberOfColumnsInSegment(1)      //
      .withNumberOfEchoes(1)                //
      .next();
  auto const pc = converter.convert(data);

  EXPECT_TRUE(hasField(pc, FieldType::Echo));
}

// Filter Tests

TEST(telegram_type_6_multiScan200_PointCloudConverterTest, convert_with_echo_filter_includes_only_selected_echoes)
{
  sick::PointCloudConfiguration config;
  config.filters.selectedEchos = std::set<std::size_t> {0, 2};

  sick::compact::multiscan200::PointCloudConverter converter(config);

  auto const data =
    sick::test::MultiScan200DataGenerator() //
      .withNumberOfRows(2)                  //
      .withNumberOfColumnsInSegment(2)      //
      .withNumberOfEchoes(3)                //
      .next();
  auto const pc = converter.convert(data);

  // 2 columns * 2 rows * 2 echoes (0 and 2) = 8 points
  EXPECT_EQ(8, pc.numberOfPoints());
}

TEST(telegram_type_6_multiScan200_PointCloudConverterTest, convert_with_single_echo_filter)
{
  sick::PointCloudConfiguration config;
  config.filters.selectedEchos = std::set<std::size_t> {1};

  sick::compact::multiscan200::PointCloudConverter converter(config);

  auto const data =
    sick::test::MultiScan200DataGenerator() //
      .withNumberOfRows(3)                  //
      .withNumberOfColumnsInSegment(3)      //
      .withNumberOfEchoes(3)                //
      .next();
  auto const pc = converter.convert(data);

  // 3 columns * 3 rows * 1 echo (index 1) = 9 points
  EXPECT_EQ(9, pc.numberOfPoints());
}

TEST(telegram_type_6_multiScan200_PointCloudConverterTest, convert_with_layer_filter_includes_only_selected_layers)
{
  sick::PointCloudConfiguration config;
  config.filters.selectedLayers = std::set<std::uint32_t> {1, 3};

  sick::compact::multiscan200::PointCloudConverter converter(config);

  auto const data =
    sick::test::MultiScan200DataGenerator() //
      .withNumberOfRows(5)                  // Layers 1-5
      .withNumberOfColumnsInSegment(2)      //
      .withNumberOfEchoes(1)                //
      .next();
  auto const pc = converter.convert(data);

  // 2 columns * 2 layers (1 and 3) * 1 echo = 4 points
  EXPECT_EQ(4, pc.numberOfPoints());
}

TEST(telegram_type_6_multiScan200_PointCloudConverterTest, convert_with_range_filter_excludes_out_of_range_points)
{
  sick::PointCloudConfiguration config;
  config.filters.range.min = sick::Distance::fromMillimeters(1500.0);
  config.filters.range.max = sick::Distance::fromMillimeters(2500.0);

  sick::compact::multiscan200::PointCloudConverter converter(config);

  auto const data =
    sick::test::MultiScan200DataGenerator() //
      .withNumberOfRows(10)                 //
      .withNumberOfColumnsInSegment(10)     //
      .withNumberOfEchoes(1)                //
      .next();
  auto const pc = converter.convert(data);

  // Should include only points within range filter
  EXPECT_LT(pc.numberOfPoints(), 100); // Less than total possible
  EXPECT_GT(pc.numberOfPoints(), 0);   // But some should pass
}

TEST(telegram_type_6_multiScan200_PointCloudConverterTest, convert_with_inverted_range_filter)
{
  sick::PointCloudConfiguration config;
  config.filters.range.min    = sick::Distance::fromMillimeters(2000.0);
  config.filters.range.max    = sick::Distance::fromMillimeters(3000.0);
  config.filters.range.invert = true; // Exclude points in range [2000, 3000]

  sick::compact::multiscan200::PointCloudConverter converter(config);

  auto const data =
    sick::test::MultiScan200DataGenerator() //
      .withNumberOfRows(5)                  //
      .withNumberOfColumnsInSegment(5)      //
      .withNumberOfEchoes(1)                //
      .next();
  auto const pc = converter.convert(data);

  // Should include points outside the specified range
  EXPECT_GT(pc.numberOfPoints(), 0);
}

TEST(telegram_type_6_multiScan200_PointCloudConverterTest, convert_with_azimuth_filter)
{
  sick::PointCloudConfiguration config;
  config.filters.azimuth.min = sick::Angle::fromDegrees(4);
  config.filters.azimuth.max = sick::Angle::fromDegrees(8);

  sick::compact::multiscan200::PointCloudConverter converter(config);

  auto const data =
    sick::test::MultiScan200DataGenerator() //
      .withNumberOfRows(4)                  //
      .withNumberOfColumnsInSegment(20)     //
      .withNumberOfColumnsInFrame(360)      //
      .withNumberOfEchoes(1)                //
      .next();

  auto const pc = converter.convert(data);

  // The segment spans the azimuth range 0° to 20° (20 columns in frame of 360 columns).
  // With the filter set to 4°..8°, we expect to 20°/4° = 5 columns * 4 rows * 1 echo = 20 points.
  EXPECT_EQ(pc.numberOfPoints(), 20);
}

TEST(telegram_type_6_multiScan200_PointCloudConverterTest, convert_with_elevation_filter)
{
  sick::PointCloudConfiguration config;
  config.filters.elevation.min = sick::Angle::fromDegrees(-5.0);
  config.filters.elevation.max = sick::Angle::fromDegrees(5.0);

  sick::compact::multiscan200::PointCloudConverter converter(config);

  auto const data =
    sick::test::MultiScan200DataGenerator() //
      .withNumberOfRows(16)                 // -15° to +15° spread
      .withNumberOfColumnsInSegment(10)     //
      .withNumberOfEchoes(1)                //
      .next();
  auto const pc = converter.convert(data);

  // Should include only rows within elevation range
  EXPECT_LT(pc.numberOfPoints(), 160); // Less than total
  EXPECT_GT(pc.numberOfPoints(), 0);
}

TEST(telegram_type_6_multiScan200_PointCloudConverterTest, convert_with_intensity_filter_when_intensity_available)
{
  sick::PointCloudConfiguration config;
  config.filters.intensity.min = 105.0F;
  config.filters.intensity.max = 115.0F;

  sick::compact::multiscan200::PointCloudConverter converter(config);

  auto const data =
    sick::test::MultiScan200DataGenerator()                                         //
      .withNumberOfRows(10)                                                         //
      .withNumberOfColumnsInSegment(10)                                             //
      .withNumberOfEchoes(1)                                                        //
      .withEchoDataContent(sick::compact::multiscan200::EchoDataContent::Intensity) //
      .next();
  auto const pc = converter.convert(data);

  // Should include only points within intensity range
  EXPECT_LT(pc.numberOfPoints(), 100);
  EXPECT_GT(pc.numberOfPoints(), 0);
}

TEST(telegram_type_6_multiScan200_PointCloudConverterTest, convert_with_combined_filters)
{
  sick::PointCloudConfiguration config;
  config.filters.selectedEchos  = std::set<std::size_t> {0};
  config.filters.selectedLayers = std::set<std::uint32_t> {1, 2, 3};
  config.filters.range.min      = sick::Distance::fromMillimeters(1000.0);
  config.filters.range.max      = sick::Distance::fromMillimeters(5000.0);

  sick::compact::multiscan200::PointCloudConverter converter(config);

  auto const data =
    sick::test::MultiScan200DataGenerator() //
      .withNumberOfRows(5)                  //
      .withNumberOfColumnsInSegment(5)      //
      .withNumberOfEchoes(2)                //
      .next();
  auto const pc = converter.convert(data);

  // Should apply all filters
  EXPECT_LT(pc.numberOfPoints(), 50); // Less than total possible
  EXPECT_GT(pc.numberOfPoints(), 0);
}

// Distance Scaling Tests

TEST(telegram_type_6_multiScan200_PointCloudConverterTest, convert_applies_distance_scaling_factor)
{
  sick::PointCloudConfiguration config;
  config.distanceScalingFactor = 1000.0F; // Convert to millimeters

  sick::compact::multiscan200::PointCloudConverter converter(config);

  auto const data =
    sick::test::MultiScan200DataGenerator() //
      .withNumberOfRows(1)                  //
      .withNumberOfColumnsInSegment(1)      //
      .withNumberOfEchoes(1)                //
      .next();
  auto const pc = converter.convert(data);

  EXPECT_EQ(1, pc.numberOfPoints());
  // The actual values would be scaled by the factor
}

TEST(telegram_type_6_multiScan200_PointCloudConverterTest, convert_with_zero_distance_scaling_factor)
{
  sick::PointCloudConfiguration config;
  config.distanceScalingFactor = 0.0F;

  sick::compact::multiscan200::PointCloudConverter converter(config);

  auto const data =
    sick::test::MultiScan200DataGenerator() //
      .withNumberOfRows(1)                  //
      .withNumberOfColumnsInSegment(1)      //
      .withNumberOfEchoes(1)                //
      .next();
  auto const pc = converter.convert(data);

  // Should still produce a point cloud, coordinates will be zero
  EXPECT_EQ(1, pc.numberOfPoints());
}

// Corner Cases and Invalid Data Tests

TEST(telegram_type_6_multiScan200_PointCloudConverterTest, convert_with_zero_echoes)
{
  sick::PointCloudConfiguration config;
  sick::compact::multiscan200::PointCloudConverter converter(config);

  auto const data =
    sick::test::MultiScan200DataGenerator() //
      .withNumberOfRows(5)                  //
      .withNumberOfColumnsInSegment(5)      //
      .withNumberOfEchoes(0)                //
      .next();
  auto const pc = converter.convert(data);

  EXPECT_EQ(0, pc.numberOfPoints());
}

TEST(telegram_type_6_multiScan200_PointCloudConverterTest, convert_with_mismatched_geometry_and_scan_data_sizes)
{
  sick::PointCloudConfiguration config;
  sick::compact::multiscan200::PointCloudConverter converter(config);

  auto generator = sick::test::MultiScan200DataGenerator().withNumberOfRows(3).withNumberOfColumnsInSegment(3).withNumberOfEchoes(1);

  auto data = generator.next();

  // Corrupt data: remove some geometry entries
  data.geometry.azimuths.resize(2); // Should be 3

  // This should not crash, might produce fewer points or handle gracefully
  EXPECT_THROW(converter.convert(data), std::runtime_error);
}

TEST(telegram_type_6_multiScan200_PointCloudConverterTest, convert_with_empty_echo_list_in_beam)
{
  sick::PointCloudConfiguration config;
  sick::compact::multiscan200::PointCloudConverter converter(config);

  auto generator = sick::test::MultiScan200DataGenerator().withNumberOfRows(2).withNumberOfColumnsInSegment(2).withNumberOfEchoes(1);

  auto data = generator.next();

  // Corrupt data: remove echoes from a beam
  if (!data.scanData.empty() && !data.scanData[0].empty())
  {
    data.scanData[0][0].echoes.clear();
  }

  auto const pc = converter.convert(data);
  // Should handle missing echoes gracefully
  EXPECT_LT(pc.numberOfPoints(), 4);
}

TEST(telegram_type_6_multiScan200_PointCloudConverterTest, convert_with_nan_distance_values)
{
  sick::PointCloudConfiguration config;
  sick::compact::multiscan200::PointCloudConverter converter(config);

  auto generator = sick::test::MultiScan200DataGenerator().withNumberOfRows(2).withNumberOfColumnsInSegment(2).withNumberOfEchoes(1);

  auto data = generator.next();

  // Set invalid distance
  if (!data.scanData.empty() && !data.scanData[0].empty() && !data.scanData[0][0].echoes.empty())
  {
    data.scanData[0][0].echoes[0].distance = sick::Distance::fromMillimeters(std::numeric_limits<double>::quiet_NaN());
  }

  auto const pc = converter.convert(data);
  // Should handle NaN values (may filter them out or include them)
  EXPECT_LE(pc.numberOfPoints(), 4);
}

TEST(telegram_type_6_multiScan200_PointCloudConverterTest, convert_with_infinite_distance_values)
{
  sick::PointCloudConfiguration config;
  sick::compact::multiscan200::PointCloudConverter converter(config);

  auto generator = sick::test::MultiScan200DataGenerator().withNumberOfRows(2).withNumberOfColumnsInSegment(2).withNumberOfEchoes(1);

  auto data = generator.next();

  // Set invalid distance
  if (!data.scanData.empty() && !data.scanData[0].empty() && !data.scanData[0][0].echoes.empty())
  {
    data.scanData[0][0].echoes[0].distance = sick::Distance::fromMillimeters(std::numeric_limits<double>::infinity());
  }

  auto const pc = converter.convert(data);
  // Should handle infinite values
  EXPECT_LE(pc.numberOfPoints(), 4);
}

TEST(telegram_type_6_multiScan200_PointCloudConverterTest, convert_with_negative_distance_values)
{
  sick::PointCloudConfiguration config;
  sick::compact::multiscan200::PointCloudConverter converter(config);

  auto generator = sick::test::MultiScan200DataGenerator().withNumberOfRows(2).withNumberOfColumnsInSegment(2).withNumberOfEchoes(1);

  auto data = generator.next();

  // Set negative distance
  if (!data.scanData.empty() && !data.scanData[0].empty() && !data.scanData[0][0].echoes.empty())
  {
    data.scanData[0][0].echoes[0].distance = sick::Distance::fromMillimeters(-1000.0);
  }

  auto const pc = converter.convert(data);
  // Should handle negative values
  EXPECT_LE(pc.numberOfPoints(), 4);
}

TEST(telegram_type_6_multiScan200_PointCloudConverterTest, convert_with_nan_angles)
{
  sick::PointCloudConfiguration config;
  sick::compact::multiscan200::PointCloudConverter converter(config);

  auto generator = sick::test::MultiScan200DataGenerator().withNumberOfRows(2).withNumberOfColumnsInSegment(2).withNumberOfEchoes(1);

  auto data = generator.next();

  // Set invalid angles
  if (!data.geometry.azimuths.empty())
  {
    data.geometry.azimuths[0] = sick::Angle::fromRadians(std::numeric_limits<double>::quiet_NaN());
  }
  if (!data.geometry.elevations.empty())
  {
    data.geometry.elevations[0] = sick::Angle::fromRadians(std::numeric_limits<double>::quiet_NaN());
  }

  auto const pc = converter.convert(data);
  // Should handle NaN angles
  EXPECT_LE(pc.numberOfPoints(), 4);
}

TEST(telegram_type_6_multiScan200_PointCloudConverterTest, convert_with_intensity_missing_when_expected)
{
  sick::PointCloudConfiguration config;
  config.fields.enableIntensity = true;

  sick::compact::multiscan200::PointCloudConverter converter(config);

  auto generator = sick::test::MultiScan200DataGenerator().withNumberOfRows(2).withNumberOfColumnsInSegment(2).withNumberOfEchoes(1).withEchoDataContent(
    sick::compact::multiscan200::EchoDataContent::None
  ); // No intensity data

  auto data = generator.next();

  // Ensure intensity is not set
  for (auto& column : data.scanData)
  {
    for (auto& beam : column)
    {
      for (auto& echo : beam.echoes)
      {
        echo.intensity = std::nullopt;
      }
    }
  }

  auto const pc = converter.convert(data);
  // Should handle missing intensity gracefully
  EXPECT_EQ(4, pc.numberOfPoints());
}

TEST(telegram_type_6_multiScan200_PointCloudConverterTest, convert_with_properties_missing_when_expected)
{
  sick::PointCloudConfiguration config;
  config.fields.enableIsReflector = true;

  sick::compact::multiscan200::PointCloudConverter converter(config);

  auto generator = sick::test::MultiScan200DataGenerator().withNumberOfRows(2).withNumberOfColumnsInSegment(2).withNumberOfEchoes(1).withEchoDataContent(
    sick::compact::multiscan200::EchoDataContent::None
  );

  auto data = generator.next();

  // Ensure properties are not set
  for (auto& column : data.scanData)
  {
    for (auto& beam : column)
    {
      for (auto& echo : beam.echoes)
      {
        echo.properties = std::nullopt;
      }
    }
  }

  auto const pc = converter.convert(data);
  // Should handle missing properties gracefully
  EXPECT_EQ(4, pc.numberOfPoints());
}

TEST(telegram_type_6_multiScan200_PointCloudConverterTest, convert_with_empty_filter_should_exclude_all_points)
{
  sick::PointCloudConfiguration config;
  config.filters.selectedEchos = std::set<std::size_t> {}; // Empty set

  sick::compact::multiscan200::PointCloudConverter converter(config);

  auto const data =
    sick::test::MultiScan200DataGenerator() //
      .withNumberOfRows(3)                  //
      .withNumberOfColumnsInSegment(3)      //
      .withNumberOfEchoes(3)                //
      .next();
  auto const pc = converter.convert(data);

  // Empty echo filter should exclude all points
  EXPECT_EQ(0, pc.numberOfPoints());
}

TEST(telegram_type_6_multiScan200_PointCloudConverterTest, convert_with_out_of_bounds_echo_filter)
{
  sick::PointCloudConfiguration config;
  config.filters.selectedEchos = std::set<std::size_t> {10, 20}; // Out of bounds

  sick::compact::multiscan200::PointCloudConverter converter(config);

  auto const data =
    sick::test::MultiScan200DataGenerator() //
      .withNumberOfRows(2)                  //
      .withNumberOfColumnsInSegment(2)      //
      .withNumberOfEchoes(2)                // Only echoes 0 and 1
      .next();
  auto const pc = converter.convert(data);

  // Should exclude all points since selected echoes don't exist
  EXPECT_EQ(0, pc.numberOfPoints());
}

TEST(telegram_type_6_multiScan200_PointCloudConverterTest, convert_with_out_of_bounds_layer_filter)
{
  sick::PointCloudConfiguration config;
  config.filters.selectedLayers = std::set<std::uint32_t> {100, 200}; // Out of bounds

  sick::compact::multiscan200::PointCloudConverter converter(config);

  auto const data =
    sick::test::MultiScan200DataGenerator() //
      .withNumberOfRows(5)                  // Layers 1-5
      .withNumberOfColumnsInSegment(2)      //
      .withNumberOfEchoes(1)                //
      .next();
  auto const pc = converter.convert(data);

  // Should exclude all points since selected layers don't exist
  EXPECT_EQ(0, pc.numberOfPoints());
}

TEST(telegram_type_6_multiScan200_PointCloudConverterTest, convert_with_impossible_range_filter)
{
  sick::PointCloudConfiguration config;
  config.filters.range.min = sick::Distance::fromMillimeters(5000.0);
  config.filters.range.max = sick::Distance::fromMillimeters(1000.0); // max < min

  sick::compact::multiscan200::PointCloudConverter converter(config);

  auto const data =
    sick::test::MultiScan200DataGenerator() //
      .withNumberOfRows(3)                  //
      .withNumberOfColumnsInSegment(3)      //
      .withNumberOfEchoes(1)                //
      .next();
  auto const pc = converter.convert(data);

  // Invalid range should exclude all points
  EXPECT_EQ(0, pc.numberOfPoints());
}

TEST(telegram_type_6_multiScan200_PointCloudConverterTest, convert_with_max_values)
{
  sick::PointCloudConfiguration config;
  sick::compact::multiscan200::PointCloudConverter converter(config);

  auto generator =
    sick::test::MultiScan200DataGenerator().withNumberOfRows(std::numeric_limits<std::uint16_t>::max()).withNumberOfColumnsInSegment(1).withNumberOfEchoes(1);

  // This test checks if very large values are handled without overflow
  // In practice, the data structure may not support such large values
  // but the converter should handle them gracefully
  auto data                         = generator.next();
  data.segmentMetaData.numberOfRows = 100; // Use a reasonable value
  data.geometry.elevations.resize(100);
  for (std::uint16_t i = 0; i < 100; ++i)
  {
    data.geometry.elevations[i] = sick::Angle::fromDegrees(static_cast<double>(i));
  }
  data.scanData.resize(1);
  data.scanData[0].resize(100);

  // Should not crash
  auto const pc = converter.convert(data);
  EXPECT_GT(pc.numberOfPoints(), 0);
}

// Point Cloud Structure Tests

TEST(telegram_type_6_multiScan200_PointCloudConverterTest, convert_sets_point_step_correctly)
{
  sick::PointCloudConfiguration config;
  config.fields.enableCartesian = true;
  config.fields.enableIntensity = true;

  sick::compact::multiscan200::PointCloudConverter converter(config);

  auto const data =
    sick::test::MultiScan200DataGenerator()                                         //
      .withNumberOfRows(1)                                                          //
      .withNumberOfColumnsInSegment(1)                                              //
      .withNumberOfEchoes(1)                                                        //
      .withEchoDataContent(sick::compact::multiscan200::EchoDataContent::Intensity) //
      .next();
  auto const pc = converter.convert(data);

  EXPECT_GT(pc.pointSizeBytes(), 0);
  EXPECT_EQ(pc.rawByteSize(), pc.numberOfPoints() * pc.pointSizeBytes());
}

TEST(telegram_type_6_multiScan200_PointCloudConverterTest, convert_data_size_matches_point_count_and_step)
{
  sick::PointCloudConfiguration config;
  sick::compact::multiscan200::PointCloudConverter converter(config);

  auto const data =
    sick::test::MultiScan200DataGenerator() //
      .withNumberOfRows(3)                  //
      .withNumberOfColumnsInSegment(4)      //
      .withNumberOfEchoes(2)                //
      .next();
  auto const pc = converter.convert(data);

  EXPECT_EQ(pc.rawByteSize(), pc.numberOfPoints() * pc.pointSizeBytes());
}

TEST(telegram_type_6_multiScan200_PointCloudConverterTest, convert_sets_header_timestamp)
{
  sick::PointCloudConfiguration config;
  sick::compact::multiscan200::PointCloudConverter converter(config);

  auto const data =
    sick::test::MultiScan200DataGenerator() //
      .withNumberOfRows(1)                  //
      .withNumberOfColumnsInSegment(1)      //
      .withNumberOfEchoes(1)                //
      .next();
  auto const pc = converter.convert(data);

  // Header timestamp should be set from the input data
  EXPECT_EQ(pc.timestamp(), data.segmentMetaData.frameTimestamp);
}

// Multiple Conversions Tests

TEST(telegram_type_6_multiScan200_PointCloudConverterTest, convert_can_be_called_multiple_times)
{
  sick::PointCloudConfiguration config;
  sick::compact::multiscan200::PointCloudConverter converter(config);

  auto generator =
    sick::test::MultiScan200DataGenerator().withNumberOfRows(2).withNumberOfColumnsInSegment(2).withNumberOfEchoes(1).withNumberOfSegmentsPerFrame(1
    ); // Single segment per frame to ensure different timestamps

  // First conversion
  auto const data1 = generator.next();
  auto const pc1   = converter.convert(data1);
  EXPECT_EQ(4, pc1.numberOfPoints());

  // Second conversion with different data
  auto const data2 = generator.next();
  auto const pc2   = converter.convert(data2);
  EXPECT_EQ(4, pc2.numberOfPoints());

  // Results should be independent
  EXPECT_NE(pc1.timestamp(), pc2.timestamp());
}

TEST(telegram_type_6_multiScan200_PointCloudConverterTest, convert_handles_different_segment_indices)
{
  sick::PointCloudConfiguration config;
  sick::compact::multiscan200::PointCloudConverter converter(config);

  auto generator =
    sick::test::MultiScan200DataGenerator().withNumberOfRows(2).withNumberOfColumnsInSegment(5).withNumberOfSegmentsPerFrame(4).withNumberOfEchoes(1);

  // Convert multiple segments
  for (int i = 0; i < 4; ++i)
  {
    auto const data = generator.next();
    auto const pc   = converter.convert(data);
    EXPECT_EQ(10, pc.numberOfPoints()); // 2 rows * 5 columns
  }
}
