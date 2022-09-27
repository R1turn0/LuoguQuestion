cmake_minimum_required(VERSION 3.22)
project(HexstrToBytes)

set(CMAKE_C_STANDARD 90)

add_executable(HexstrToBytes main.c HexstrToBytes.c HexstrToBytes.h)
