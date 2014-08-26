cmake_minimum_required(VERSION 2.8)
project(galaxy)

# FIXME
cmake_policy(SET CMP0042 OLD)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

include(AddCxxFlag)

set(GALAXY_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(GALAXY_BUILD_DIR ${CMAKE_CURRENT_BINARY_DIR})

set(GLXW_LIBRARY "")
if(UNIX AND NOT APPLE)
  add_subdirectory(ext/glxw)
  set(GLXW_LIBRARY "glxw")
endif()

# Compiler Flags:
add_cxxflag("-std=c++11")

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
  add_cxxflag("-stdlib=libc++")
endif()

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}/src
  ${CMAKE_CURRENT_SOURCE_DIR}/include

  ${CMAKE_CURRENT_BINARY_DIR}/ext/glxw/include
)

set(GALAXY_SOURCES
  src/gxy/game.cpp

  src/gxy/test/functioncallmap.cpp
)

add_library(${PROJECT_NAME} SHARED ${GALAXY_SOURCES})

target_link_libraries(${PROJECT_NAME}
  ${GLXW}
)

# Tests
add_subdirectory(ext/gmock)
add_subdirectory(test)

add_dependencies(unit gmock gmock_main)

