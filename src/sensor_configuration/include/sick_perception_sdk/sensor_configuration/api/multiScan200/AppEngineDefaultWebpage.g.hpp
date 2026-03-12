/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file AppEngineDefaultWebpage.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>
#include <string>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /AppEngineDefaultWebpage.
*/
struct SDK_EXPORT AppEngineDefaultWebpage
{

  constexpr static const char* variableName = "AppEngineDefaultWebpage";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief Defines which MSDD file of which App should be used as default view for the webserver. Value can be in format 'appname' or 'appname/msddfilename'. Default is empty which means to use the first one of the first alphabetical app, or if no app use the device msdd webpage.
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  Response() = default;

  explicit Response(std::string AppEngineDefaultWebpage)
    : _AppEngineDefaultWebpage(std::move(AppEngineDefaultWebpage))
  {}

  std::string _AppEngineDefaultWebpage;
};

}; // struct Get

/**
 * @brief Defines which MSDD file of which App should be used as default view for the webserver. Value can be in format 'appname' or 'appname/msddfilename'. Default is empty which means to use the first one of the first alphabetical app, or if no app use the device msdd webpage.

 This function requires at least user level: Authorized Client.
*/
struct SDK_EXPORT Post
{
struct SDK_EXPORT Request
{
  Request() = default;

  explicit Request(std::string AppEngineDefaultWebpage)
    : _AppEngineDefaultWebpage(std::move(AppEngineDefaultWebpage))
  {}

  std::string _AppEngineDefaultWebpage;
};

}; // struct Post

}; // struct AppEngineDefaultWebpage

} // namespace sick::srt::multiScan200
