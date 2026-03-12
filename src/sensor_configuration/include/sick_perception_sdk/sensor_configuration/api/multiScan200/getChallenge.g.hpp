/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file getChallenge.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 *
 * @note This class represents the payload of a SOPAS method. Do not use in `write_variable()`!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>
#include <string>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /getChallenge.
*/
struct SDK_EXPORT getChallenge
{

  constexpr static const char* methodName = "getChallenge";
  constexpr static const bool isSopasMethod = true;

/**
 * @brief Post getChallenge.
*/
struct SDK_EXPORT Post
{
struct SDK_EXPORT Request
{
  Request() = default;

  explicit Request(std::string user)
    : _user(std::move(user))
  {}

  std::string _user;
};

struct SDK_EXPORT Response
{
  Response() = default;

  explicit Response(std::string realm, std::string nonce, std::string opaque, std::vector<int> salt)
    : _realm(std::move(realm)), _nonce(std::move(nonce)), _opaque(std::move(opaque)), _salt(salt)
  {}

  std::string _realm;
  std::string _nonce;
  std::string _opaque;
  std::vector<int> _salt;
};

}; // struct Post

}; // struct getChallenge

} // namespace sick::srt::multiScan200
