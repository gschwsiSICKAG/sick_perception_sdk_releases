/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

#pragma once

#include <cstdint>
#include <string>

auto getSensorAddress() -> std::string;
auto getSensorPort() -> std::uint16_t;
