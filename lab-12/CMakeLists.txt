cmake_minimum_required(VERSION 3.26)
project(lab_12 C)

set(CMAKE_C_STANDARD 23)

add_executable(lab_12 main.c
        Functions/bst.c
        Functions/bst.h)
