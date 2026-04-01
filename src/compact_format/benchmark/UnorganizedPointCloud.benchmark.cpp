/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

#include <sick_perception_sdk/compact_format/telegram_type_6_multiScan200/PointCloudConverter.hpp>

#include "../test/utils/TestParams.hpp"
#include "benchmark_tools.hpp"
#include <sick_perception_sdk/compact_format/PointCloud/UnorganizedPointCloud.hpp>
#include <sick_perception_sdk/compact_format/telegram_type_6_multiScan200/MultiScan200Parser.hpp>

#include <benchmark/benchmark.h>
#include <memory>

using namespace sick::compact;
using namespace sick::compact::multiscan200;

class UnorganizedPointCloudBenchmark : public ::benchmark::Fixture
{
protected:
  std::unique_ptr<sick::point_cloud::UnorganizedPointCloud> m_pointCloud;

  void SetUp(benchmark::State const& state) override
  {
    std::string const fileName = "multiScan270_0.8.0_2337_ms270_full-frame_0.bin";
    auto const rawData         = sick::benchmark::readBinary("data/" + fileName);
    auto const rawDataView     = sick::ByteView(rawData);

    constexpr bool validateChecksum = true;
    auto const data                 = sick::compact::multiscan200::Parser::validateAndParse(rawDataView, validateChecksum);

    sick::point_cloud::PointCloudConfiguration config;
    config.fields.enableCartesian   = true;
    config.fields.enableSpherical   = true;
    config.fields.enableIntensity   = true;
    config.fields.enableTimeOffset  = true;
    config.fields.enableRing        = true;
    config.fields.enableLayer       = true;
    config.fields.enableEcho        = true;
    config.fields.enableIsReflector = true;
    config.fields.enableHasBlooming = true;
    config.fields.enablePulseWidth  = true;

    sick::compact::multiscan200::PointCloudConverter converter {config};
    m_pointCloud = std::make_unique<sick::point_cloud::UnorganizedPointCloud>(converter.convertToUnorganized(data));
  }
};

BENCHMARK_DEFINE_F(UnorganizedPointCloudBenchmark, getCartesian_first_point)(benchmark::State& state)
{
  constexpr std::size_t pointIndex = 0;
  auto const& pointCloud           = *m_pointCloud;
  for (auto _ : state)
  {
    benchmark::DoNotOptimize(pointCloud.getCartesian(pointIndex));
  }
}

BENCHMARK_DEFINE_F(UnorganizedPointCloudBenchmark, getCartesian_last_point)(benchmark::State& state)
{
  std::size_t const pointIndex = m_pointCloud->numberOfPoints() - 1;
  auto const& pointCloud       = *m_pointCloud;
  for (auto _ : state)
  {
    benchmark::DoNotOptimize(pointCloud.getCartesian(pointIndex));
  }
}

BENCHMARK_DEFINE_F(UnorganizedPointCloudBenchmark, getPulseWidth_first_point)(benchmark::State& state)
{
  constexpr std::size_t pointIndex = 0;
  auto const& pointCloud           = *m_pointCloud;
  for (auto _ : state)
  {
    benchmark::DoNotOptimize(pointCloud.getPulseWidth(pointIndex));
  }
}

BENCHMARK_DEFINE_F(UnorganizedPointCloudBenchmark, getPulseWidth_last_point)(benchmark::State& state)
{
  std::size_t const pointIndex = m_pointCloud->numberOfPoints() - 1;
  auto const& pointCloud       = *m_pointCloud;
  for (auto _ : state)
  {
    benchmark::DoNotOptimize(pointCloud.getPulseWidth(pointIndex));
  }
}

BENCHMARK_DEFINE_F(UnorganizedPointCloudBenchmark, getCartesian)(benchmark::State& state)
{
  state.SetLabel(std::to_string(m_pointCloud->numberOfPoints()) + " points");
  auto const& pointCloud = *m_pointCloud;
  for (auto _ : state)
  {
    for (std::size_t i = 0; i < pointCloud.numberOfPoints(); ++i)
    {
      benchmark::DoNotOptimize(pointCloud.getCartesian(i));
    }
  }
}

BENCHMARK_DEFINE_F(UnorganizedPointCloudBenchmark, getAllFields)(benchmark::State& state)
{
  state.SetLabel(std::to_string(m_pointCloud->numberOfPoints()) + " points");
  auto const& pointCloud = *m_pointCloud;
  for (auto _ : state)
  {
    for (std::size_t i = 0; i < pointCloud.numberOfPoints(); ++i)
    {
      benchmark::DoNotOptimize(pointCloud.getCartesian(i));
      benchmark::DoNotOptimize(pointCloud.getSpherical(i));
      benchmark::DoNotOptimize(pointCloud.getIntensity(i));
      benchmark::DoNotOptimize(pointCloud.getTimeOffset(i));
      benchmark::DoNotOptimize(pointCloud.getRing(i));
      benchmark::DoNotOptimize(pointCloud.getLayer(i));
      benchmark::DoNotOptimize(pointCloud.getEcho(i));
      benchmark::DoNotOptimize(pointCloud.isReflector(i));
      benchmark::DoNotOptimize(pointCloud.hasBlooming(i));
      benchmark::DoNotOptimize(pointCloud.getPulseWidth(i));
    }
  }
}

BENCHMARK_REGISTER_F(UnorganizedPointCloudBenchmark, getCartesian_first_point);
BENCHMARK_REGISTER_F(UnorganizedPointCloudBenchmark, getCartesian_last_point);
BENCHMARK_REGISTER_F(UnorganizedPointCloudBenchmark, getPulseWidth_first_point);
BENCHMARK_REGISTER_F(UnorganizedPointCloudBenchmark, getPulseWidth_last_point);
BENCHMARK_REGISTER_F(UnorganizedPointCloudBenchmark, getCartesian);
BENCHMARK_REGISTER_F(UnorganizedPointCloudBenchmark, getAllFields);
