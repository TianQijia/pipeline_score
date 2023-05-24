cmake_minimum_required(VERSION 3.0)

project(ScoreManager)

set(CMAKE_CXX_STANDARD 11)

add_executable(ScoreManager Student.h ScoreManager.cpp ScoreManager.h DataStructure.h DataStructure.cpp main.cpp)
