#include "paddle.h"

Paddle::Paddle()
{
    m_paddle.setSize(m_paddleSize);
    m_paddle.setFillColor(sf::Color::White);
    m_paddle.setPosition(300, 800);
}

Direction Paddle::getDirection() { return m_direction; }

float Paddle::getPhysicalDirection()
{
    if (m_direction == Direction::Left) {
        return -1.0;
    } else if (m_direction == Direction::Right) {
        return 1.0;
    }
    return 0.0;
}

void Paddle::setDirection(Direction direction) { m_direction = direction; }

float Paddle::getSpeed() { return m_speed; }

void Paddle::move(sf::Vector2u l_windSize, float l_elapsed)
{
    sf::Vector2f l_windSizeFloat = static_cast<sf::Vector2f>(l_windSize);
    if ((getPosition().x > l_windSize.x - m_paddleSize.x && getDirection() == Direction::Right) || (getPosition().x < 0 && getDirection() == Direction::Left)) {
        setDirection(Direction::None);
    }
    // float fElapsed = m_elapsed.asSeconds();
    float delta = getPhysicalDirection() * l_elapsed * m_speed;
    // float paddle_x = getPosition().x + delta;
    // if (paddle_x <= 0.0) {
    //     paddle_x = 0.0;
    // }
    // if (paddle_x >= l_windSize.x - m_paddleSize.x) {
    //     paddle_x = l_windSize.x - m_paddleSize.x;
    // }
    // setPosition(paddle_x, getPosition().y);
    m_paddle.move(delta, 0.0);
}

void Paddle::setPosition(float x, float y) { m_paddle.setPosition(x, y); }

sf::Vector2f Paddle::getSize() { return m_paddle.getSize(); }

sf::Vector2i Paddle::getPosition()
{
    return sf::Vector2i(m_paddle.getPosition());
}

void Paddle::render(sf::RenderWindow& window) { window.draw(m_paddle); }

void Paddle::checkCollision() { }

void Paddle::pause()
{
    m_speed = 0.0;
}

void Paddle::resume()
{
    m_speed = 250.0;
}
