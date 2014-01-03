project(tests)
message("[CMake]: Processing ${PROJECT_NAME} project")

enable_testing()

add_subdirectory(unit)

add_test(unit unit)
