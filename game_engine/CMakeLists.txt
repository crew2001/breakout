add_library(
    game_engine game.cpp window.cpp paddle.cpp ball.cpp
    wall.cpp block.cpp textbox.cpp
)

find_package(SFML 2.6 COMPONENTS graphics window REQUIRED)
target_link_libraries(game_engine sfml-graphics sfml-window)
