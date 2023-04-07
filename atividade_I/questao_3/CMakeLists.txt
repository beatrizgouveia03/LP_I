cmake_minimum_required(VERSION 3.5)

project(livroClass VERSION 1.0 LANGUAGES CXX)

include_directories (include)

add_executable( program 
                src/main.cpp
                src/Livro.cpp)
                
set_property(TARGET program PROPERTY CXX_STANDARD 20)