cmake_minimum_required(VERSION 3.10)

project(Labirint)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/Labirint")

add_library(Game STATIC Game.cpp)
add_library(Player STATIC Player.cpp)

add_library(Labirint1 STATIC Labirint.cpp)

add_executable(Labirint main.cpp)

target_link_libraries(Labirint Game Player)
