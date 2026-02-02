/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

#include <sick_perception_sdk/drivers/LRS4000.hpp>

#include <sick_perception_sdk/common/IpV4Address.hpp>
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

LRS4000::LRS4000(IpV4Address deviceAddress, std::function<void(std::exception)> onError)
  : m_deviceAddress(deviceAddress)
  , m_onError(std::move(onError))
{ }

void LRS4000::multiplexScanData(compact::scan_data::ScanData const& scanData)
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

void LRS4000::enableScanDataStream(
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
    "LRS4000 scan data on " + m_deviceAddress.toString() + ":" + std::to_string(devicePort)
  );
}

void LRS4000::setOnNewScanData(
  std::function<void(compact::scan_data::ScanData)> onNewScanData,
  std::uint16_t devicePort,
  std::chrono::milliseconds firstDataTimeout,
  std::chrono::milliseconds newDataTimeout
)
{
  m_onNewScanData = std::move(onNewScanData);
  enableScanDataStream(devicePort, m_onError, firstDataTimeout, newDataTimeout);
}

void LRS4000::setOnNewPointCloud(
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

LRS4000::~LRS4000()
{
  stop();
}

void LRS4000::run()
{
  if (m_scanDataStream)
  {
    m_scanDataStream->start();
  }
}

void LRS4000::stop()
{
  if (m_scanDataStream)
  {
    m_scanDataStream->stop();
  }
}

void LRS4000::setPackageLossMonitor(compact::scan_data::PackageLossMonitor packageLossMonitor)
{
  m_packageLossMonitor = std::move(packageLossMonitor);
}

} // namespace sick
