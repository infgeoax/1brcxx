cmake_minimum_required(VERSION 3.8)
set(CMAKE_CXX_STANDARD 17)
project(1brc)
add_executable(create-sample src/create_sample.cpp
        src/time_me.h)
add_executable(run src/run.cpp)
add_executable(analyze src/analyze.c)
