/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

#include <sick_perception_sdk/drivers/MultiScan200.hpp>

#include <sick_perception_sdk/common/IpV4Address.hpp>
#include <sick_perception_sdk/compact_receiver/AmbientLightData.hpp>
#include <sick_perception_sdk/compact_receiver/ImuData.hpp>
#include <sick_perception_sdk/compact_receiver/PointCloud.hpp>
#include <sick_perception_sdk/compact_receiver/PointCloudConfiguration.hpp>
#include <sick_perception_sdk/compact_receiver/ScanData.hpp>

#include <chrono>
#include <cstddef>
#include <cstdint>
#include <exception>
#include <functional>
#include <string>
#include <utility>

namespace sick {

MultiScan200::MultiScan200(IpV4Address deviceAddress, std::function<void(std::exception)> onError)
  : m_deviceAddress(deviceAddress)
  , m_onError(std::move(onError))
{ }

void MultiScan200::multiplexScanData(compact::scan_data::ScanData const& scanData)
{
  if (m_onNewScanData)
  {
    if (m_packageLossMonitor)
    {
      m_packageLossMonitor->check(scanData);
    }
    (*m_onNewScanData)(scanData);
  }
  if (m_onNewPointCloud)
  {
    (*m_onNewPointCloud)(m_pointCloudConverter.convert(scanData));
  }
}

void MultiScan200::enableScanDataStream(
  std::uint16_t devicePort,
  std::function<void(std::exception)> onError,
  std::chrono::milliseconds firstDataTimeout,
  std::chrono::milliseconds newDataTimeout
)
{
  if (m_scanDataStream)
  {
    return;
  }

  constexpr std::size_t receiveBufferSize = 4'000'000;
  m_scanDataStream.emplace(
    m_deviceAddress,
    devicePort,
    receiveBufferSize,
    [&](compact::scan_data::ScanData const& scanData) -> void {
      multiplexScanData(scanData);
    },
    std::move(onError),
    firstDataTimeout,
    newDataTimeout,
    "multiScan200 scan data on " + m_deviceAddress.toString() + ":" + std::to_string(devicePort)
  );
}

void MultiScan200::setOnNewScanData(
  std::function<void(compact::scan_data::ScanData)> onNewScanData,
  std::uint16_t devicePort,
  std::chrono::milliseconds firstDataTimeout,
  std::chrono::milliseconds newDataTimeout
)
{
  m_onNewScanData = std::move(onNewScanData);
  enableScanDataStream(devicePort, m_onError, firstDataTimeout, newDataTimeout);
}

void MultiScan200::setOnNewPointCloud(
  PointCloudConfiguration const& pointCloudConfiguration,
  std::function<void(PointCloud)> onNewPointCloud,
  std::uint16_t devicePort,
  std::chrono::milliseconds firstDataTimeout,
  std::chrono::milliseconds newDataTimeout
)
{
  m_pointCloudConverter = compact::PointCloudConverter(pointCloudConfiguration);
  m_onNewPointCloud     = std::move(onNewPointCloud);
  enableScanDataStream(devicePort, m_onError, firstDataTimeout, newDataTimeout);
}

void MultiScan200::setOnNewAmbientLightData(
  std::function<void(compact::ambient_light::AmbientLightData)> onNewAmbientLight,
  std::uint16_t devicePort,
  std::chrono::milliseconds firstDataTimeout,
  std::chrono::milliseconds newDataTimeout
)
{
  constexpr std::size_t receiveBufferSize = 4'000'000;
  m_ambientLightStream.emplace(
    m_deviceAddress,
    devicePort,
    receiveBufferSize,
    std::move(onNewAmbientLight),
    m_onError,
    firstDataTimeout,
    newDataTimeout,
    "multiScan200 ambient light " + m_deviceAddress.toString() + ":" + std::to_string(devicePort)
  );
}

void MultiScan200::setOnNewImuData(
  std::function<void(compact::imu::ImuData)> onNewImu,
  std::uint16_t devicePort,
  std::chrono::milliseconds firstDataTimeout,
  std::chrono::milliseconds newDataTimeout
)
{
  constexpr std::size_t receiveBufferSize = 64;
  m_imuStream.emplace(
    m_deviceAddress,
    devicePort,
    receiveBufferSize,
    std::move(onNewImu),
    m_onError,
    firstDataTimeout,
    newDataTimeout,
    "multiScan200 IMU " + m_deviceAddress.toString() + ":" + std::to_string(devicePort)
  );
}

MultiScan200::~MultiScan200()
{
  stop();
}

void MultiScan200::run()
{
  if (m_scanDataStream)
  {
    m_scanDataStream->start();
  }
  if (m_ambientLightStream)
  {
    m_ambientLightStream->start();
  }
  if (m_imuStream)
  {
    m_imuStream->start();
  }
}

void MultiScan200::stop()
{
  if (m_scanDataStream)
  {
    m_scanDataStream->stop();
  }
  if (m_ambientLightStream)
  {
    m_ambientLightStream->stop();
  }
  if (m_imuStream)
  {
    m_imuStream->stop();
  }
}

void MultiScan200::setPackageLossMonitor(compact::scan_data::PackageLossMonitor packageLossMonitor)
{
  m_packageLossMonitor = std::move(packageLossMonitor);
}

} // namespace sick
