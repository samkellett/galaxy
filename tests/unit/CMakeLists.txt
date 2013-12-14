project(unit)
message("[CMake]: Processing ${PROJECT_NAME} project")

enable_testing()

include_directories(
  ${gtest_SOURCE_DIR}
  ${gtest_SOURCE_DIR}/include
)

set(UNIT_TESTS
  src/testgtest.cpp
)

add_executable(${PROJECT_NAME}
  ${UNIT_TESTS}
)

target_link_libraries(${PROJECT_NAME}
  gtest
  gtest_main
)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
  COMMAND ln -s ${PROJECT_BINARY_DIR}/${PROJECT_NAME} ${CMAKE_BINARY_DIR}/${PROJECT_NAME}.run
)

add_test(unit ${PROJECT_NAME})
