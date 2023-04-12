add_executable(bordle
    src/input.c
    src/keybordle.c
    src/main.c
)

if(NOT MSVC)
    target_compile_options(bordle PRIVATE -Wall -Werror -Wextra -Wpedantic)
endif()
