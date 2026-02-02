/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

#pragma once

#include <sick_perception_sdk/common/IpV4Address.hpp>

#include <utility>

namespace sick::examples {

auto getDeviceAddress(int argc, char* argv[]) -> IpV4Address
{
  if (argc == 2)
  {
    return sick::IpV4Address(argv[1]);
  }
  return sick::IpV4Address("192.168.0.1");
}

auto getTwoDeviceAddresses(int argc, char* argv[]) -> std::pair<IpV4Address, IpV4Address>
{
  if (argc == 3)
  {
    return {sick::IpV4Address(argv[1]), sick::IpV4Address(argv[2])};
  }
  return {sick::IpV4Address("192.168.0.1"), sick::IpV4Address("192.168.0.2")};
}

} // namespace sick::examples
