project(unit)
message("[CMake]: Processing ${PROJECT_NAME} project")

include_directories(
  ${GALAXY_SOURCE_DIR}/src

  ${gtest_SOURCE_DIR}
  ${gtest_SOURCE_DIR}/include
  ${gmock_SOURCE_DIR}
  ${gmock_SOURCE_DIR}/include
)

set(UNIT_TESTS
  src/main.cpp

  src/teststatemanager.cpp
)

add_executable(${PROJECT_NAME}
  ${UNIT_TESTS}
)

target_link_libraries(${PROJECT_NAME}  
  gmock
  gmock_main

  galaxy
)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
  COMMAND ln -fs ${PROJECT_BINARY_DIR}/${PROJECT_NAME} ${CMAKE_BINARY_DIR}/${PROJECT_NAME}.run
  COMMENT "[CMake]: Creating symlink to unit tests"
)
