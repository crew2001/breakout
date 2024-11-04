#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "ball.h"
#include "paddle.h"
#include "textbox.h"
#include "wall.h"
#include "window.h"

using namespace std;

class Game {
public:
    Game();
    ~Game() = default;
    void HandleInput();
    void Update();
    void Render();
    Window* GetWindow();

    sf::Time GetElapsed();
    void RestartClock();
    void pauseGame();
    void resumeGame();

    void restartGame(int previousScore = 0);

private:
    Window m_window;
    sf::RectangleShape m_square;
    Paddle m_paddle;
    Ball m_ball;
    Wall m_wall;
    TextBox m_textBox;
    TextBox m_scoreBox;
    TextBox m_livesBox;
    void MoveSquare();
    void movePaddle();
    sf::Vector2i m_increment;
    sf::Clock m_clock;
    sf::Time m_elapsed;
    bool isPaused = false;
};
