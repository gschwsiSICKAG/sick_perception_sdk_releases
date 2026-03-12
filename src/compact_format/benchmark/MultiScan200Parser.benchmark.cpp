/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

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

class MultiScan200ParserBenchmark : public ::benchmark::Fixture
{ };

BENCHMARK_DEFINE_F(MultiScan200ParserBenchmark, validateAndParse)(benchmark::State& state)
{
  auto const file_idx  = state.range(0);
  auto const& fileName = testFiles[file_idx];
  state.SetLabel(deviceNames[file_idx]);
  auto const rawData = sick::benchmark::readBinary("data/" + fileName);
  auto const data    = sick::ByteView(rawData);

  constexpr bool validateChecksum = true;
  for (auto _ : state)
  {
    benchmark::DoNotOptimize(sick::compact::multiscan200::Parser::validateAndParse(data, validateChecksum));
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

BENCHMARK_REGISTER_F(MultiScan200ParserBenchmark, validateAndParse)->Apply(RegisterBenchmarks);
