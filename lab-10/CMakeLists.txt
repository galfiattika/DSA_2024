cmake_minimum_required(VERSION 3.26)
project(lab_10 C)

set(CMAKE_C_STANDARD 23)

add_executable(lab_10 main.c
        Sources/linked_list.c
        Headers/linked_list.h)
