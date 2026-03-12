/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

#include <sick_perception_sdk/sensor_configuration/MultiScan200Configurator.hpp>

#include "test_config.hpp"
#include <sick_perception_sdk/sensor_configuration/HttpClient/httplib_client/HttpClient.hpp>

#include <chrono>
#include <cstdint>
#include <gtest/gtest.h>
#include <thread>

using namespace sick::literals;
using namespace std::chrono_literals;

class MultiScan200ConfiguratorTest : public ::testing::Test
{
protected:
  MultiScan200ConfiguratorTest()
    : m_configurator {std::make_unique<sick::httplib_client::HttpClient>(getSensorAddress(), getSensorPort()), sick::UserLevel::Service, "servicelevel"}
  { }

  static void SetUpTestSuite()
  {
    std::cout << "Waiting for factory reset to complete ";
    sick::MultiScan200Configurator configurator {
      std::make_unique<sick::httplib_client::HttpClient>(getSensorAddress(), getSensorPort()),
      sick::UserLevel::Service,
      "servicelevel"
    };
    configurator.factoryReset();
    std::this_thread::sleep_for(10s);
    while (true)
    {
      try
      {
        std::cout << ".";
        configurator.firmwareVersion.get();
        break;
      }
      catch (...)
      {
        std::this_thread::sleep_for(1s);
      }
    }
    std::cout << "\n";
  }

  sick::MultiScan200Configurator m_configurator;
};

TEST_F(MultiScan200ConfiguratorTest, deviceType_get)
{
  auto const deviceType = m_configurator.deviceType.get();
  EXPECT_EQ(deviceType, "multiScan200");
}

TEST_F(MultiScan200ConfiguratorTest, firmwareVersion_get)
{
  auto const firmwareVersion = m_configurator.firmwareVersion.get();
  EXPECT_FALSE(firmwareVersion.empty());
}

TEST_F(MultiScan200ConfiguratorTest, locationName_get)
{
  auto const locationName = m_configurator.locationName.get();
  EXPECT_FALSE(locationName.empty());
}

TEST_F(MultiScan200ConfiguratorTest, orderNumber_get)
{
  auto const orderNumber = m_configurator.orderNumber.get();
  EXPECT_FALSE(orderNumber.empty());
}

TEST_F(MultiScan200ConfiguratorTest, serialNumber_get)
{
  auto const serialNumber = m_configurator.serialNumber.get();
  EXPECT_FALSE(serialNumber.empty());
}

TEST_F(MultiScan200ConfiguratorTest, horizontalFieldOfViewStartAngle_get)
{
  auto const startAngle = m_configurator.horizontalFieldOfViewStartAngle.get();
  EXPECT_GE(startAngle.degrees(), -180.0f);
}

TEST_F(MultiScan200ConfiguratorTest, sensorPosition_get)
{
  auto const position = m_configurator.sensorPosition.get();
  EXPECT_TRUE(position.x.meters() >= 0.0f && position.y.meters() >= 0.0f && position.z.meters() >= 0.0f);
}

TEST_F(MultiScan200ConfiguratorTest, systemTime_get)
{
  auto const systemTime = m_configurator.systemTime.get();
  EXPECT_GT(systemTime.count(), 0);
}

TEST_F(MultiScan200ConfiguratorTest, intervalFilter_get)
{
  auto const interval = m_configurator.intervalFilter.get();
  EXPECT_GE(interval.value(), 2);
}

TEST_F(MultiScan200ConfiguratorTest, bloomingFilter_get)
{
  auto const bloomingFilter = m_configurator.bloomingFilter.get();
  EXPECT_TRUE(bloomingFilter.isEnabled == true || bloomingFilter.isEnabled == false);
}

TEST_F(MultiScan200ConfiguratorTest, verticalAngleRangeFilter_get)
{
  auto const verticalFilter = m_configurator.verticalAngleRangeFilter.get();
  EXPECT_GE(verticalFilter.outerStart.degrees(), -180.0f);
  EXPECT_GE(verticalFilter.innerStart.degrees(), -180.0f);
}

TEST_F(MultiScan200ConfiguratorTest, bloomingFilter_isEnabled)
{
  auto const isEnabled = m_configurator.bloomingFilter.isEnabled();
  EXPECT_FALSE(isEnabled);
}

TEST_F(MultiScan200ConfiguratorTest, horizontalAngleRangeFilter_isEnabled)
{
  auto const isEnabled = m_configurator.horizontalAngleRangeFilter.isEnabled();
  EXPECT_FALSE(isEnabled);
}

TEST_F(MultiScan200ConfiguratorTest, verticalAngleRangeFilter_isEnabled)
{
  auto const isEnabled = m_configurator.verticalAngleRangeFilter.isEnabled();
  EXPECT_FALSE(isEnabled);
}

TEST_F(MultiScan200ConfiguratorTest, intervalFilter_isEnabled)
{
  auto const isEnabled = m_configurator.intervalFilter.isEnabled();
  EXPECT_FALSE(isEnabled);
}

TEST_F(MultiScan200ConfiguratorTest, stopStartMeasure)
{
  m_configurator.stopMeasurement();
  std::this_thread::sleep_for(1s);
  m_configurator.startMeasurement();
}

TEST_F(MultiScan200ConfiguratorTest, rebootDevice)
{
  auto const previousPowerOnCount = m_configurator.readVariable<sick::srt::multiScan200::PowerOnCnt>()._PowerOnCnt;

  m_configurator.reboot();
  std::cout << "Waiting for device to reboot";
  std::this_thread::sleep_for(10s);
  while (true)
  {
    try
    {
      std::cout << ".";
      m_configurator.firmwareVersion.get();
      break;
    }
    catch (...)
    {
      std::this_thread::sleep_for(1s);
    }
  }
  std::cout << "\n";

  auto const newPowerOnCount = m_configurator.readVariable<sick::srt::multiScan200::PowerOnCnt>()._PowerOnCnt;
  EXPECT_EQ(newPowerOnCount, previousPowerOnCount + 1);
}

TEST_F(MultiScan200ConfiguratorTest, findMe)
{
  m_configurator.findMe(1_s);
  std::this_thread::sleep_for(1s);
}
