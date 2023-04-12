cmake_minimum_required(VERSION 3.0)

project(Betabordle)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_C_STANDARD 90)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(original)
add_subdirectory(remake)
