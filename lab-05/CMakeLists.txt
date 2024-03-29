cmake_minimum_required(VERSION 3.26)
project(lab_05 C)

set(CMAKE_C_STANDARD 23)

add_executable(lab_05 main.c
        Sources/stack.c
        Headers/stack.h
        Headers/constants.h
        Sources/regular_queue.c
        Headers/regular_queue.h
        Sources/circular_queue.c
        Headers/circular_queue.h)
