cmake_minimum_required(VERSION 3.13...3.22 FATAL_ERROR)

project(factory_example3 VERSION 1.0.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(factory_example3)

set(INCLUDE_DIRS "${CMAKE_SOURCE_DIR}")

set(SOURCE_FILES 
    "${CMAKE_SOURCE_DIR}/main.cpp"
    "${CMAKE_SOURCE_DIR}/game_object_boat.cpp"
    "${CMAKE_SOURCE_DIR}/game_object_plane.cpp"
    "${CMAKE_SOURCE_DIR}/game_object_factory.cpp"
)

add_executable ( factory_example3 ${SOURCE_FILES})
target_include_directories ( factory_example3 PRIVATE ${INCLUDE_DIRS} )