#pragma once

#include <math.h>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/Texture.hpp>

#include "Player.hpp"
#include "Time.hpp"
#include "Object.hpp"
#include "Keybinds.hpp"
#include <fstream>

class Game {
public:
    sf::RenderWindow* window;
    sf::Event event;
    int max_framerate;
    Game();
    void init();
    void run();
    void cleanup();
};