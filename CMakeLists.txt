cmake_minimum_required(VERSION 3.20)

project(RailDB)

add_executable(RailDB ./src/engine/engine.cpp)

add_subdirectory(src/engine)

