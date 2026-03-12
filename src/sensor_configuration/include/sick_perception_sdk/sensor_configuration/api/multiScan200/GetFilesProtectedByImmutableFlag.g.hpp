/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file GetFilesProtectedByImmutableFlag.g.hpp Sensor REST API payload definitions.
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
 * @brief Payloads for endpoint /GetFilesProtectedByImmutableFlag.
*/
struct SDK_EXPORT GetFilesProtectedByImmutableFlag
{

  constexpr static const char* methodName = "GetFilesProtectedByImmutableFlag";
  constexpr static const bool isSopasMethod = true;

/**
 * @brief Returns a list of all present files and their immutable flag's state.

 This function requires at least user level: Production.
*/
struct SDK_EXPORT Post
{
struct SDK_EXPORT Response
{
  struct SDK_EXPORT FileListItem
  {
    FileListItem() = default;

    explicit FileListItem(std::string FilePath, bool Immutable)
      : _FilePath(std::move(FilePath)), _Immutable(Immutable)
    {}

    std::string _FilePath;
    bool _Immutable;
  };

  Response() = default;

  explicit Response(std::vector<FileListItem> FileList)
    : _FileList(FileList)
  {}

  std::vector<FileListItem> _FileList;
};

}; // struct Post

}; // struct GetFilesProtectedByImmutableFlag

} // namespace sick::srt::multiScan200
