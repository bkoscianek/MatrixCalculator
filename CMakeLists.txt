cmake_minimum_required(VERSION 3.13)
project(MatrixCalculator)

set(CMAKE_CXX_STANDARD 17)

add_executable(MatrixCalculator main.cpp MatrixCalculator.cpp MatrixCalculator.h Matrix.h Matrix.cpp)