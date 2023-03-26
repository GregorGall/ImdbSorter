cmake_minimum_required(VERSION 3.0)

project(IMDB VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)

aux_source_directory(src SOURCE)
add_executable(imdb main.cpp ${SOURCE})
target_include_directories(imdb PRIVATE include)
