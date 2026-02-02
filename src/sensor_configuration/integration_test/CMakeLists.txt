cmake_minimum_required(VERSION 3.24)

add_executable(sensor_configuration_integration_test
  ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/MultiScan200Configurator.test.cpp
)

find_package(GTest)

target_link_libraries(sensor_configuration_integration_test
  PUBLIC
    GTest::gtest
    ${PROJECT_NAME}::sensor_configuration
)

include(GoogleTest)
gtest_discover_tests(sensor_configuration_integration_test)