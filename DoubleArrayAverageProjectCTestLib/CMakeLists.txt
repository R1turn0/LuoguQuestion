cmake_minimum_required(VERSION 3.20)

project(DoubleArrayAverage C)

set(CMAKE_C_STANDARD 90)
# 工程编译类型Debug/Release
set(CMAKE_BUILD_TYPE Debug)

link_directories(${PROJECT_SOURCE_DIR}/lib/)

add_executable(main main.c)

# 链接静态库
target_link_libraries(main myLib.a)
#target_link_libraries(main myDll.so)




## 设置cmake的最低版本
#cmake_minimum_required(VERSION 3.20)
## 设置工程名称 和版本
#project(DoubleArrayAverage C)
#
## 指定为C90版本
#set(CMAKE_C_STANDARD 90)
## 设置指定的C++编译器版本是必须的，如果不设置，或者为OFF，则指定版本不可用时，会使用上一版本。
#set(CMAKE_CXX_STANDARD_REQUIRED ON)
#
## 提供一个选项是OFF或者ON，如果没有初始值被提供则默认使用OFF
#option(USE_MYMATH "Use tutorial provided math implementation" ON)
#
## 指定版本号的配置文件
## configure_file(include/DoubleArrayAverage.h.in DoubleArrayAverage.h)
#
## 判断变量USE_MYMATH是否设置了ON，如果设置了配置lib library
#if(USE_MYMATH)
#    # 添加一个名字为lib的子编译路径
#    add_subdirectory(lib)
#
#    # 列出lib库的所有项目，并添加到外部库变量EXTRA_LIBS中
#    list(APPEND EXTRA_LIBS lib)
#
#    # 将子路径"${PROJECT_SOURCE_DIR}/lib"添加到外部路径变量EXTRA_INCLUDES中
#    list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/lib")
#endif()
#
#
## 增加生成可执行文件，生成的程序名称为：main
#add_executable(main main.c /lib/myDll.a)
## 对目标的外部库进行链接操作
# target_link_directories(tutorial PUBLIC ${EXTRA_LIBS})
#
## 为指定项目添加 include 路径
# target_include_directories(tutorial PUBLIC "${PROJECT_BINARY_DIR}" ${EXTRA_INCLUDES})
