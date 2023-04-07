cmake_minimum_required(VERSION 3.5)

project(animalClass VERSION 1.0 LANGUAGES CXX)

include_directories (include)

add_executable( program 
                src/Zoo.cpp
                src/main.cpp
                src/Animal.cpp
                src/utilities.cpp)
set_property(TARGET program PROPERTY CXX_STANDARD 20)