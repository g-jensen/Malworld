#include <iostream>
#include <fstream>

#include "../headers/Game.hpp"

#include "../../nlohmann-json/single_include/nlohmann/json.hpp"
using json = nlohmann::json;

int main() {
    
    std::ifstream f("test.json");
    json data = json::parse(f);
    std::cout << data << std::endl;

    Game* game = new Game();

    game->init();

    game->run();

    game->cleanup();

    delete game;

    std::cout << "Successful Exit" << std::endl;

    return 0;
}