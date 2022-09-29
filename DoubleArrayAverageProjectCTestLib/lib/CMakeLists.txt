cmake_minimum_required(VERSION 3.20)
project(LIBDoubleArrayAverage C)

# ====设置变量=====
# LIBHELLO_SRC：lib库源文件
SET(LIBAVERAGE_SRC ./DoubleArrayAverage.c ./DoubleArrayAverage.h)
# CMAKE_LIBRARY_OUTPUT_DIRECTORY：编译最终输出目录
SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY .)

# 第一个参数为你需要构建的dll的名字，第二个为类型
ADD_LIBRARY(myDll SHARED ${LIBAVERAGE_SRC})
ADD_LIBRARY(myLib STATIC ${LIBAVERAGE_SRC})
# SHARED，动态库(扩展名为.so)
# STATIC，静态库(扩展名为.a)
# MODULE，在使用dyld的系统有效，如果不支持dyld，则被当作SHARED对待。
# EXCLUDE_FROM_ALL 参数的意思是这个库不会被默认构建，除非有其他的组件依赖或者手工构建。

# 依赖有别的动态库时
#TARGET_LINK_LIBRARIES(myDll lib1 lib2)

# 然后使用INSTALL指定了目标my_dll
INSTALL(TARGETS myDll)
INSTALL(TARGETS myLib)

# 为dll设置linker
# 指定dll的生成目录，这里是：./lib_out
SET_TARGET_PROPERTIES(myDll PROPERTIES LINKER_LANGUAGE C
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}
        LIBRARY_OUTPUT_DIRECTORY ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}
        OUTPUT_NAME "myDll"
        PREFIX "")
SET_TARGET_PROPERTIES(myLib PROPERTIES LINKER_LANGUAGE C
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}
        LIBRARY_OUTPUT_DIRECTORY ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}
        OUTPUT_NAME "myLib"
        PREFIX "")
# PROPERTIES LINKER_LANGUAGE C：声明为C链接库，提高DLL库的兼容性；
# XXX_OUTPUT_DIRECTORY：指定输出命令；
# OUTPUT_NAME：DLL库输出名称；
# PREFIX：DLL库前缀，若不设置，可能会加默认前缀；如，cygmy_dll.dll