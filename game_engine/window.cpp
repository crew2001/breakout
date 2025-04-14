#include "window.h"

Window::Window() { Setup("Window", sf::Vector2u(600, 1000)); }

Window::Window(const string& l_title, const sf::Vector2u& l_size)
{
    Setup(l_title, l_size);
}

Window::~Window() { Destroy(); }

void Window::Setup(const string l_title, const sf::Vector2u& l_size)
{
    m_windowTitle = l_title;
    m_windowSize = l_size;
    m_isFullscreen = false;
    m_isDone = false;
    m_window.setFramerateLimit(60);
    Create();
}

sf::RenderWindow* Window::GetRenderWindow() { return &m_window; }

void Window::Create()
{
    auto state = (m_isFullscreen ? sf::State::Fullscreen : sf::State::Windowed);
    m_window.create(sf::VideoMode({ m_windowSize.x, m_windowSize.y }), m_windowTitle, sf::Style::Default, state);
}

void Window::Destroy() { m_window.close(); }

void Window::Update()
{
    // sf::Event event;
    while (const optional event = m_window.pollEvent()) {
        if (event->is<sf::Event::Closed>()) {
            m_isDone = true;
        } else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
            if (keyPressed->scancode == sf::Keyboard::Scancode::F5) {
                ToggleFullscreen();
            }
            if (keyPressed->scancode == sf::Keyboard::Scancode::Escape) {
                m_isDone = true;
            }
        }
    }
}

void Window::ToggleFullscreen()
{
    m_isFullscreen = !m_isFullscreen;
    Destroy();
    Create();
}

void Window::BeginDraw() { m_window.clear(sf::Color::Black); }
void Window::EndDraw() { m_window.display(); }

bool Window::IsDone() { return m_isDone; }
bool Window::IsFullscreen() { return m_isFullscreen; }
sf::Vector2u Window::GetWindowSize() { return m_windowSize; }

void Window::Draw(sf::Drawable& l_drawable) { m_window.draw(l_drawable); }
