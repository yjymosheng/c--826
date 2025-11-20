cmake_minimum_required(VERSION 3.31)
project(leetcode)

set(CMAKE_CXX_STANDARD 11)

add_executable(fib fib.cpp)
add_executable(max max.cpp)
add_executable(leetcode leetcode.cpp)


add_subdirectory(vector)
add_subdirectory(sort)
add_subdirectory(bitmap)
add_subdirectory(stack)
add_subdirectory(Fib-struct)
