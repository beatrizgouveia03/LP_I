cmake_minimum_required(VERSION 3.5)

project(vector VERSION 1.0 LANGUAGES CXX)

include_directories (include)

add_executable( program 
                main.cpp)
                
set_property(TARGET program PROPERTY CXX_STANDARD 20)