cmake_minimum_required(VERSION 3.24)
project(TAC_test_init_funtion)

set(CMAKE_CXX_STANDARD 11)

# 设置动态库的搜索路径
# link_directories(${PROJECT_SOURCE_DIR})

add_executable(TAC_test_init_funtion main.cpp)

# 链接动态库
# target_link_libraries(TAC_test_init_funtion slm_runtime)
# target_link_libraries(TAC_test_init_funtion slm_control)