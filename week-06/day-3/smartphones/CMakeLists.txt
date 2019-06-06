cmake_minimum_required(VERSION 3.14)
project(smartphones C)

set(CMAKE_C_STANDARD 11)

add_executable(smartphones main.c smartphones.h smartphones.c)