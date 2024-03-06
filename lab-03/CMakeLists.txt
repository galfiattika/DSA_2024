cmake_minimum_required(VERSION 3.26)
project(lab_03 C)

set(CMAKE_C_STANDARD 23)

add_executable(lab_03 main.c
        Sources/functions.c
        Headers/functions.h
)
include_directories(Headers)
