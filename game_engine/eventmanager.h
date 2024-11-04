#pragma once

#include "ball.h"
#include "paddle.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class EventManager {
public:
    EventManager(sf::RenderWindow& window, Ball& ball, Paddle& paddle);
    ~EventManager() = default;

    void handleEvents();

    void handleCollision();

private:
    sf::RenderWindow& m_window;
    Ball& m_ball;
    Paddle& m_paddle;
};
