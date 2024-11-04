#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>

#include "block.h"
#include <iostream>

using namespace std;

class Wall {
public:
    Wall();
    ~Wall() = default;

    void render(sf::RenderWindow& window)
    {
        for (auto& m_block : m_blocks) {
            m_block.render(window);
        }
    }

    vector<Block> getBlocks() { return m_blocks; }

    void removeBlock(int index)
    {
        m_blocks.erase(m_blocks.begin() + index);
    }

    int getScore(int index)
    {
        return m_blocks[index].getScore();
    }

private:
    vector<Block> m_blocks;
};
