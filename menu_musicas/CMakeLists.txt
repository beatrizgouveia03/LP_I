cmake_minimum_required(VERSION 3.5)

project(menu_musicas VERSION 1.0 LANGUAGES CXX)

include_directories (include)

add_executable( program 
                src/main.cpp
                src/Musica.cpp
                src/Playlist.cpp)
set_property(TARGET program PROPERTY CXX_STANDARD 20)