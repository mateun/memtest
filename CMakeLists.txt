cmake_minimum_required(VERSION 3.0) 
project(mem_test)

file(GLOB sources src/*.cpp)

add_executable(app ${sources})
