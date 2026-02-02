# Function to add an example project.
# Usage: add_example(FAMILY <device_family> TARGET <target_name> [SOURCES <file1> <file2> ...] [DEPENDENCIES <dep1> <dep2> ... ])
function(add_example)
  set(options "")
  set(oneValueArgs FAMILY TARGET)
  set(multiValueArgs SOURCES DEPENDENCIES)
  cmake_parse_arguments(ARG "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

  if(NOT ARG_FAMILY)
    message(FATAL_ERROR "add_example: FAMILY argument is required")
  endif()
  if(NOT ARG_TARGET)
    message(FATAL_ERROR "add_example: TARGET argument is required")
  endif()

  set(TARGET_NAME "${ARG_FAMILY}_${ARG_TARGET}_example")

  add_executable(${TARGET_NAME})

  if(ARG_SOURCES)
    target_sources(${TARGET_NAME} PRIVATE ${ARG_SOURCES})
  else()
    target_sources(${TARGET_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/${ARG_TARGET}.cpp)
  endif()

  if(ARG_DEPENDENCIES)
    target_link_libraries(${TARGET_NAME} PRIVATE ${ARG_DEPENDENCIES})
  endif()
endfunction()
