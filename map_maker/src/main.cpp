#include "../headers/Game.hpp"

#include "../../nlohmann-json/single_include/nlohmann/json.hpp"
using json = nlohmann::json;

int main() {

    Game* game = new Game();

    game->init();

    game->run();

    game->cleanup();

    delete game;
    
    std::cout << "Successful Exit" << std::endl;

    return 0;
}