#pragma once

#include <string>
#include <unordered_map>

#include <SFML/Window/Event.hpp>
#include "../../nlohmann-json/single_include/nlohmann/json.hpp"
using json = nlohmann::json;


class Keybinds{
public:
    static const std::unordered_map<std::string, sf::Keyboard::Key> string_to_key;
    static void load_keybinds(json data);

    static sf::Keyboard::Key move_left;
    static sf::Keyboard::Key move_right;
};