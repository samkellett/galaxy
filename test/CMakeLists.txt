project(unit)

enable_testing()

include_directories(
  ${gtest_SOURCE_DIR}/include
  ${gmock_SOURCE_DIR}/include
)

set(UNIT_TESTS
  src/main.cpp
)

add_executable(${PROJECT_NAME} ${UNIT_TESTS})

target_link_libraries(${PROJECT_NAME}
  gmock
  gmock_main
)

