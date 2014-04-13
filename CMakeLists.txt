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

set(GXY_FLAGS "-Wall -Wextra -Wfatal-errors -Werror -Wno-missing-field-initializers -fPIC")
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
find_package(FreeType REQUIRED)
find_package(GLFW3 REQUIRED)
find_package(GLM REQUIRED)
find_package(GLog REQUIRED)
find_package(Lua51 REQUIRED)
find_package(Luabind REQUIRED)
find_package(OpenGL REQUIRED)
find_package(PNG REQUIRED)
find_package(YamlCpp REQUIRED)

# Submodule packages:
if(UNIX AND NOT APPLE)
  add_subdirectory(ext/glxw)
  set(GLXW glxw)
endif()
add_subdirectory(ext/gmock)

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}/src
  ${CMAKE_CURRENT_SOURCE_DIR}/include/galaxy
  ${CMAKE_CURRENT_SOURCE_DIR}/include/galaxy/gui

  ${CMAKE_CURRENT_BINARY_DIR}/ext/glxw/include

  ${Boost_INCLUDE_DIR}
  ${GLFW3_INCLUDE_PATH}
  ${GLM_INCLUDE_DIR}
  ${GLOG_INCLUDE_DIR}
  ${FREETYPE_INCLUDE_DIRS}
  ${LUA_INCLUDE_DIR}
  ${LUABIND_INCLUDE_DIR}
  ${OPENGL_INCLUDE_DIR}
  ${PNG_INCLUDE_DIRS}
  ${YAMLCPP_INCLUDE_DIR}
)

set(GALAXY_SOURCES
  # Core
  src/component.cpp
  src/componentmanager.cpp
  src/face.cpp
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
  src/texture.cpp
  src/vbo.cpp

  # Mixins
  src/gameable.cpp
)

file(GLOB_RECURSE GALAXY_HEADERS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} src/*.h)
file(GLOB_RECURSE GALAXY_INC_HEADERS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} include/*.h)

add_library(${PROJECT_NAME} SHARED
  ${GALAXY_HEADERS}
  ${GALAXY_INC_HEADERS}

  ${GALAXY_SOURCES}
)

target_link_libraries(${PROJECT_NAME}
  ${Boost_LIBRARIES}
  ${GLFW3_LIBRARY}
  ${GLOG_LIBRARY}
  ${GLXW}
  ${FREETYPE_LIBRARY}
  ${LUA_LIBRARIES}
  ${LUABIND_LIBRARY}
  ${OPENGL_LIBRARIES}
  ${PNG_LIBRARIES}
  ${YAMLCPP_LIBRARY}
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
