project(tests)
message("[CMake]: Processing ${PROJECT_NAME} project")

enable_testing()
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage")

add_subdirectory(unit)

add_test(unit unit)
