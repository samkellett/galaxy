project(galaxy)
message("[CMake]: Processing Galaxy library")

set(GALAXY_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(GALAXY_BUILD_DIR ${CMAKE_CURRENT_BINARY_DIR})

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${GALAXY_SOURCE_DIR}/cmake)

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
endif()

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DGALAXY_DEBUG")

find_package(GLog REQUIRED)
set(Boost_USE_STATIC_LIBS ON)
find_package(Boost 1.49 COMPONENTS REQUIRED)
find_package(OpenGL REQUIRED)
find_package(Lua51 REQUIRED)
find_package(Luabind REQUIRED)

find_package(PkgConfig REQUIRED)
pkg_search_module(FREETYPE REQUIRED freetype2)
pkg_search_module(GLFW REQUIRED glfw3)
if(APPLE)
  set(GLFW_LIB ${GLFW_STATIC_LIBRARIES})
elseif(UNIX)
  # FIXME: Can't link statically on Linux...
  set(GLFW_LIB ${GLFW_LIBRARIES})
endif()

if(APPLE)
  find_library(COCOA_LIBRARY Cocoa)
  find_library(IOKIT_LIBRARY IOKit)
  find_library(COREVIDEO_LIBRARY CoreVideo)
endif()

include_directories(
  src/galaxy

  ${GLOG_INCLUDE_DIR}

  ${Boost_INCLUDE_DIR}
  ${LUA_INCLUDE_DIR}
  ${LUABIND_INCLUDE_DIR}

  ${OPENGL_INCLUDE_PATH}
  ${FREETYPE_INCLUDE_DIRS}
  ${GLFW_INCLUDE_DIRS}
)

link_directories(
  /usr/local/lib
)

set(GALAXY_SOURCES
  src/galaxy/component.cpp
  src/galaxy/componentmanager.cpp
  src/galaxy/fontmanager.cpp
  src/galaxy/galaxy.cpp
  src/galaxy/game.cpp
  src/galaxy/gameobject.cpp
  src/galaxy/logger.cpp
  src/galaxy/objectmanager.cpp
  src/galaxy/scene.cpp
  src/galaxy/scenemanager.cpp
  src/galaxy/shader.cpp
  src/galaxy/shadermanager.cpp
  src/galaxy/shaderpipeline.cpp
  src/galaxy/shadertype.cpp

  src/galaxy/components/transform.cpp
  src/galaxy/components/guiscript.cpp
  src/galaxy/components/luascript.cpp

  src/galaxy/objects/camera.cpp
)

file(GLOB_RECURSE GALAXY_HEADERS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} src/*.h)

add_library(${PROJECT_NAME} SHARED
  ${GALAXY_HEADERS}
  ${GALAXY_SOURCES}
)

target_link_libraries(${PROJECT_NAME}
  ${GLOG_LIBRARY}

  ${Boost_LIBRARIES}
  ${LUA_LIBRARIES}
  ${LUABIND_LIBRARY}

  ${COCOA_LIBRARY}
  ${OPENGL_LIBRARIES}
  ${FREETYPE_LIBRARY}
  ${IOKIT_LIBRARY}
  ${COREVIDEO_LIBRARY}

  ${GLFW_LIB}
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
add_subdirectory(ext/gmock)
add_subdirectory(tests)

add_dependencies(unit gmock)
