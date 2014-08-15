project(galaxy)

cmake_policy(SET CMP0042 OLD)

set(GALAXY_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(GALAXY_BUILD_DIR ${CMAKE_CURRENT_BINARY_DIR})

# Compiler Flags:
if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
endif()

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}/src
  ${CMAKE_CURRENT_SOURCE_DIR}/include
)

set(GALAXY_SOURCES
  src/gxy/game.cpp

  src/gxy/test/functioncallmap.cpp
)

add_library(${PROJECT_NAME} SHARED ${GALAXY_SOURCES})

# Tests:
add_subdirectory(ext/gmock)
add_subdirectory(test)

add_dependencies(unit gmock)
add_test(test unit)
