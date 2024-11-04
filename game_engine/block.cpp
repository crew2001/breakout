#include "block.h"

Block::Block(sf::Vector2f position, sf::Color color, int score)
{
    m_block.setPosition(position);
    m_block.setSize(m_blockSize);
    m_block.setFillColor(color);
    m_score = score;
}

void Block::render(sf::RenderWindow& window)
{
    window.draw(m_block);
}

sf::FloatRect Block::getGlobalBounds()
{
    return m_block.getGlobalBounds();
}

sf::Vector2f Block::getPosition()
{
    return m_block.getPosition();
}

sf::Vector2f Block::getSize()
{
    return m_block.getSize();
}

int Block::getScore()
{
    return m_score;
}
