/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

#include <sick_perception_sdk/drivers/LRS4000/Driver.hpp>

#include <sick_perception_sdk/common/IpV4Address.hpp>
#include <sick_perception_sdk/compact_format/PointCloud/PointCloudConfiguration.hpp>
#include <sick_perception_sdk/compact_format/telegram_type_1_scan_data/DataLossMonitor.hpp>
#include <sick_perception_sdk/compact_format/telegram_type_1_scan_data/PointCloudConverter.hpp>
#include <sick_perception_sdk/compact_format/telegram_type_1_scan_data/ScanData.hpp>

#include <chrono>
#include <cstddef>
#include <cstdint>
#include <exception>
#include <functional>
#include <optional>
#include <string>
#include <utility>

namespace sick::LRS4000 {

Driver::Driver(IpV4Address deviceAddress, std::function<void(std::exception_ptr)> const& onError)
  : m_scanDataReceiver(deviceAddress, onError)
{ }

Driver::~Driver()
{
  stop();
}

void Driver::run()
{
  if (m_scanDataReceiver.m_stream.has_value())
  {
    m_scanDataReceiver.m_stream->start();
  }
}

void Driver::stop()
{
  if (m_scanDataReceiver.m_stream.has_value())
  {
    m_scanDataReceiver.m_stream->stop();
  }
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

void Driver::ScanDataReceiver::multiplexScanData(compact::scan_data::ScanData const& scanData)
{
  if (m_dataLoss)
  {
    try
    {
      auto& [monitor, callback] = *m_dataLoss;
      auto const lossCounts     = monitor.check(scanData);
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
    (*m_onNewData)(scanData);
  }
  if (m_pointCloud)
  {
    auto& [converter, callback] = *m_pointCloud;
    callback(converter.convert(scanData));
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
    [&](compact::scan_data::ScanData const& data) -> void {
      multiplexScanData(data);
    },
    m_onError,
    firstDataTimeout,
    newDataTimeout,
    "scan data on " + m_deviceAddress.toString() + ":" + std::to_string(sensorPort)
  );
}

void Driver::ScanDataReceiver::teardown()
{
  m_stream = std::nullopt;
}

void Driver::ScanDataReceiver::setDataLossMonitor(compact::scan_data::DataLossMonitor monitor, DataLossCallback callback)
{
  m_dataLoss = std::make_pair(std::move(monitor), std::move(callback));
}

void Driver::ScanDataReceiver::setOnNewFrameCallback(ScanDataCallback callback)
{
  m_onNewData = std::move(callback);
}

void Driver::ScanDataReceiver::setOnNewFrameCallback(PointCloudCallback callback, PointCloudConfiguration const& pointCloudConfiguration)
{
  m_pointCloud = std::make_pair(compact::scan_data::PointCloudConverter(pointCloudConfiguration), std::move(callback));
}

} // namespace sick::LRS4000
