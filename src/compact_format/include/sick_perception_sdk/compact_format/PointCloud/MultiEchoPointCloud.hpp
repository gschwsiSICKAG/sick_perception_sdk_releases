/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

#pragma once

#include <sick_perception_sdk/common/export.hpp>
#include <sick_perception_sdk/common/quantities/Timestamp.hpp>

#include <algorithm>
#include <cstdint>
#include <cstring>
#include <vector>

namespace sick {

class OrganizedPointCloudBuilder;
class UnorganizedPointCloudBuilder;

/**
 * @brief Data structure representing a multi-echo point cloud.
 *
 * This is the common transfer format for point clouds in the sick_perception_sdk.
 *
 * The sick_perception_sdk provides converters from Compact format representations that contain data convertible to point clouds
 * into this point cloud structure.
 *
 * @see `sick::compact::scan_data::PointCloudConverter`
 * @see `sick::multiscan200::PointCloudConverter`
 * 
 * The order of fields in the raw data is defined by the order of `fields` in the point cloud.
 * The offset and datatype information for each field can be used to interpret the point data correctly.
 * 
 * **Data Layout:**
 * 
 * For *organized point clouds* the point values are stored in a row-major order with all echoes of a point forming a tuple.
 * The first `width * numberOfEchoesPerBeam` points in `m_data` belong to the first row,
 * the second `width` points belong to the second row, and so on. 
 * 
 * An example is given below.
 * 
 * ```
 * memory address:   0                                           ...        width * height * numberOfEchoesPerBeam * pointSizeBytes - 1
 *                   |                                                                                                             |
 *                   v                                                                                                             v
 *                 +-----------------------------------+-----------------------------------+ ... +-----------------------------------+
 *                 | x | y | z | x | y | z | x | y | z | x | y | z | x | y | z | x | y | z | ... | x | y | z | x | y | z | x | y | z |
 *                 + ----------------------------------+ ----------------------------------+ ... + ----------------------------------+
 *                 |  echo 0   |  echo 1   |  echo 2   |  echo 0   |  echo 1   |  echo 2   | ... |  echo 0   |  echo 1   |  echo 2   |
 *                 |          row 0 column 0           |          row 0 column 1           | ... |   row (height-1) column (width-1) |
 * ```
 * 
 * For *unorganized point clouds* the point values are stored sequentially without any particular order.
 */
class SDK_EXPORT MultiEchoPointCloud
{
public:
  enum class Organization
  {
    Unorganized, ///< Points have no particular structure => height == 1.
    Organized    ///< Points arranged in a width x height grid => height > 1.
  };

  enum class Density
  {
    AllPointsValid,        ///< Point cloud is dense, i.e. all points are valid (no NaN coordinates).
    InvalidPointsContained ///< Point cloud is sparse, i.e. may contain invalid points (NaN coordinates, 0 for integers).
  };

  struct SDK_EXPORT PointField
  {
    enum class DataType
    {
      Bool    = 0,
      Int8    = 1,
      Uint8   = 2,
      Int16   = 3,
      Uint16  = 4,
      Int32   = 5,
      Uint32  = 6,
      Int64   = 7,
      Uint64  = 8,
      Float32 = 9,
      Float64 = 10,
    };

    enum class FieldType
    {
      X,
      Y,
      Z,
      Range,
      Azimuth,
      Elevation,
      Intensity,
      TimeOffsetNanoseconds,
      TimeOffsetSeconds,
      Ring,
      Layer,
      Echo,
      IsReflector,
      HasBlooming,
      PulseWidth,
    };

    FieldType fieldType  = FieldType::X;
    std::uint32_t offset = 0;
    DataType dataType    = DataType::Float32;
  };

  // Classes that can create point clouds get access to the raw data.
  friend class OrganizedPointCloudBuilder;
  friend class UnorganizedPointCloudBuilder;

