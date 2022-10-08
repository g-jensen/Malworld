#include "../headers/Keybinds.hpp"

std::unordered_map<std::string, sf::Keyboard::Key> Keybinds::string_to_key = 
{
    {"A", sf::Keyboard::A},
    {"B", sf::Keyboard::B},
    {"C", sf::Keyboard::C},
    {"D", sf::Keyboard::D},
    {"E", sf::Keyboard::E},
    {"F", sf::Keyboard::F},
    {"G", sf::Keyboard::G},
    {"Space", sf::Keyboard::Space},
    // {"C", sf::Keyboard::C},
    // {"C", sf::Keyboard::C},
    // {"C", sf::Keyboard::C},
    // {"C", sf::Keyboard::C},
    // {"C", sf::Keyboard::C},
    // {"C", sf::Keyboard::C},
    // {"C", sf::Keyboard::C},
    // {"C", sf::Keyboard::C},
    // {"C", sf::Keyboard::C},
    // {"C", sf::Keyboard::C},
    // {"C", sf::Keyboard::C},
    // {"C", sf::Keyboard::C},
    // {"C", sf::Keyboard::C},
    // {"C", sf::Keyboard::C},
    // {"C", sf::Keyboard::C},
    // {"C", sf::Keyboard::C},
    // {"C", sf::Keyboard::C},
    // {"C", sf::Keyboard::C},
};

void Keybinds::load_keybinds(json data){
    auto key = Keybinds::string_to_key.find(data["move_left"]);

    if (key != Keybinds::string_to_key.end()) {
        Keybinds::move_left = key->second;
    }

    key = Keybinds::string_to_key.find(data["move_right"]);

    if (key != Keybinds::string_to_key.end()) {
        Keybinds::move_right = key->second;
    }
}

sf::Keyboard::Key Keybinds::move_left = sf::Keyboard::A;
sf::Keyboard::Key Keybinds::move_right = sf::Keyboard::D;
