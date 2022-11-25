cmake_minimum_required(VERSION 3.21)
project(CMakeProject)

set(CMAKE_CXX_STANDARD 17)

add_executable(CMakeProject src/main.cpp src/Classes/Extractor.cpp src/Classes/Extractor.h src/Helpers/StringHelper.cpp src/Helpers/StringHelper.h src/Helpers/StdVectorHelper.h src/Helpers/OutputHelper.cpp src/Helpers/OutputHelper.h src/Helpers/VectorHelper.h src/Helpers/VectorHelper.cpp src/Classes/Comparator.cpp src/Classes/Comparator.h)
