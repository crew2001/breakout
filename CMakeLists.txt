cmake_minimum_required(VERSION 3.29)
project(breakout)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


configure_file(
    ${CMAKE_SOURCE_DIR}/Roboto-Regular.ttf
    ${CMAKE_BINARY_DIR}/game_engine/Roboto-Regular.ttf
    COPYONLY
)

add_executable(breakout main.cpp)

add_subdirectory(game_engine)

include_directories(game_engine)
target_link_libraries(breakout game_engine)
