/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

#include <sick_perception_sdk/compact_receiver/PointCloudToPCDConverter.hpp>

#include <sick_perception_sdk/compact_receiver/PointCloud.hpp>

#include <cstdint>
#include <cstring> // for std::memcpy
#include <iomanip>
#include <ios>
#include <ostream>
#include <stdexcept>

namespace sick {

namespace {

struct PCDFieldInfo
{
  char type; // 'F', 'I', 'U'
  int size;
};

auto getPCDFieldInfo(PointField::Datatype type) -> PCDFieldInfo
{
  switch (type)
  {
  case PointField::Datatype::BOOL:
    return {'U', sizeof(bool)};
  case PointField::Datatype::INT8:
    return {'I', sizeof(std::int8_t)};
  case PointField::Datatype::UINT8:
    return {'U', sizeof(std::uint8_t)};
  case PointField::Datatype::INT16:
    return {'I', sizeof(std::int16_t)};
  case PointField::Datatype::UINT16:
    return {'U', sizeof(std::uint16_t)};
  case PointField::Datatype::INT32:
    return {'I', sizeof(std::int32_t)};
  case PointField::Datatype::UINT32:
    return {'U', sizeof(std::uint32_t)};
  case PointField::Datatype::FLOAT32:
    return {'F', sizeof(float)};
  case PointField::Datatype::FLOAT64:
    return {'F', sizeof(double)};
  default:
    throw std::runtime_error("Unsupported PointField datatype");
  }
}

// Helper to write PCD header for all fields
void writePCDHeader(std::ostream& stream, PointCloud const& cloud, bool binary)
{
  stream << "# .PCD v.7 - Point Cloud Data file format\n";
  stream << "VERSION .7\n";
  stream << "FIELDS";
  for (auto const& field : cloud.fields)
  {
    stream << " " << field.name;
  }
  stream << "\nSIZE";
  for (auto const& field : cloud.fields)
  {
    stream << " " << getPCDFieldInfo(field.datatype).size;
  }
  stream << "\nTYPE";
  for (auto const& field : cloud.fields)
  {
    stream << " " << getPCDFieldInfo(field.datatype).type;
  }
  stream << "\nCOUNT";
  for (auto const& field : cloud.fields)
  {
    stream << " " << field.count;
  }
  stream << "\nWIDTH " << cloud.numberOfPoints << "\nHEIGHT 1\n";
  stream << "VIEWPOINT 0 0 0 1 0 0 0\n";
  stream << "POINTS " << cloud.numberOfPoints << "\n";
  stream << "DATA " << (binary ? "binary" : "ascii") << "\n";
}

// Helper to write one point in ASCII
void writePointASCII(PointCloud const& cloud, std::size_t pointOffset, std::ostream& stream)
{
  constexpr int kFloatPrecision = 6;

  for (std::size_t fieldIndex = 0; fieldIndex < cloud.fields.size(); ++fieldIndex)
  {
    auto const& field             = cloud.fields[fieldIndex];
    std::size_t const fieldOffset = pointOffset + field.offset;
    for (std::size_t valueIndex = 0; valueIndex < field.count; ++valueIndex)
    {
      switch (field.datatype)
      {
      case PointField::Datatype::BOOL:
      {
        std::int8_t val = 0;
        std::memcpy(&val, &cloud.data[fieldOffset + valueIndex * sizeof(std::int8_t)], sizeof(std::int8_t));
        stream << (val > 0 ? "1" : "0");
        break;
      }
      case PointField::Datatype::INT8:
      {
        std::int8_t val = 0;
        std::memcpy(&val, &cloud.data[fieldOffset + valueIndex * sizeof(std::int8_t)], sizeof(std::int8_t));
        stream << static_cast<int>(val);
        break;
      }
      case PointField::Datatype::UINT8:
      {
        std::uint8_t val = 0;
        std::memcpy(&val, &cloud.data[fieldOffset + valueIndex * sizeof(std::uint8_t)], sizeof(std::uint8_t));
        stream << static_cast<unsigned int>(val);
        break;
      }
      case PointField::Datatype::INT16:
      {
        std::int16_t val = 0;
        std::memcpy(&val, &cloud.data[fieldOffset + valueIndex * sizeof(std::int16_t)], sizeof(std::int16_t));
        stream << val;
        break;
      }
      case PointField::Datatype::UINT16:
      {
        std::uint16_t val = 0;
        std::memcpy(&val, &cloud.data[fieldOffset + valueIndex * sizeof(std::uint16_t)], sizeof(std::uint16_t));
        stream << val;
        break;
      }
      case PointField::Datatype::INT32:
      {
        std::int32_t val = 0;
        std::memcpy(&val, &cloud.data[fieldOffset + valueIndex * sizeof(std::int32_t)], sizeof(std::int32_t));
        stream << val;
        break;
      }
      case PointField::Datatype::UINT32:
      {
        std::uint32_t val = 0;
        std::memcpy(&val, &cloud.data[fieldOffset + valueIndex * sizeof(std::uint32_t)], sizeof(std::uint32_t));
        stream << val;
        break;
      }
      case PointField::Datatype::FLOAT32:
      {
        float val = 0.0f;
        std::memcpy(&val, &cloud.data[fieldOffset + valueIndex * sizeof(float)], sizeof(float));
        stream << std::fixed << std::setprecision(kFloatPrecision) << val;
        break;
      }
      case PointField::Datatype::FLOAT64:
      {
        double val = 0.0;
        std::memcpy(&val, &cloud.data[fieldOffset + valueIndex * sizeof(double)], sizeof(double));
        stream << std::fixed << std::setprecision(kFloatPrecision) << val;
        break;
      }
      }
      if (valueIndex + 1 < field.count)
      {
        stream << " ";
      }
    }
    if (fieldIndex + 1 < cloud.fields.size())
    {
      stream << " ";
    }
  }
  stream << "\n";
}

} // anonymous namespace

void PointCloudToPCDConverter::convertToPCDBinary(PointCloud const& pointCloud, std::ostream& outputStream)
{
  writePCDHeader(outputStream, pointCloud, true);
  // NOLINTNEXTLINE(cppcoreguidelines-pro-type-reinterpret-cast)
  outputStream.write(reinterpret_cast<char const*>(pointCloud.data.data()), static_cast<std::streamsize>(pointCloud.data.size()));
}

void PointCloudToPCDConverter::convertToPCDASCII(PointCloud const& pointCloud, std::ostream& outputStream)
{
  writePCDHeader(outputStream, pointCloud, false);
  for (std::uint32_t i = 0; i < pointCloud.numberOfPoints; ++i)
  {
    auto const pointOffset = static_cast<std::size_t>(i) * static_cast<std::size_t>(pointCloud.pointStep);
    writePointASCII(pointCloud, pointOffset, outputStream);
  }
}

} // namespace sick
