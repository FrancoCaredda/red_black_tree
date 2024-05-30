cmake_minimum_required(VERSION 3.8)

project(red_black_tree)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(red_black_tree "src/main.cpp"
                              "src/red_black_tree.h")
