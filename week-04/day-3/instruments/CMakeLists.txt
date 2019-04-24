cmake_minimum_required(VERSION 3.14)
project(instruments)

set(CMAKE_CXX_STANDARD 14)

add_executable(instruments main.cpp Instrument.cpp Instrument.h)