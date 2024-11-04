#include "ball.h"

Ball::Ball()
{
    m_ball.setRadius(3);
    m_ball.setFillColor(sf::Color::White);
    m_ball.setOrigin(m_ball.getRadius(), m_ball.getRadius());
    m_ball.setPosition(400, 200);
    m_lives = 3;
    m_score = 0;
}

void Ball::reset()
{
    m_ball.setPosition(400, 300);
    m_lives--;
}

int Ball::getRadius()
{
    return m_ball.getRadius();
}

int Ball::getScore()
{
    return m_score;
}

int Ball::getLives()
{
    return m_lives;
}

void Ball::move(sf::Vector2u windowSize, Paddle& l_paddle, Wall& l_wall, float elapsed)
{
    blockCollision(l_wall);
    windowCollision(windowSize);
    paddleCollision(l_paddle);
    m_ball.move(m_increment * elapsed);
}

void Ball::blockCollision(Wall& wall)
{
    for (int i = 0; i < wall.getBlocks().size(); i++) {
        Block block = wall.getBlocks()[i];
        if (!m_ball.getGlobalBounds().intersects(block.getGlobalBounds())) {
            continue;
        }
        m_score += block.getScore();
        // bool leftBlockx = m_ball.getPosition().x >= block.getPosition().x - getRadius();
        // bool rightBlockx = m_ball.getPosition().x + getRadius() <= block.getPosition().x + block.getSize().x;
        bool bottomBlocky = m_ball.getPosition().y - (block.getPosition().y + block.getSize().y) <= getRadius() && m_ball.getPosition().y >= block.getPosition().y + block.getSize().y;
        bool topBlocky = block.getPosition().y - m_ball.getPosition().y <= getRadius() && m_ball.getPosition().y <= block.getPosition().y;

        if (bottomBlocky || topBlocky) {
            m_increment.y = -m_increment.y;
        } else {
            m_increment.x = -m_increment.x;
        }
        wall.removeBlock(i);
    }
}

void Ball::windowCollision(sf::Vector2u windowSize)
{
    if ((m_ball.getPosition().x > windowSize.x - getRadius() && m_increment.x > 0) || (m_ball.getPosition().x - getRadius() < 0 && m_increment.x < 0)) {
        m_increment.x = -m_increment.x;
    }
    if ((m_ball.getPosition().y - getRadius() < 0 && m_increment.y < 0)) {
        m_increment.y = -m_increment.y;
    } else if (m_ball.getPosition().y > windowSize.y - getRadius() && m_increment.y > 0) {
        reset();
    }
}

void Ball::paddleCollision(Paddle& l_paddle)
{
    sf::Vector2i paddlePosition = l_paddle.getPosition();
    float paddleWidth = l_paddle.getSize().x;
    // float paddleHeight = l_paddle.getSize().y;
    bool leftPaddlex = m_ball.getPosition().x >= paddlePosition.x - getRadius();
    bool rightPaddlex = m_ball.getPosition().x + getRadius() <= paddlePosition.x + paddleWidth;
    bool paddley = m_ball.getPosition().y >= paddlePosition.y - getRadius() && m_ball.getPosition().y <= paddlePosition.y + getRadius();
    if (leftPaddlex && rightPaddlex && paddley) {
        m_increment.y = -m_increment.y;
        // If paddle moving in different direction to ball,
        // then change direction of ball in x direction
        if (l_paddle.getPhysicalDirection() * m_increment.x < 0 && l_paddle.getDirection() != Direction::None) {
            m_increment.x = -m_increment.x;
        }
    }
}

void Ball::pause()
{
    m_increment = sf::Vector2f(0, 0);
}

void Ball::resume()
{
    m_increment = sf::Vector2f(175.f, 300.f);
}
