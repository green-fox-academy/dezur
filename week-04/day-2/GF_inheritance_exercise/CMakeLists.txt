cmake_minimum_required(VERSION 3.14)
project(GF_inheritance_exercise)

set(CMAKE_CXX_STANDARD 14)

add_executable(GF_inheritance_exercise main.cpp Person.h Person.cpp Student.h Student.cpp Mentor.h Mentor.cpp Sponsor.cpp Sponsor.h Cohort.cpp Cohort.h)