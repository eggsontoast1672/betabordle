# Init
cmake_minimum_required(VERSION 3.22)
project(Betabordle)

# Global
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Bordle
add_executable(bordle src/main.c src/utils.c)
set_property(TARGET bordle PROPERTY C_STANDARD 90)
if(NOT MSVC)
    target_compile_options(bordle PRIVATE -Wall -Werror -Wextra)
endif()
