#include "wall.h"

Wall::Wall()
{
    for (int i = 0; i < 14; i++) {
        for (int j = 0; j < 8; j++) {
            sf::Color color;
            int score = 1;
            if (j < 2) {
                // red
                color = sf::Color(226, 0, 0);
                score = 7;
            } else if (j < 4) {
                // orange
                color = sf::Color(255, 90, 0);
                score = 5;
            } else if (j < 6) {
                // yellow
                color = sf::Color::Yellow;
                score = 3;
            } else {
                // green
                color = sf::Color::Green;
            }
            m_blocks.emplace_back(Block(sf::Vector2f(i * 43.f, 50.f + j * 10.f), color, score));
        }
    }
}
