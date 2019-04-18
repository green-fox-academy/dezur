cmake_minimum_required(VERSION 3.13)
project(fleet)

set(CMAKE_CXX_STANDARD 14)

add_executable(fleet main.cpp fleet.cpp fleet.h thing.cpp thing.h)