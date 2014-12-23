cmake_minimum_required(VERSION 3.0)
project (jkit)

include_directories (.)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_subdirectory (JKit)
add_subdirectory (Tests)
