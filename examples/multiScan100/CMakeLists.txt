# cmake versions >= 3.5 are compatible with cmake 4, versions >= 3.10 are not deprecated.
cmake_minimum_required(VERSION 3.24)
project(sick_perception_sdk_multiScan100_examples)

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
  set(IS_ROOT_PROJECT TRUE)
else()
  set(IS_ROOT_PROJECT FALSE)
endif()

include(${CMAKE_CURRENT_LIST_DIR}/../../cmake/compiler-defines.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/../examples.cmake)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if (IS_ROOT_PROJECT)
  find_package(sick_perception_sdk COMPONENTS compact_receiver drivers sensor_configuration REQUIRED)
endif()

add_example(
  FAMILY multiScan100
  TARGET change_ip_address
  DEPENDENCIES sick_perception_sdk::drivers sick_perception_sdk::sensor_configuration
)
add_example(
  FAMILY multiScan100
  TARGET configuration
  DEPENDENCIES sick_perception_sdk::drivers sick_perception_sdk::sensor_configuration
)
add_example(
  FAMILY multiScan100
  TARGET data_streaming
  DEPENDENCIES sick_perception_sdk::drivers sick_perception_sdk::sensor_configuration
)
add_example(
  FAMILY multiScan100
  TARGET data_streaming_roi
  DEPENDENCIES sick_perception_sdk::drivers sick_perception_sdk::sensor_configuration
)
add_example(
  FAMILY multiScan100
  TARGET diagnosis
  DEPENDENCIES sick_perception_sdk::drivers sick_perception_sdk::sensor_configuration
)
add_example(
  FAMILY multiScan100
  TARGET multiple_devices
  DEPENDENCIES sick_perception_sdk::drivers sick_perception_sdk::sensor_configuration
)
add_example(
  FAMILY multiScan100
  TARGET object_detection
  DEPENDENCIES sick_perception_sdk::drivers sick_perception_sdk::sensor_configuration
)
add_example(
  FAMILY multiScan100
  TARGET low_level_streaming
  DEPENDENCIES sick_perception_sdk::drivers sick_perception_sdk::sensor_configuration
)
add_example(
  FAMILY multiScan100
  TARGET segmented_data
  DEPENDENCIES sick_perception_sdk::drivers sick_perception_sdk::sensor_configuration
)
add_example(
  FAMILY multiScan100
  TARGET write_to_pcd_file
  DEPENDENCIES sick_perception_sdk::drivers sick_perception_sdk::sensor_configuration
)