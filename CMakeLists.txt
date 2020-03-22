cmake_minimum_required(VERSION 2.8)
project(diamond-square)

list(APPEND CMAKE_CXX_FLAGS "-g -Wall -Wextra -O3")

include_directories(include)
set(CMAKE_SOURCE_DIR src/)

file(GLOB SOURCES ${CMAKE_SOURCE_DIR}/*.cpp)

add_executable(diamond-square ${SOURCES})