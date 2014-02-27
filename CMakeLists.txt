project(galaxy)
message("[CMake]: Processing Galaxy library")

set(GALAXY_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(GALAXY_BUILD_DIR ${CMAKE_CURRENT_BINARY_DIR})

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${GALAXY_SOURCE_DIR}/cmake)

# Compiler Flags:
if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
endif()

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DGALAXY_DEBUG")

# Package options:
set(Boost_USE_STATIC_LIBS ON)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "Build the GLFW example programs")
set(GLFW_BUILD_TESTS OFF CACHE BOOL "Build the GLFW test programs")
set(GLFW_BUILD_DOCS OFF CACHE BOOL "Build the GLFW documentation")
set(GLFW_INSTALL OFF CACHE BOOL "Generate installation target")

# CMake packages:
find_package(Boost 1.49 COMPONENTS REQUIRED)
find_package(Doxygen)
find_package(Freetype REQUIRED)
find_package(GLog REQUIRED)
find_package(Lua51 REQUIRED)
find_package(Luabind REQUIRED)
find_package(OpenGL REQUIRED)

# Submodule packages:
add_subdirectory(ext/glfw)
add_subdirectory(ext/gmock)

include_directories(
  src/galaxy

  ${GLOG_INCLUDE_DIR}

  ${Boost_INCLUDE_DIR}
  ${FREETYPE_INCLUDE_DIRS}
  ${LUA_INCLUDE_DIR}
  ${LUABIND_INCLUDE_DIR}

  ext/glfw/include
)

link_directories(
  /usr/local/lib
)

set(GALAXY_SOURCES
  src/galaxy/component.cpp
  src/galaxy/fontmanager.cpp
  src/galaxy/galaxy.cpp
  src/galaxy/game.cpp
  src/galaxy/gameobject.cpp
  src/galaxy/logger.cpp
  src/galaxy/luastate.cpp
  src/galaxy/scene.cpp
  src/galaxy/scenemanager.cpp
  src/galaxy/shader.cpp
  src/galaxy/shadermanager.cpp
  src/galaxy/shaderprogram.cpp
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
  ${FREETYPE_LIBRARY}
  ${LUA_LIBRARIES}
  ${LUABIND_LIBRARY}

  glfw
  ${GLFW_LIBRARIES}
)

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

execute_process(
  COMMAND ln -fs ${PROJECT_SOURCE_DIR}/scripts/gxy ${CMAKE_SOURCE_DIR}/gxy
)

# Tests
add_subdirectory(tests)

add_dependencies(unit gmock)
