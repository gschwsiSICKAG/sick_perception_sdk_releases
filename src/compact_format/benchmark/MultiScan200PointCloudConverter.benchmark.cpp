/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

#include <sick_perception_sdk/compact_format/telegram_type_6_multiScan200/PointCloudConverter.hpp>

#include <sick_perception_sdk/compact_format/telegram_type_6_multiScan200/MultiScan200Parser.hpp>

#include <sick_perception_sdk/compact_format/CompactParser.hpp>

#include "../test/utils/TestParams.hpp"
#include "benchmark_tools.hpp"

#include <benchmark/benchmark.h>

using namespace sick::compact;
using namespace sick::compact::multiscan200;

static std::vector<std::string> const deviceNames = {
  "multiScan200",      //
  "multiScan200 full", //
};

static std::vector<std::string> const testFiles = {
  "multiScan270_0.8.0_2337_ms270-frame_0.bin",      //
  "multiScan270_0.8.0_2337_ms270_full-frame_0.bin", //
};

class MultiScan200PointCloudConverterBenchmark : public ::benchmark::Fixture
{ };

BENCHMARK_DEFINE_F(MultiScan200PointCloudConverterBenchmark, convert_cartesian)(benchmark::State& state)
{
  auto const file_idx  = state.range(0);
  auto const& fileName = testFiles[file_idx];
  state.SetLabel(deviceNames[file_idx]);
  auto const rawData     = sick::benchmark::readBinary("data/" + fileName);
  auto const rawDataView = sick::ByteView(rawData);

  constexpr bool validateChecksum = true;
  auto const data                 = sick::compact::multiscan200::Parser::validateAndParse(rawDataView, validateChecksum);

  sick::compact::multiscan200::PointCloudConverter converter {sick::PointCloudConfiguration {}};

  for (auto _ : state)
  {
    benchmark::DoNotOptimize(converter.convert(data));
  }
}

BENCHMARK_DEFINE_F(MultiScan200PointCloudConverterBenchmark, convert_all)(benchmark::State& state)
{
  auto const file_idx  = state.range(0);
  auto const& fileName = testFiles[file_idx];
  state.SetLabel(deviceNames[file_idx]);
  auto const rawData     = sick::benchmark::readBinary("data/" + fileName);
  auto const rawDataView = sick::ByteView(rawData);

  constexpr bool validateChecksum = true;
  auto const data                 = sick::compact::multiscan200::Parser::validateAndParse(rawDataView, validateChecksum);

  sick::compact::multiscan200::PointCloudConverter converter {sick::PointCloudConfiguration {
    true, // enableCartesian
    true, // enableSpherical
    true, // enableIntensity
    true, // enableTimeOffset
    true, // enableRing
    true, // enableLayer
    true, // enableEcho
    true, // enableIsReflector
    true, // enableHasBlooming
    true, // enablePulseWidth
  }};

  for (auto _ : state)
  {
    benchmark::DoNotOptimize(converter.convert(data));
  }
}

// Register the benchmark with one argument per device file
static void RegisterBenchmarks(benchmark::internal::Benchmark* b)
{
  for (size_t i = 0; i < testFiles.size(); ++i)
  {
    b->Args({static_cast<int64_t>(i)});
  }
}

BENCHMARK_REGISTER_F(MultiScan200PointCloudConverterBenchmark, convert_cartesian)->Apply(RegisterBenchmarks);
BENCHMARK_REGISTER_F(MultiScan200PointCloudConverterBenchmark, convert_all)->Apply(RegisterBenchmarks);
