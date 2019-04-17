cmake_minimum_required(VERSION 3.13)
project(counter)

set(CMAKE_CXX_STANDARD 14)

add_executable(counter main.cpp Counter.cpp Counter.h)