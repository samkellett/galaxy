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

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fPIC")
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
add_subdirectory(ext/glxw)
add_subdirectory(ext/gmock)
add_subdirectory(ext/yaml-cpp)

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}/src
  ${CMAKE_CURRENT_SOURCE_DIR}/include/galaxy
  ${CMAKE_CURRENT_SOURCE_DIR}/include/galaxy/components
  ${CMAKE_CURRENT_SOURCE_DIR}/include/galaxy/gui
  ${CMAKE_CURRENT_SOURCE_DIR}/include/galaxy/objects

  ${CMAKE_CURRENT_SOURCE_DIR}/ext/glm
  ${CMAKE_CURRENT_SOURCE_DIR}/ext/glfw/include
  ${CMAKE_CURRENT_BINARY_DIR}/ext/glxw/include

  ${GLOG_INCLUDE_DIR}
  ${Boost_INCLUDE_DIR}
  ${FREETYPE_INCLUDE_DIRS}
  ${LUA_INCLUDE_DIR}
  ${LUABIND_INCLUDE_DIR}
)

set(GALAXY_SOURCES
  # Core
  src/component.cpp
  src/fontmanager.cpp
  src/galaxy.cpp
  src/game.cpp
  src/gameobject.cpp
  src/logger.cpp
  src/luastate.cpp
  src/scene.cpp
  src/scenemanager.cpp
  src/shader.cpp
  src/shadermanager.cpp
  src/shaderprogram.cpp
  src/shadertype.cpp

  # Components
  src/transform.cpp
  src/guiscript.cpp
  src/luascript.cpp

  # Objects
  src/camera.cpp
)

file(GLOB_RECURSE GALAXY_HEADERS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} src/*.h)
file(GLOB_RECURSE GALAXY_INCLUDE_HEADERS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} include/*.h)

add_library(${PROJECT_NAME} SHARED
  ${GALAXY_HEADERS}
  ${GALAXY_INCLUDE_HEADERS}

  ${GALAXY_SOURCES}
)

target_link_libraries(${PROJECT_NAME}
  ${GLOG_LIBRARY}

  ${Boost_LIBRARIES}
  ${FREETYPE_LIBRARY}
  ${LUA_LIBRARIES}
  ${LUABIND_LIBRARY}

  glxw
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
