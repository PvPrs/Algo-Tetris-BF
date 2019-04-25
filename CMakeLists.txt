cmake_minimum_required(VERSION 3.13)
project(fillit C)

set(CMAKE_C_STANDARD 99)

add_executable(fillit
        src/main.c
        src/sort_list.c
        src/reader.c
        src/validator.c
        src/solver.c)

# includes external header files
target_include_directories(fillit PRIVATE ${CMAKE_SOURCE_DIR}/libft/includes)

# includes libraries
target_link_libraries(fillit ${CMAKE_SOURCE_DIR}/libft/libft.a)
