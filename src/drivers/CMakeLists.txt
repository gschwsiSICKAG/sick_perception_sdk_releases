cmake_minimum_required(VERSION 3.24)

include(${CMAKE_SOURCE_DIR}/cmake/install-library.cmake)
include(${CMAKE_SOURCE_DIR}/cmake/compiler-defines.cmake)
include(${CMAKE_SOURCE_DIR}/cmake/clang-tidy.cmake)

set(LIB_NAME "drivers")

add_library(${LIB_NAME})
add_library(${PROJECT_NAME}::${LIB_NAME} ALIAS ${LIB_NAME})

set(LIB_SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/src/LRS4000.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/MultiScan200.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/MultiScan100.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/PicoScan100.cpp
)

target_sources(${LIB_NAME} PRIVATE ${LIB_SOURCES})

target_include_directories(${LIB_NAME} PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)

find_package(plog REQUIRED)

target_link_libraries(${LIB_NAME}
  PUBLIC
  ${PROJECT_NAME}::compact_receiver
  plog::plog
)

target_enable_clang_tidy(
  TARGET
    ${LIB_NAME}
  SOURCES
    ${LIB_SOURCES}
  INCLUDE_DIRS 
    ${CMAKE_CURRENT_SOURCE_DIR}/include
  LIBS
    ${PROJECT_NAME}::compact_receiver
)

#===============================================================================
# Installation
#===============================================================================
install_sdk_library(
  TARGET ${LIB_NAME}
  plog
)
