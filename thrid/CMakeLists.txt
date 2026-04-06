cmake_minimum_required(VERSION 3.10)
project(rec_expantion CXX)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE Debug)

add_library(rec_expan STATIC rectangle_expansion.cpp)
add_library(ref_base STATIC refer_base.cpp)
add_executable(main main.cpp)
target_link_libraries(main rec_expan ref_base)