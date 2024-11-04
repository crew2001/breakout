cmake_minimum_required(VERSION 3.29)
project(breakout)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
add_executable(breakout main.cpp)

add_subdirectory(game_engine)

include_directories(game_engine)
target_link_libraries(breakout game_engine)
