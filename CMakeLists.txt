cmake_minimum_required(VERSION 3.17)
project(plazza LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED true)

enable_testing()

add_compile_options(
    "-Wall" "-Wextra" "-Wshadow" "-pedantic" "-Wpointer-arith" "-fpic"
)

if (CMAKE_BUILD_TYPE STREQUAL Testing)
    add_compile_options("-coverage")
endif()

add_subdirectory(src)
add_subdirectory(tests)
