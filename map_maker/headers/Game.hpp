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
#include "EditMode.hpp"

#include "../../nlohmann-json/single_include/nlohmann/json.hpp"

class Game {
public:
    static sf::RenderWindow* window;
    static sf::Event event;
    static int max_framerate;
    static EditMode edit_mode;
    static std::vector<sf::RectangleShape*> rects;
    static sf::RectangleShape* selected_rect;
    static std::string serialize_game(std::vector<sf::RectangleShape*> rects);
    static void set_selected_rect(sf::RectangleShape* rect);
    static void init();
    static void run();
    static void cleanup();
};