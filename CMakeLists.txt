cmake_minimum_required(VERSION 3.10)
project(ADTMap)

set(CMAKE_CXX_STANDARD 11)

add_executable(ADTMap main.cpp Map.cpp Map.h Car.cpp Car.h HashTable.cpp HashTable.h)