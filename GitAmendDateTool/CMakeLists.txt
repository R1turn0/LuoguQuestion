cmake_minimum_required(VERSION 3.24)
project(GitAmendDateTool)

set(CMAKE_CXX_STANDARD 11)

add_executable(GitAmendDateTool main.cpp)

target_link_libraries(GitAmendDateTool -static)