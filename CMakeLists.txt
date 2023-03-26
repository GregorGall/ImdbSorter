cmake_minimum_required(VERSION 3.0)
project(IMDB VERSION 1.0)
set(CMAKE_CXX_STANDARD 20)

aux_source_directory(src SOURCE)
aux_source_directory(src/FileProcessors PROCESSORS)
set(SOURCE ${SOURCE} ${PROCESSORS})

add_executable(imdb main.cpp ${SOURCE})
target_include_directories(imdb PRIVATE include)
target_link_libraries(imdb pthread)