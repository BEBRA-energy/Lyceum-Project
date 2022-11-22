cmake_minimum_required(VERSION 3.21)
project(CMakeProject)

set(CMAKE_CXX_STANDARD 17)

add_executable(CMakeProject main.cpp Extractor.cpp Extractor.h StringHelper.cpp StringHelper.h)
