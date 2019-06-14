cmake_minimum_required(VERSION 3.13)
project(fillit C)

set(CMAKE_C_STANDARD 99)

add_custom_target(fillit COMMAND make -C ${fillit_SOURCE_DIR}
        CLION_EXE_DIR=${PROJECT_BINARY_DIR})