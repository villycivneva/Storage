cmake_minimum_required(VERSION 3.15)
project(Storage)

set(CMAKE_CXX_STANDARD 14)

add_executable(Storage main.cpp Product.cpp Product.h Date.cpp Date.h Storage.cpp Storage.h)