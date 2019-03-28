cmake_minimum_required(VERSION 3.8)
project(basic_skills)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Algorithm/Sort/BubbleSort.hpp Algorithm/Sort/InsertSort.hpp Algorithm/Sort/SelectSort.hpp Algorithm/Sort/ShellSort.hpp)
add_executable(basic_skills ${SOURCE_FILES})