  /**
   * @param timestamp Timestamp of the point cloud, typically the timestamp of the corresponding scan or frame.
   * @param width Number of columns of the sensor for organized point clouds; total number of points for unorganized point clouds.
   * @param height Number of rows/layers for organized point clouds; must be 1 for unorganized point clouds.
   * @param numberOfEchoesPerBeam Number of echoes per beam for organized point clouds; must be 1 for unorganized point clouds.
   * @param organization Whether the point cloud is organized (points arranged in a grid) or unorganized (points have no particular order).
   * @param density Whether the point cloud is dense (all points valid) or sparse (contains invalid points).
   * @param fields Vector of field definitions, including offset and dataType information for each field. The order of fields defines the order of data in the raw byte array.
   * @param pointSizeBytes Total size of one point in bytes, used to calculate offsets for accessing point data.
   */
  explicit MultiEchoPointCloud(
    Timestamp timestamp,
    std::size_t width,
    std::size_t height,
    std::size_t numberOfEchoesPerBeam,
    Organization organization,
    Density density,
    std::vector<PointField> fields,
    std::uint32_t pointSizeBytes
  );

  /**
   * @brief Access a field value by point index.
   * 
   * @param fieldType The type of the field to access.
   * @param pointIndex The linear index of the point (0 to numberOfPoints-1).
   * 
   * @throws std::out_of_range if point index is out of bounds or field not found.
   */
  template <typename ValueT>
  auto getFieldValue(PointField::FieldType fieldType, std::size_t pointIndex) const -> ValueT
  {
    auto it = std::find_if(m_fields.begin(), m_fields.end(), [fieldType](PointField const& field) -> bool {
      return field.fieldType == fieldType;
    });
    if (it == m_fields.end())
    {
      throw std::out_of_range("Field not found");
    }

    auto const byteIndexForPoint = it->offset + pointIndex * m_pointSizeBytes;
    if (byteIndexForPoint + sizeof(ValueT) > m_data.size())
    {
      throw std::out_of_range("Point index out of range");
    }

    std::uint8_t const* dataPtr = &m_data[byteIndexForPoint];
    return convertFromRuntimeType<ValueT>(dataPtr, it->dataType);
  }

  /**
   * @brief Access a field value by grid coordinates.
   * 
   * @throws std::logic_error if the point cloud is unorganized.
   * @throws std::out_of_range if coordinates are out of bounds or field not found.
   */
  template <typename ValueT>
  auto getFieldValue(PointField::FieldType fieldType, std::size_t column, std::size_t row, std::size_t echoIndex) const -> ValueT
  {
    return getFieldValue<ValueT>(fieldType, pointIndex(column, row, echoIndex));
  }

  auto density() const -> Density
  {
    return m_density;
  }

  auto fields() const -> std::vector<PointField> const&
  {
    return m_fields;
  }

  auto height() const -> std::size_t
  {
    return m_height;
  }

  auto isEmpty() const -> bool
  {
    return m_data.empty();
  }

  auto numberOfEchoesPerBeam() const -> std::size_t
  {
    return m_numberOfEchoesPerBeam;
  }

  auto numberOfBeams() const -> std::size_t
  {
    return m_width * m_height;
  }

  auto numberOfPoints() const -> std::size_t
  {
    return numberOfBeams() * numberOfEchoesPerBeam();
  }

  auto organization() const -> Organization
  {
    return m_organization;
  }

  auto pointSizeBytes() const -> std::uint32_t
  {
    return m_pointSizeBytes;
  }

  auto rawBytes() const -> std::uint8_t const*
  {
    return m_data.data();
  }

  auto rawByteSize() const -> std::size_t
  {
    return m_data.size();
  }

  auto timestamp() const -> Timestamp
  {
    return m_timestamp;
  }

