cmake_minimum_required(VERSION 3.13...3.22 FATAL_ERROR)

project(decorator_example2 VERSION 1.0.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(decorator_example2)

set(INCLUDE_DIRS "${CMAKE_SOURCE_DIR}")

add_executable ( decorator_example2 main.cpp )
target_include_directories ( decorator_example2 PRIVATE ${INCLUDE_DIRS} )