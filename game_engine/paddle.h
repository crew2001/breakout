#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

using namespace std;

enum class Direction { None,
    Left,
    Right };

class Paddle {
public:
    Paddle();
    ~Paddle() = default;

    Direction getDirection();
    void setDirection(Direction direction);
    float getSpeed();
    sf::Vector2i getPosition();
    void move(sf::Vector2u l_windSize, float l_elapsed);
    void render(sf::RenderWindow& window);
    sf::Vector2f getSize();
    void setPosition(float x, float y);
    float getPhysicalDirection();

    void pause();
    void resume();

private:
    void checkCollision();
    sf::RectangleShape m_paddle;
    sf::Vector2f m_paddleSize = sf::Vector2f(50.f, 10.f);
    Direction m_direction;
    float m_speed = 350.0;
};
