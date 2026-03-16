/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

#include <sick_perception_sdk/drivers/multiScan200/Driver.hpp>

#include <sick_perception_sdk/common/IpV4Address.hpp>
#include <sick_perception_sdk/compact_format/PointCloud/PointCloudConfiguration.hpp>
#include <sick_perception_sdk/compact_format/telegram_type_2_imu/ImuData.hpp>
#include <sick_perception_sdk/compact_format/telegram_type_3_ambient_light/AmbientLightData.hpp>
#include <sick_perception_sdk/compact_format/telegram_type_6_multiScan200/DataLossMonitor.hpp>
#include <sick_perception_sdk/compact_format/telegram_type_6_multiScan200/MultiScan200Data.hpp>

#include <chrono>
#include <cstddef>
#include <cstdint>
#include <exception>
#include <functional>
#include <optional>
#include <string>
#include <utility>

namespace sick::multiScan200 {

Driver::Driver(IpV4Address deviceAddress, std::function<void(std::exception_ptr)> const& onError)
  : m_ambientLightReceiver(deviceAddress, onError)
  , m_imuReceiver(deviceAddress, onError)
  , m_scanDataReceiver(deviceAddress, onError)
{ }

Driver::~Driver()
{
  stop();
}

void Driver::run()
{
  if (m_ambientLightReceiver.m_stream.has_value())
  {
    m_ambientLightReceiver.m_stream->start();
  }
  if (m_imuReceiver.m_stream.has_value())
  {
    m_imuReceiver.m_stream->start();
  }
  if (m_scanDataReceiver.m_stream.has_value())
  {
    m_scanDataReceiver.m_stream->start();
  }
}

void Driver::stop()
{
  if (m_ambientLightReceiver.m_stream.has_value())
  {
    m_ambientLightReceiver.m_stream->stop();
  }
  if (m_imuReceiver.m_stream.has_value())
  {
    m_imuReceiver.m_stream->stop();
  }
  if (m_scanDataReceiver.m_stream.has_value())
  {
    m_scanDataReceiver.m_stream->stop();
  }
}

// --------------------------------------------------------------
// AmbientLightReceiver
// --------------------------------------------------------------

Driver::AmbientLightReceiver::AmbientLightReceiver(IpV4Address const& deviceAddress, std::function<void(std::exception_ptr)> const& onError)
  : m_deviceAddress(deviceAddress)
  , m_onError(onError)
  , m_stream(std::nullopt)
  , m_onNewData(std::nullopt)
{ }

void Driver::AmbientLightReceiver::setup(std::uint16_t sensorPort, std::chrono::milliseconds firstDataTimeout, std::chrono::milliseconds newDataTimeout)
{
  if (m_stream)
  {
    return;
  }
  constexpr std::size_t receiveBufferSize = 4'000'000;
  m_stream.emplace(
    m_deviceAddress,
    sensorPort,
    receiveBufferSize,
    [&](compact::ambient_light::AmbientLightData data) -> void {
      if (m_onNewData)
      {
        (*m_onNewData)(std::move(data));
      }
    },
    m_onError,
    firstDataTimeout,
    newDataTimeout,
    "multiScan200 ambient light " + m_deviceAddress.toString() + ":" + std::to_string(sensorPort)
  );
}

void Driver::AmbientLightReceiver::teardown()
{
  m_stream = std::nullopt;
}

void Driver::AmbientLightReceiver::setOnNewDataCallback(Driver::AmbientLightReceiver::DataCallback callback)
{
  m_onNewData = std::move(callback);
}

// --------------------------------------------------------------
// ImuReceiver
// --------------------------------------------------------------
Driver::ImuReceiver::ImuReceiver(IpV4Address const& deviceAddress, std::function<void(std::exception_ptr)> const& onError)
  : m_deviceAddress(deviceAddress)
  , m_onError(onError)
  , m_stream(std::nullopt)
  , m_onNewData(std::nullopt)
{ }

void Driver::ImuReceiver::setup(std::uint16_t sensorPort, std::chrono::milliseconds firstDataTimeout, std::chrono::milliseconds newDataTimeout)
{
  if (m_stream)
  {
    return;
  }
  constexpr std::size_t receiveBufferSize = 64;
  m_stream.emplace(
    m_deviceAddress,
    sensorPort,
    receiveBufferSize,
    [&](compact::imu::ImuData imuData) -> void {
      if (m_onNewData)
      {
        (*m_onNewData)(imuData);
      }
    },
    m_onError,
    firstDataTimeout,
    newDataTimeout,
    "multiScan200 IMU " + m_deviceAddress.toString() + ":" + std::to_string(sensorPort)
  );
}

void Driver::ImuReceiver::teardown()
{
  m_stream = std::nullopt;
}

void Driver::ImuReceiver::setOnNewDataCallback(Driver::ImuReceiver::DataCallback callback)
{
  m_onNewData = std::move(callback);
}

// --------------------------------------------------------------
// ScanDataReceiver
// --------------------------------------------------------------
Driver::ScanDataReceiver::ScanDataReceiver(IpV4Address const& deviceAddress, std::function<void(std::exception_ptr)> const& onError)
  : m_deviceAddress(deviceAddress)
  , m_onError(onError)
  , m_stream(std::nullopt)
  , m_dataLoss(std::nullopt)
  , m_onNewData(std::nullopt)
  , m_pointCloud(std::nullopt)
{ }

void Driver::ScanDataReceiver::multiplexScanData(compact::multiscan200::MultiScan200Data const& data)
{
  if (m_dataLoss)
  {
    try
    {
      auto& [monitor, callback] = *m_dataLoss;
      auto const lossCounts     = monitor.check(data);
      if ((lossCounts.numberOfLostFrames != 0) || (lossCounts.numberOfLostTelegrams != 0) || (lossCounts.numberOfLostSegments != 0))
      {
        callback(lossCounts);
      }
    }
    catch (std::exception_ptr exception)
    {
      m_onError(exception);
    }
  }
  if (m_onNewData)
  {
    (*m_onNewData)(data);
  }
  if (m_pointCloud)
  {
    m_pointCloud->second(m_pointCloud->first.convert(data));
  }
}

void Driver::ScanDataReceiver::setup(std::uint16_t sensorPort, std::chrono::milliseconds firstDataTimeout, std::chrono::milliseconds newDataTimeout)
{
  if (m_stream)
  {
    return;
  }

  constexpr std::size_t receiveBufferSize = 4'000'000;
  m_stream.emplace(
    m_deviceAddress,
    sensorPort,
    receiveBufferSize,
    [&](compact::multiscan200::MultiScan200Data const& data) -> void {
      multiplexScanData(data);
    },
    m_onError,
    firstDataTimeout,
    newDataTimeout,
    "multiScan200 scan data on " + m_deviceAddress.toString() + ":" + std::to_string(sensorPort)
  );
}

void Driver::ScanDataReceiver::teardown()
{
  m_stream = std::nullopt;
}

void Driver::ScanDataReceiver::setDataLossMonitor(compact::multiscan200::DataLossMonitor monitor, DataLossCallback callback)
{
  m_dataLoss = std::make_pair(std::move(monitor), std::move(callback));
}

void Driver::ScanDataReceiver::setOnNewFrameCallback(ScanDataCallback callback)
{
  m_onNewData = std::move(callback);
}

void Driver::ScanDataReceiver::setOnNewFrameCallback(PointCloudCallback callback, PointCloudConfiguration const& pointCloudConfiguration)
{
  m_pointCloud = std::make_pair(compact::multiscan200::PointCloudConverter(pointCloudConfiguration), std::move(callback));
}

} // namespace sick::multiScan200
