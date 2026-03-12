/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

#include <sick_perception_sdk/drivers/MultiScan200.hpp>

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

namespace sick {

MultiScan200::MultiScan200(IpV4Address deviceAddress, std::function<void(std::exception_ptr)> const& onError)
  : m_ambientLightReceiver(deviceAddress, onError)
  , m_imuReceiver(deviceAddress, onError)
  , m_scanDataReceiver(deviceAddress, onError)
{ }

MultiScan200::~MultiScan200()
{
  stop();
}

void MultiScan200::run()
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

void MultiScan200::stop()
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

MultiScan200::AmbientLightReceiver::AmbientLightReceiver(IpV4Address const& deviceAddress, std::function<void(std::exception_ptr)> const& onError)
  : m_deviceAddress(deviceAddress)
  , m_onError(onError)
  , m_stream(std::nullopt)
  , m_onNewData(std::nullopt)
{ }

void MultiScan200::AmbientLightReceiver::setup(std::uint16_t sensorPort, std::chrono::milliseconds firstDataTimeout, std::chrono::milliseconds newDataTimeout)
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

void MultiScan200::AmbientLightReceiver::teardown()
{
  m_stream = std::nullopt;
}

void MultiScan200::AmbientLightReceiver::setOnNewDataCallback(MultiScan200::AmbientLightReceiver::DataCallback callback)
{
  m_onNewData = std::move(callback);
}

// --------------------------------------------------------------
// ImuReceiver
// --------------------------------------------------------------
MultiScan200::ImuReceiver::ImuReceiver(IpV4Address const& deviceAddress, std::function<void(std::exception_ptr)> const& onError)
  : m_deviceAddress(deviceAddress)
  , m_onError(onError)
  , m_stream(std::nullopt)
  , m_onNewData(std::nullopt)
{ }

void MultiScan200::ImuReceiver::setup(std::uint16_t sensorPort, std::chrono::milliseconds firstDataTimeout, std::chrono::milliseconds newDataTimeout)
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

void MultiScan200::ImuReceiver::teardown()
{
  m_stream = std::nullopt;
}

void MultiScan200::ImuReceiver::setOnNewDataCallback(MultiScan200::ImuReceiver::DataCallback callback)
{
  m_onNewData = std::move(callback);
}

// --------------------------------------------------------------
// ScanDataReceiver
// --------------------------------------------------------------
MultiScan200::ScanDataReceiver::ScanDataReceiver(IpV4Address const& deviceAddress, std::function<void(std::exception_ptr)> const& onError)
  : m_deviceAddress(deviceAddress)
  , m_onError(onError)
  , m_stream(std::nullopt)
  , m_dataLoss(std::nullopt)
  , m_onNewData(std::nullopt)
  , m_pointCloud(std::nullopt)
{ }

void MultiScan200::ScanDataReceiver::multiplexScanData(compact::multiscan200::MultiScan200Data const& data)
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

void MultiScan200::ScanDataReceiver::setup(std::uint16_t sensorPort, std::chrono::milliseconds firstDataTimeout, std::chrono::milliseconds newDataTimeout)
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

void MultiScan200::ScanDataReceiver::teardown()
{
  m_stream = std::nullopt;
}

void MultiScan200::ScanDataReceiver::setDataLossMonitor(compact::multiscan200::DataLossMonitor monitor, DataLossCallback callback)
{
  m_dataLoss = std::make_pair(std::move(monitor), std::move(callback));
}

void MultiScan200::ScanDataReceiver::setOnNewFrameCallback(ScanDataCallback callback)
{
  m_onNewData = std::move(callback);
}

void MultiScan200::ScanDataReceiver::setOnNewFrameCallback(PointCloudCallback callback, PointCloudConfiguration const& pointCloudConfiguration)
{
  m_pointCloud = std::make_pair(compact::multiscan200::PointCloudConverter(pointCloudConfiguration), std::move(callback));
}

} // namespace sick
