cmake_minimum_required(VERSION 3.20)
project(LIBDoubleArrayAverage C)

# ====设置变量=====
# LIBHELLO_SRC：lib库源文件
SET(LIBAVERAGE_SRC ./DoubleArrayAverage.c ./DoubleArrayAverage.h)
# CMAKE_LIBRARY_OUTPUT_DIRECTORY：编译动态库最终输出目录
SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib_out)
# CMAKE_ARCHIVE_OUTPUT_DIRECTORY：编译静态库最终输出目录
SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib_out)

# 第一个参数为你需要构建的dll的名字，第二个为类型
ADD_LIBRARY(libmyDll SHARED ${LIBAVERAGE_SRC})
ADD_LIBRARY(libmyLib STATIC ${LIBAVERAGE_SRC})
# SHARED，动态库(扩展名为.so)
# STATIC，静态库(扩展名为.a)
# MODULE，在使用dyld的系统有效，如果不支持dyld，则被当作SHARED对待。
# EXCLUDE_FROM_ALL 参数的意思是这个库不会被默认构建，除非有其他的组件依赖或者手工构建。

# 依赖有别的动态库时
#TARGET_LINK_LIBRARIES(myDll lib1 lib2)

# 然后使用INSTALL指定了目标my_dll
INSTALL(TARGETS libmyDll)
INSTALL(TARGETS libmyLib)

# 为dll设置linker
# 指定dll的生成目录，这里是：./lib_out
SET_TARGET_PROPERTIES(libmyDll PROPERTIES LINKER_LANGUAGE C
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}
        LIBRARY_OUTPUT_DIRECTORY ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}
        OUTPUT_NAME "libmyDll"
        PREFIX "")
SET_TARGET_PROPERTIES(libmyLib PROPERTIES LINKER_LANGUAGE C
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}
        LIBRARY_OUTPUT_DIRECTORY ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}
        OUTPUT_NAME "libmyLib"
        PREFIX "")
# PROPERTIES LINKER_LANGUAGE C：声明为C链接库，提高DLL库的兼容性；
# XXX_OUTPUT_DIRECTORY：指定输出命令；
# OUTPUT_NAME：DLL库输出名称；
# PREFIX：DLL库前缀，若不设置，可能会加默认前缀；如，cygmy_dll.dll

# msbuild YourSolution.sln /p:Configuration=Release /p:Platform=x64
# 在上述命令中，"YourSolution.sln" 是您生成的解决方案文件的路径。"/p:Configuration=Release" 和 "/p:Platform=x64" 分别指定了要构建的配置和目标平台。您可以根据您的项目设置相应的配置和平台。
# 如果项目具有多个项目或构建目标，可以在 MSBuild 命令中使用"/t:YourProject"指定要构建的项目或目标
# 另外，MSBuild 还支持指定任务名称。任务是执行特定操作的构建组件。例如，Clean 是一个常见的任务，用于清理构建输出。
# msbuild YourSolution.sln /t:Clean
