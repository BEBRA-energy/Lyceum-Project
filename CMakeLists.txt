cmake_minimum_required(VERSION 3.21)
project(CMakeProject)

set(CMAKE_CXX_STANDARD 17)

add_executable(CMakeProject src/main.cpp src/Classes/Extractor.cpp src/Classes/Extractor.h src/Helpers/StringHelper.cpp src/Helpers/StringHelper.h src/Helpers/StdVectorHelper.cpp src/Helpers/StdVectorHelper.h src/Classes/Main.cpp src/Classes/Main.h)
