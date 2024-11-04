#include "game.h"

Game::Game()
    : m_window("Breakout", sf::Vector2u(600, 900))
    , m_paddle()
    , m_ball()
    , m_wall()
{
    RestartClock();
    srand(time(nullptr));

    m_scoreBox.setup(5, 14, 250, sf::Vector2f(10.f, 10.f));
    m_scoreBox.add("Score: " + to_string(m_ball.getScore()));
    m_livesBox.setup(5, 14, 250, sf::Vector2f(500.f, 10.f));
    m_livesBox.add("Lives: " + to_string(m_ball.getLives()));
}

void Game::Update()
{
    m_window.Update();
    m_paddle.move(m_window.GetWindowSize(), m_elapsed.asSeconds());
    m_ball.move(m_window.GetWindowSize(), m_paddle, m_wall, m_elapsed.asSeconds());
    int preivousScore = m_ball.getScore();
    if (!isPaused) {
        m_scoreBox.add("Score: " + to_string(m_ball.getScore()));
        m_livesBox.add("Lives: " + to_string(m_ball.getLives()));
    }
    if (m_ball.getLives() == 0) {
        restartGame(preivousScore);
    }
}

sf::Time Game::GetElapsed() { return m_elapsed; }
void Game::RestartClock() { m_elapsed = m_clock.restart(); }

void Game::HandleInput()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        isPaused = !isPaused;
        if (isPaused) {
            pauseGame();
        } else {
            resumeGame();
        }
        return;
    }
    if (isPaused) {
        return;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::H)) {
        m_paddle.setDirection(Direction::Left);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::L)) {
        m_paddle.setDirection(Direction::Right);
    } else {
        m_paddle.setDirection(Direction::None);
    }
}

void Game::restartGame(int previousScore)
{
    m_ball = Ball();
    m_wall = Wall();
    m_scoreBox.clear();
    m_livesBox.clear();
    m_scoreBox.add("Previous Score: " + to_string(previousScore));
    m_livesBox.add("Lives: " + to_string(m_ball.getLives()));
    isPaused = true;
    pauseGame();
}

void Game::pauseGame()
{
    m_ball.pause();
    m_paddle.pause();
}

void Game::resumeGame()
{
    m_ball.resume();
    m_paddle.resume();
}

Window* Game::GetWindow() { return &m_window; }

void Game::Render()
{
    m_window.BeginDraw();
    m_paddle.render(*m_window.GetRenderWindow());
    m_ball.render(*m_window.GetRenderWindow());
    m_wall.render(*m_window.GetRenderWindow());
    m_scoreBox.render(*m_window.GetRenderWindow());
    m_livesBox.render(*m_window.GetRenderWindow());
    m_window.EndDraw();
}
