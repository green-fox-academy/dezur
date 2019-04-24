cmake_minimum_required(VERSION 3.14)
project(instruments)

set(CMAKE_CXX_STANDARD 14)

add_executable(instruments main.cpp Instrument.cpp Instrument.h StringedInstrument.cpp StringedInstrument.h ElectricGuitar.cpp ElectricGuitar.h BassGuitar.cpp BassGuitar.h Violin.cpp Violin.h)