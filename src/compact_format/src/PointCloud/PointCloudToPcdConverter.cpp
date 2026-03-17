/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

#include <sick_perception_sdk/compact_format/PointCloud/PointCloudToPcdConverter.hpp>

#include <sick_perception_sdk/compact_format/PointCloud/MultiEchoPointCloud.hpp>

#include <cstdint>
#include <cstring> // for std::memcpy
#include <fstream>
#include <iomanip>
#include <ios>
#include <ostream>
#include <stdexcept>

namespace sick::pcd {

namespace {

using FieldType = MultiEchoPointCloud::PointField::FieldType;
using DataType  = MultiEchoPointCloud::PointField::DataType;

auto toPcdFieldName(FieldType type) -> char const*
{
  switch (type)
  {
  case FieldType::X:
    return "x";
  case FieldType::Y:
    return "y";
  case FieldType::Z:
    return "z";
  case FieldType::Range:
    return "range";
  case FieldType::Azimuth:
    return "azimuth";
  case FieldType::Elevation:
    return "elevation";
  case FieldType::Intensity:
    return "intensity";
  case FieldType::TimeOffsetNanoseconds:
    return "t";
  case FieldType::TimeOffsetSeconds:
    return "ts";
  case FieldType::Ring:
    return "ring";
  case FieldType::Layer:
    return "layer";
  case FieldType::Echo:
    return "echo";
  case FieldType::IsReflector:
    return "isReflector";
  case FieldType::HasBlooming:
    return "hasBlooming";
  case FieldType::PulseWidth:
    return "pulseWidth";
  default:
    return "unknown";
  }
}

struct PcdFieldInfo
{
  char type; // 'F', 'I', 'U'
  int size;
};

auto getPcdFieldInfo(DataType type) -> PcdFieldInfo
{
  switch (type)
  {
  case DataType::Bool:
    return {'U', sizeof(bool)};
  case DataType::Int8:
    return {'I', sizeof(std::int8_t)};
  case DataType::Uint8:
    return {'U', sizeof(std::uint8_t)};
  case DataType::Int16:
    return {'I', sizeof(std::int16_t)};
  case DataType::Uint16:
    return {'U', sizeof(std::uint16_t)};
  case DataType::Int32:
    return {'I', sizeof(std::int32_t)};
  case DataType::Uint32:
    return {'U', sizeof(std::uint32_t)};
  case DataType::Int64:
    return {'I', sizeof(std::int64_t)};
  case DataType::Uint64:
    return {'U', sizeof(std::uint64_t)};
  case DataType::Float32:
    return {'F', sizeof(float)};
  case DataType::Float64:
    return {'F', sizeof(double)};
  default:
    throw std::runtime_error("Unsupported PointField datatype");
  }
}

// Helper to write PCD header for all fields
void writePcdHeader(std::ostream& stream, MultiEchoPointCloud const& cloud, bool binary)
{
  stream << "# .PCD v.7 - Point Cloud Data file format\n";
  stream << "VERSION .7\n";
  stream << "FIELDS";
  for (auto const& field : cloud.fields())
  {
    stream << " " << toPcdFieldName(field.fieldType);
  }
  stream << "\nSIZE";
  for (auto const& field : cloud.fields())
  {
    stream << " " << getPcdFieldInfo(field.dataType).size;
  }
  stream << "\nTYPE";
  for (auto const& field : cloud.fields())
  {
    stream << " " << getPcdFieldInfo(field.dataType).type;
  }
  stream << "\nCOUNT";
  for (auto const& field : cloud.fields())
  {
    stream << " 1";
  }
  stream << "\nWIDTH " << cloud.numberOfPoints() << "\nHEIGHT 1\n"; // Always unorganized
  stream << "VIEWPOINT 0 0 0 1 0 0 0\n";
  stream << "POINTS " << cloud.numberOfPoints() << "\n";
  stream << "DATA " << (binary ? "binary" : "ascii") << "\n";
}

// Helper to write one point in ASCII
void writePointAscii(MultiEchoPointCloud const& cloud, std::size_t pointIndex, std::ostream& stream)
{
  constexpr int kFloatPrecision = 6;

  for (std::size_t fieldIndex = 0; fieldIndex < cloud.fields().size(); ++fieldIndex)
  {
    auto const& field = cloud.fields()[fieldIndex];

    switch (field.dataType)
    {
    case DataType::Bool:
    {
      stream << (cloud.getFieldValue<bool>(field.fieldType, pointIndex) ? "1" : "0");
      break;
    }
    case DataType::Int8:
    {
      stream << static_cast<int>(cloud.getFieldValue<std::int8_t>(field.fieldType, pointIndex));
      break;
    }
    case DataType::Uint8:
    {
      stream << static_cast<unsigned int>(cloud.getFieldValue<std::uint8_t>(field.fieldType, pointIndex));
      break;
    }
    case DataType::Int16:
    {
      stream << cloud.getFieldValue<std::int16_t>(field.fieldType, pointIndex);
      break;
    }
    case DataType::Uint16:
    {
      stream << cloud.getFieldValue<std::uint16_t>(field.fieldType, pointIndex);
      break;
    }
    case DataType::Int32:
    {
      stream << cloud.getFieldValue<std::int32_t>(field.fieldType, pointIndex);
      break;
    }
    case DataType::Uint32:
    {
      stream << cloud.getFieldValue<std::uint32_t>(field.fieldType, pointIndex);
      break;
    }
    case DataType::Int64:
    {
      stream << cloud.getFieldValue<std::int64_t>(field.fieldType, pointIndex);
      break;
    }
    case DataType::Uint64:
    {
      stream << cloud.getFieldValue<std::uint64_t>(field.fieldType, pointIndex);
      break;
    }
    case DataType::Float32:
    {
      stream << std::fixed << std::setprecision(kFloatPrecision) << cloud.getFieldValue<float>(field.fieldType, pointIndex);
      break;
    }
    case DataType::Float64:
    {
      stream << std::fixed << std::setprecision(kFloatPrecision) << cloud.getFieldValue<double>(field.fieldType, pointIndex);
      break;
    }
    }

    if (fieldIndex + 1 < cloud.fields().size())
    {
      stream << " ";
    }
  }
  stream << "\n";
}

} // anonymous namespace

void convertToBinary(MultiEchoPointCloud const& pointCloud, std::ostream& outputStream)
{
  writePcdHeader(outputStream, pointCloud, true);
  // NOLINTNEXTLINE(cppcoreguidelines-pro-type-reinterpret-cast)
  outputStream.write(reinterpret_cast<char const*>(pointCloud.rawBytes()), static_cast<std::streamsize>(pointCloud.rawByteSize()));
}

void convertToAscii(MultiEchoPointCloud const& pointCloud, std::ostream& outputStream)
{
  writePcdHeader(outputStream, pointCloud, false);
  for (auto pointIndex = 0; pointIndex < pointCloud.numberOfPoints(); ++pointIndex)
  {
    writePointAscii(pointCloud, pointIndex, outputStream);
  }
}

void writeToAsciiFile(sick::MultiEchoPointCloud const& pointCloud, std::string const& filePath)
{
  // open in binary mode to prevent the compiler from converting \n to \r\n on windows
  std::ofstream file(filePath, std::ios_base::binary);
  if (!file.is_open())
  {
    std::cout << "Could not open file " << filePath << " for writing.\n";
    return;
  }
  convertToAscii(pointCloud, file);
  std::cout << "Wrote point cloud with " << pointCloud.numberOfPoints() << " points to " << filePath << "\n";
  file.close();
}

} // namespace sick::pcd
