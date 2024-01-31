cmake_minimum_required(VERSION 3.25)
project(MD5)

#set(CMAKE_GCC_STANDARD 98)
SET(CMAKE_C_STANDARD 99)

add_executable(MD5 main.cpp
        md5.cpp
        md5.h
        global.h
        mddriver.cpp)
