cmake_minimum_required(VERSION 3.14)
project(garden_app)

set(CMAKE_CXX_STANDARD 14)

add_executable(garden_app main.cpp Plant.cpp Plant.h Tree.cpp Tree.h Garden.cpp Garden.h)