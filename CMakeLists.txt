cmake_minimum_required(VERSION 3.30)

project(cursedcpp)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)


add_executable(cursed cursed.cpp)
