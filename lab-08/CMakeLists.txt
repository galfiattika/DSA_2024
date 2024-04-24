cmake_minimum_required(VERSION 3.26)
project(lab_08 C)

set(CMAKE_C_STANDARD 23)

add_executable(lab_08 main.c
        Sources/functions.c
        Headers/functions.h
        Sources/linked_list.c
        Headers/linked_list.h)
