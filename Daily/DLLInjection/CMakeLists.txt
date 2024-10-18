cmake_minimum_required(VERSION 3.24)
project(DLLInjection)

set(CMAKE_CXX_STANDARD 11)

add_executable(DLLInjection main.cpp dll.cpp)
