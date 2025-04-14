#include "eventmanager.h"

EventManager::EventManager(sf::RenderWindow& window, Ball& ball, Paddle& paddle)
    : m_window(window)
    , m_ball(ball)
    , m_paddle(paddle)
{
}

void EventManager::handleEvents()
{
}
