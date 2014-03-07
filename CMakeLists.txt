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

set(GXY_FLAGS "-Wall -Wextra -Wfatal-errors -Werror -fPIC")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${GXY_FLAGS}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GXY_FLAGS}")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DGALAXY_DEBUG")

# Package options:
set(Boost_USE_STATIC_LIBS OFF) # Turn this on eventually, but static needs fPIC
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "Build the GLFW example programs")
set(GLFW_BUILD_TESTS OFF CACHE BOOL "Build the GLFW test programs")
set(GLFW_BUILD_DOCS OFF CACHE BOOL "Build the GLFW documentation")
set(GLFW_INSTALL OFF CACHE BOOL "Generate installation target")

# CMake packages:
find_package(Boost 1.49 REQUIRED COMPONENTS
  system
  filesystem
)
find_package(Doxygen)
find_package(GLog REQUIRED)
find_package(Lua51 REQUIRED)
find_package(Luabind REQUIRED)
find_package(OpenGL REQUIRED)

# Disable warnings for submodules:
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -w")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -w")

# Submodule packages:
add_subdirectory(ext/freetype2)
add_subdirectory(ext/glfw)
add_subdirectory(ext/glxw)
add_subdirectory(ext/gmock)
add_subdirectory(ext/yaml-cpp)

# Renable warnings again:
string(REPLACE "-w" "" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
string(REPLACE "-w" "" CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}/src
  ${CMAKE_CURRENT_SOURCE_DIR}/include/galaxy
  ${CMAKE_CURRENT_SOURCE_DIR}/include/galaxy/gui

  ${CMAKE_CURRENT_SOURCE_DIR}/ext/freetype2/include
  ${CMAKE_CURRENT_SOURCE_DIR}/ext/glm
  ${CMAKE_CURRENT_SOURCE_DIR}/ext/glfw/include
  ${CMAKE_CURRENT_SOURCE_DIR}/ext/yaml-cpp/include

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
  src/componentmanager.cpp
  src/fontmanager.cpp
  src/galaxy.cpp
  src/game.cpp
  src/gameobject.cpp
  src/logger.cpp
  src/luastate.cpp
  src/objectmanager.cpp
  src/scene.cpp
  src/scenemanager.cpp
  src/shader.cpp
  src/shadermanager.cpp
  src/shaderprogram.cpp
  src/shadertype.cpp

  # Mixins
  src/gameable.cpp

  # Widgets
  src/label.cpp
  src/widget.cpp
)

file(GLOB_RECURSE GALAXY_HEADERS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} src/*.h)
file(GLOB_RECURSE GALAXY_INC_HEADERS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} include/*.h)

add_library(${PROJECT_NAME} SHARED
  ${GALAXY_HEADERS}
  ${GALAXY_INC_HEADERS}

  ${GALAXY_SOURCES}
)

target_link_libraries(${PROJECT_NAME}
  ${GLOG_LIBRARY}

  ${Boost_LIBRARIES}
  ${FREETYPE_LIBRARY}
  ${LUA_LIBRARIES}
  ${LUABIND_LIBRARY}

  freetype
  glxw
  glfw
  ${GLFW_LIBRARIES}
  yaml-cpp
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
