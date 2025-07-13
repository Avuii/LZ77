cmake_minimum_required(VERSION 3.15)
project(LZ77Project)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(LZ77 main.cpp lz77.cpp)
