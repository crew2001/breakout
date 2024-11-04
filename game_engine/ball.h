#pragma once

#include "paddle.h"
#include "wall.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Ball {
public:
    Ball();
    ~Ball() = default;

    int getRadius();

    void render(sf::RenderWindow& window)
    {
        window.draw(m_ball);
    }

    void move(sf::Vector2u l_windSize, Paddle& l_paddle, Wall& l_wall, float l_elapsed);
    int getScore();
    int getLives();

    void reset();
    void pause();
    void resume();

private:
    sf::CircleShape m_ball;
    sf::Vector2f m_increment = sf::Vector2f(175.f, 350.f);
    void blockCollision(Wall& l_wall);
    void paddleCollision(Paddle& l_paddle);
    void windowCollision(sf::Vector2u l_windSize);
    int m_score;
    int m_lives;
};
