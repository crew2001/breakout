#pragma once

#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string>
#include <vector>

using namespace std;

using MessageContainer = vector<string>;

class TextBox {
public:
    TextBox();
    TextBox(int l_visible, int l_charSize, int l_width, sf::Vector2f l_screenPos);
    ~TextBox() = default;

    void setup(int l_visible, int l_charSize, int l_width, sf::Vector2f l_screenPos);
    void render(sf::RenderWindow& l_window);

    void add(string l_message);

    void clear()
    {
        m_messages.clear();
    };

private:
    int m_numVisible;
    MessageContainer m_messages;
    sf::RectangleShape m_backdrop;
    sf::Font m_font;
    sf::Text m_content;
};
