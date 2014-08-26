cmake_minimum_required(VERSION 2.8)
project(galaxy)

cmake_policy(VERSION 2.8)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

include(AddCxxFlag)

set(GALAXY_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(GALAXY_BUILD_DIR ${CMAKE_CURRENT_BINARY_DIR})

add_subdirectory(ext/glxw)

# Compiler Flags:
if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
  add_cxxflag("-std=c++11")
  add_cxxflag("-stdlib=libc++")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
  add_cxxflag("-std=c++11")
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
  glxw
)

# Tests
add_subdirectory(ext/gmock)
add_subdirectory(test)

add_dependencies(test gmock gmock_main)

