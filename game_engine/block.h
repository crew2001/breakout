#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Block {
public:
    Block(sf::Vector2f position, sf::Color color, int score);
    ~Block() = default;

    void render(sf::RenderWindow& window);
    void setPosition(float x, float y);
    sf::Vector2f getSize();
    sf::Vector2f getPosition();
    sf::FloatRect getGlobalBounds();
    int getScore();

private:
    sf::RectangleShape m_block;
    float block_width = 40.f;
    float block_height = 5.f;
    sf::Vector2f m_blockSize;
    int m_score;
};
