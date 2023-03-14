cmake_minimum_required(VERSION 3.24)
project(Linear_congruential_generator)

set(CMAKE_CXX_STANDARD 17)

add_executable(Linear_congruential_generator main.cpp Generator.cpp Generator.h Tree.cpp Tree.h Util.h Util.cpp Heap.cpp Heap.h)
