project(galaxy)
message("[CMake]: Processing Galaxy library")

set(GALAXY_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(GALAXY_BUILD_DIR ${CMAKE_CURRENT_BINARY_DIR})

set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-include ${GALAXY_SOURCE_DIR}/src/galaxy/global.h")

set(Boost_USE_STATIC_LIBS ON)
find_package(Boost 1.55 COMPONENTS REQUIRED)
find_package(OpenGL REQUIRED)

find_package(PkgConfig REQUIRED)
pkg_search_module(GLFW REQUIRED glfw3)

find_library(COCOA_LIBRARY Cocoa)
find_library(IOKIT_LIBRARY IOKit)
find_library(COREVIDEO_LIBRARY CoreVideo)

message("[CMake]: Cocoa: ${COCOA_LIBRARY}")
message("[CMake]: IOKit: ${IOKIT_LIBRARY}")
message("[CMake]: CoreVideo: ${COREVIDEO_LIBRARY}")

message("[CMake]: GLFW include dirs: ${GLFW_INCLUDE_DIRS}")
message("[CMake]: GLFW static libs: ${GLFW_STATIC_LIBRARIES}")

include_directories(
  ${Boost_INCLUDE_DIR}
  ${OPENGL_INCLUDE_PATH}
  ${GLFW_INCLUDE_DIRS}
  ${GALAXY_SOURCE_DIR}/ext/glm
)

link_directories(
  /usr/local/lib
)

set(GALAXY_SOURCES
  src/galaxy/game.cpp
  src/galaxy/galaxy.cpp
)

file(GLOB_RECURSE GALAXY_HEADERS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} src/*.h)

add_library(${PROJECT_NAME} SHARED
  ${GALAXY_HEADERS}
  ${GALAXY_SOURCES}
)

target_link_libraries(${PROJECT_NAME}
  ${COCOA_LIBRARY}
  ${OPENGL_LIBRARIES}
  ${IOKIT_LIBRARY}
  ${COREVIDEO_LIBRARY}

  ${Boost_LIBRARIES}
  ${GLFW_STATIC_LIBRARIES}
)

# add a target to generate API documentation with Doxygen
find_package(Doxygen)
if(DOXYGEN_FOUND)
  configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile
    ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile @ONLY
  )

  add_custom_target(doc
    ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/doc
    COMMENT "[CMake]: Generating API documentation with Doxygen" VERBATIM
  )
endif()

# Tests
add_subdirectory(ext/gtest)

add_subdirectory(tests)

add_dependencies(unit gtest)
