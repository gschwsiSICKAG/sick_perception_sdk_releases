cmake_minimum_required(VERSION 3.24)
project(sick_perception_sdk VERSION 0.0.0 LANGUAGES CXX)
set(PRE_RELEASE_VERSION "-dev")

#===============================================================================
# User configuration for the SDK package.
#===============================================================================
option(BUILD_DRIVERS "Add the library `drivers` to the cmake build." ON)
option(BUILD_COMPACT_RECEIVER "Add the library `compact_receiver` to the cmake build." ON)
option(BUILD_SENSOR_CONFIGURATION "Add the library `sensor_configuration` to the cmake build." ON)
option(BUILD_UNIT_TESTS "Build unit tests for the libraries" OFF)
option(BUILD_EXAMPLES "Build examples" OFF)
option(BUILD_SHARED_LIBS "Build shared libraries (dll on Windows, so on Linux)" OFF)

# ------------------------------------------------------------------------------
# Configuration options for third-party dependencies.
# ------------------------------------------------------------------------------
option(TRY_TO_USE_ZLIB "Try to use zlib for CRC32, otherwise use internal (slower) implementation" ON)

# For Windows set the OpenSSL root directory to the installation path of OpenSSL.
# Adjust the path if OpenSSL is installed in a different location. The default path shown is for the
# installation from Shining Light Productions.
if (WIN32)
  if (NOT EXISTS "${CMAKE_BINARY_DIR}/generators/conan_toolchain.cmake")
    set(OPENSSL_ROOT_DIR "C:/Program Files/OpenSSL-Win64" CACHE STRING "Path to OpenSSL root directory")
  else()
    # Unset the cache variable when using Conan to let Conan's FindOpenSSL.cmake handle it
    unset(OPENSSL_ROOT_DIR CACHE)
  endif()
endif()

#===============================================================================
# Internal dependency logic
#===============================================================================
if (BUILD_EXAMPLES)
  set(BUILD_DRIVERS ON)
  set(BUILD_SENSOR_CONFIGURATION ON)
  set(BUILD_COMPACT_RECEIVER ON)
endif()

if (BUILD_UNIT_TESTS)
  set(BUILD_COMPACT_RECEIVER ON)
  set(BUILD_SENSOR_CONFIGURATION ON)
endif()

if (BUILD_DRIVERS)
  set(BUILD_COMMON ON)
  set(BUILD_SENSOR_CONFIGURATION ON)
  set(BUILD_COMPACT_RECEIVER ON)
endif()

if (BUILD_SENSOR_CONFIGURATION OR BUILD_COMPACT_RECEIVER)
  set(BUILD_COMMON ON)
endif()

#===============================================================================
# Configure cmake
#===============================================================================
include(GNUInstallDirs)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

#===============================================================================
# SDK Libraries
#===============================================================================
if (BUILD_COMMON)
  add_subdirectory(src/common)
endif()

if (BUILD_COMPACT_RECEIVER)
  add_subdirectory(src/compact_receiver)
endif()

if (BUILD_SENSOR_CONFIGURATION)
  add_subdirectory(src/sensor_configuration)
endif()

if (BUILD_DRIVERS)
  add_subdirectory(src/drivers)
endif()

if (BUILD_EXAMPLES)
  add_subdirectory(examples)
endif()

#===============================================================================
# Project export
#===============================================================================
include(CMakePackageConfigHelpers)

configure_package_config_file(
  ${CMAKE_CURRENT_LIST_DIR}/cmake/${PROJECT_NAME}-config.cmake.in
  ${PROJECT_NAME}-config.cmake
  INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}
)

write_basic_package_version_file(
  "${CMAKE_BINARY_DIR}/${PROJECT_NAME}-config-version.cmake"
  VERSION ${PROJECT_VERSION}
  COMPATIBILITY SameMajorVersion
)

install(
  FILES
    "${CMAKE_BINARY_DIR}/${PROJECT_NAME}-config.cmake"
    "${CMAKE_BINARY_DIR}/${PROJECT_NAME}-config-version.cmake"
  DESTINATION 
    ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}
)

install(
  EXPORT ${PROJECT_NAME}-config
  FILE ${PROJECT_NAME}-config-targets.cmake
  NAMESPACE ${PROJECT_NAME}::
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}
)
