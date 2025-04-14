add_library(
    game_engine game.cpp window.cpp paddle.cpp ball.cpp
    wall.cpp block.cpp textbox.cpp
)

find_package(SFML 3.0 COMPONENTS Graphics Window REQUIRED)
target_link_libraries(game_engine SFML::Graphics SFML::Window)
