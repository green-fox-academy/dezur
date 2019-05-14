cmake_minimum_required(VERSION 3.14)
project(PI C)

set(CMAKE_C_STANDARD 11)

add_executable(PI main.c circle.c circle.h)