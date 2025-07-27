# CMakeLists.txt for a basic C++ project
cmake_minimum_required(VERSION 3.12)

# Project name and version
project(sees_tutorials VERSION 1.0.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(main src/main.cpp)
add_executable(q1 src/question1.cpp)
add_executable(q3 src/question3.cpp)