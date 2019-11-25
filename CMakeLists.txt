cmake_minimum_required(VERSION 3.15)
project(exercises)

set(CMAKE_CXX_STANDARD 14)

add_executable(exercises LinkedList.cpp library.cpp library.h AvlNode.cpp AvlNode.h AvlTree.cpp AvlTree.h Calculator.cpp)