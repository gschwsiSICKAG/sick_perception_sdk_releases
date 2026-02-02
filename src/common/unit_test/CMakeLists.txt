cmake_minimum_required(VERSION 3.24)

set(TEST_NAME common_unit_test)
set(TEST_SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/version.test.cpp
)

add_executable(${TEST_NAME})

target_sources(${TEST_NAME}
  PRIVATE
    ${TEST_SOURCES}
)

find_package(GTest)

target_link_libraries(${TEST_NAME}
  PRIVATE
    GTest::gtest
    ${PROJECT_NAME}::common
)

include(GoogleTest)

# Address Sanitizer variant
set(TEST_NAME_ASAN ${TEST_NAME}_asan)

add_executable(${TEST_NAME_ASAN} EXCLUDE_FROM_ALL)

target_sources(${TEST_NAME_ASAN}
  PRIVATE
    ${TEST_SOURCES}
)

target_link_libraries(${TEST_NAME_ASAN}
  PRIVATE
    GTest::gtest
    ${PROJECT_NAME}::common
)

target_compile_options(${TEST_NAME_ASAN} PRIVATE -fsanitize=address -fno-omit-frame-pointer)
target_link_options(${TEST_NAME_ASAN} PRIVATE -fsanitize=address)
