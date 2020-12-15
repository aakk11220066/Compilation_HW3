cmake_minimum_required(VERSION 3.13)
project(HW3)

set(CMAKE_CXX_STANDARD 11)

add_executable(HW3 Framework.cpp hw3_output.cpp Symbol.cpp Exceptions.h lex.yy.c parser.tab.cpp Exceptions.cpp hw3_output.hpp)