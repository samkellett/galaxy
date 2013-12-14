project(tests)
message("[CMake]: Processing ${PROJECT_NAME} project")

add_subdirectory(${GALAXY_SOURCE_DIR}/tests/googletest)
add_subdirectory(unit)
