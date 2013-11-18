project(galaxy)

include_directories(
  ${Boost_INCLUDE_DIR}
)

set(GALAXY_SOURCES
  src/galaxy.cpp
)

file(GLOB GALAXY_HEADERS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} src/*.h)

add_library(${PROJECT_NAME} SHARED
  ${GALAXY_HEADERS}
  ${GALAXY_SOURCES}
)

target_link_libraries(${PROJECT_NAME}
  ${Boost_LIBRARIES}
)