  auto width() const -> std::size_t
  {
    return m_width;
  }

private:
  Timestamp m_timestamp               = Timestamp::fromMicrosecondsSinceEpoch(0);
  std::size_t m_width                 = 0; ///< Number of columns (organized) or total points (unorganized).
  std::size_t m_height                = 1; ///< Number of rows/layers (organized) or 1 (unorganized).
  std::size_t m_numberOfEchoesPerBeam = 1; ///< Number of echoes per beam (organized) or 1 (unorganized).
  Organization m_organization         = Organization::Unorganized;
  Density m_density                   = Density::AllPointsValid;
  std::vector<PointField> m_fields;
  std::uint32_t m_pointSizeBytes = 0;
  std::vector<std::uint8_t> m_data; ///< Actual point data, size is (number of points * point step).

  /**
   * @brief Private ctor for friends who know what they are doing.
   */
  MultiEchoPointCloud() = default;

  /**
   * @brief Returns the linear point index for grid coordinates.
   *
   * Data is stored in row-major order: all columns and echoes for a row are stored
   * before moving to the next row.
   *
   * @param column Column index (0 to numberOfColumns-1, where numberOfColumns = width / numberOfEchoesPerBeam).
   * @param row Row/layer index (0 to height-1).
   * @param echoIndex Echo index (0 to numberOfEchoesPerBeam-1).
   * @throws std::logic_error if the point cloud is unorganized.
   * @throws std::out_of_range if coordinates are out of bounds.
   */
  auto pointIndex(std::size_t column, std::size_t row, std::size_t echoIndex) const -> std::size_t;

  template <typename OutputT>
  static auto convertFromRuntimeType(std::uint8_t const* dataPtr, PointField::DataType runtimeType) -> OutputT
  {
    // NOLINTBEGIN(cppcoreguidelines-init-variables) variables are not initialized intentionally to avoid unnecessary initialization overhead before memcpy
    switch (runtimeType)
    {
    case PointField::DataType::Bool:
    {
      std::uint8_t value;
      std::memcpy(&value, dataPtr, sizeof(std::uint8_t));
      return static_cast<OutputT>(value != 0);
    }
    case PointField::DataType::Int8:
    {
      std::int8_t value;
      std::memcpy(&value, dataPtr, sizeof(std::int8_t));
      return static_cast<OutputT>(value);
    }
    case PointField::DataType::Uint8:
    {
      std::uint8_t value;
      std::memcpy(&value, dataPtr, sizeof(std::uint8_t));
      return static_cast<OutputT>(value);
    }
    case PointField::DataType::Int16:
    {
      std::int16_t value;
      std::memcpy(&value, dataPtr, sizeof(std::int16_t));
      return static_cast<OutputT>(value);
    }
    case PointField::DataType::Uint16:
    {
      std::uint16_t value;
      std::memcpy(&value, dataPtr, sizeof(std::uint16_t));
      return static_cast<OutputT>(value);
    }
    case PointField::DataType::Int32:
    {
      std::int32_t value;
      std::memcpy(&value, dataPtr, sizeof(std::int32_t));
      return static_cast<OutputT>(value);
    }
    case PointField::DataType::Uint32:
    {
      std::uint32_t value;
      std::memcpy(&value, dataPtr, sizeof(std::uint32_t));
      return static_cast<OutputT>(value);
    }
    case PointField::DataType::Int64:
    {
      std::int64_t value;
      std::memcpy(&value, dataPtr, sizeof(std::int64_t));
      return static_cast<OutputT>(value);
    }
    case PointField::DataType::Uint64:
    {
      std::uint64_t value;
      std::memcpy(&value, dataPtr, sizeof(std::uint64_t));
      return static_cast<OutputT>(value);
    }
    case PointField::DataType::Float32:
    {
      float value;
      std::memcpy(&value, dataPtr, sizeof(float));
      return static_cast<OutputT>(value);
    }
    case PointField::DataType::Float64:
    {
      double value;
      std::memcpy(&value, dataPtr, sizeof(double));
      return static_cast<OutputT>(value);
    }
    default:
      throw std::invalid_argument("Unsupported PointField::DataType");
    }
    // NOLINTEND(cppcoreguidelines-init-variables)
  }
};

} // namespace sick
