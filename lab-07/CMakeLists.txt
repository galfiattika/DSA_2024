cmake_minimum_required(VERSION 3.26)
project(lab_07 C)

set(CMAKE_C_STANDARD 23)

add_executable(lab_07 main.c
        source/folder.c
        header/folder.h)
