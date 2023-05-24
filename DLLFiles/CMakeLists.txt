cmake_minimum_required(VERSION 3.10)
project(my_plugin)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 设置编译选项和链接选项
if(MSVC)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
endif()

# 添加动态库目标，这里已经将所有动态库添加完全
add_library(my_plugin SHARED FindNULL.cpp TimerWork.cpp DataStructure.cpp ScoreManager.cpp)


