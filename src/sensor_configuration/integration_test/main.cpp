/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

#include "test_config.hpp"

#include <gtest/gtest.h>
#include <iostream>
#include <string>

static std::string gSensorAddress;

auto getSensorAddress() -> std::string
{
  return gSensorAddress;
}

static std::uint16_t gSensorPort = 80;

auto getSensorPort() -> std::uint16_t
{
  return gSensorPort;
}

auto parseCustomArgs(int& argc, char** argv) -> void
{
  for (int i = 1; i < argc; ++i)
  {
    std::string arg = argv[i];
    if (arg.find("--sensor-address=") == 0)
    {
      gSensorAddress = arg.substr(17); // Extract value after "--sensor-address="
    }
    else if (arg.find("--sensor-port=") == 0)
    {
      gSensorPort = static_cast<std::uint16_t>(std::stoi(arg.substr(14))); // Extract value after "--sensor-port="
    }
    else
    {
      continue;
    }

    // Remove the processed argument from argv
    for (int j = i; j < argc - 1; ++j)
    {
      argv[j] = argv[j + 1];
    }
    --argc;
    --i;
  }
}

auto main(int argc, char** argv) -> int
{
  parseCustomArgs(argc, argv); // Parse custom arguments
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
