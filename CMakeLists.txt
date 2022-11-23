cmake_minimum_required(VERSION 3.21)
project(CMakeProject)

set(CMAKE_CXX_STANDARD 17)

add_executable(CMakeProject src/main.cpp src/Classes/Extractor.cpp src/Classes/Extractor.h src/Helpers/StringHelper.cpp src/Helpers/StringHelper.h src/Helpers/VectorHelper.cpp src/Helpers/VectorHelper.h)
