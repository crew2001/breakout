#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

using namespace std;

class Window {
public:
    Window();
    Window(const string& l_title, const sf::Vector2u& l_size);
    ~Window();

    void BeginDraw(); // Clear the window.
    void EndDraw(); // Display the changes.

    void Update();

    bool IsDone();
    bool IsFullscreen();
    sf::Vector2u GetWindowSize();
    sf::RenderWindow* GetRenderWindow();

    void ToggleFullscreen();

    void Draw(sf::Drawable& l_drawable);

private:
    void Setup(const string l_title, const sf::Vector2u& l_size);
    void Destroy();
    void Create();

    sf::RenderWindow m_window;
    sf::Vector2u m_windowSize;
    string m_windowTitle;
    bool m_isDone;
    bool m_isFullscreen;
};
