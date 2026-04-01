cmake_minimum_required(VERSION 3.10)
project(string_compare CXX)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE Debug)

add_library(strcmp STATIC strcmp.cpp)
add_executable(str_compare main.cpp)
target_link_libraries(str_compare strcmp)