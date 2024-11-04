#include <iostream>

#include "game_engine/game.h"

using namespace std;

int main() {
    Game game;
    while (!game.GetWindow()->IsDone()) {
        game.HandleInput();
        game.Update();
        game.Render();
        // sf::sleep(sf::seconds(0.005));
        game.RestartClock();
    }
}
