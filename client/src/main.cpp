#include <iostream>

#include "../headers/Game.hpp"

int main() {
    
    Game* game = new Game();

    game->init();

    game->run();

    game->cleanup();

    delete game;
    std::cout << "Successful Exit" << std::endl;



    return 0;
}