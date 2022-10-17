#pragma once

#include <iostream>
#include <math.h>
#include <fstream>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>

#include "UIButton.hpp"

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