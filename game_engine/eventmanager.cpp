#include "eventmanager.h"

EventManager::EventManager(sf::RenderWindow& window, Ball& ball, Paddle& paddle)
    : m_window(window)
    , m_ball(ball)
    , m_paddle(paddle)
{
}

void EventManager::handleEvents()
{
    sf::Event event;
    while (m_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            m_window.close();
        }
    }
}
