cmake_minimum_required(VERSION 3.13)
project(fillit C)

set(CMAKE_C_STANDARD 99)

add_executable(fillit
        main.c
        sort_list.c
        reader.c
        validator.c
        solver.c)

target_include_directories(fillit PRIVATE ${CMAKE_SOURCE_DIR}/libft/includes)

target_link_libraries(fillit ${CMAKE_SOURCE_DIR}/libft/libft.a)
