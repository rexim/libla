cmake_minimum_required(VERSION 2.8)
project(la)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror -std=c11 -pedantic")

add_subdirectory(la)
add_subdirectory(gaussian_elimination)
