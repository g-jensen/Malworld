#include "../headers/Keybinds.hpp"

const std::unordered_map<std::string, sf::Keyboard::Key> Keybinds::string_to_key = 
{
    {"A", sf::Keyboard::A},
    {"B", sf::Keyboard::B},
    {"C", sf::Keyboard::C},
    {"D", sf::Keyboard::D},
    {"E", sf::Keyboard::E},
    {"F", sf::Keyboard::F},
    {"G", sf::Keyboard::G},
    {"H", sf::Keyboard::H},
    {"I", sf::Keyboard::I},
    {"J", sf::Keyboard::J},
    {"K", sf::Keyboard::K},
    {"L", sf::Keyboard::L},
    {"M", sf::Keyboard::M},
    {"N", sf::Keyboard::N},
    {"O", sf::Keyboard::O},
    {"P", sf::Keyboard::P},
    {"Q", sf::Keyboard::Q},
    {"R", sf::Keyboard::R},
    {"S", sf::Keyboard::S},
    {"T", sf::Keyboard::T},
    {"U", sf::Keyboard::U},
    {"V", sf::Keyboard::V},
    {"W", sf::Keyboard::W},
    {"X", sf::Keyboard::X},
    {"Y", sf::Keyboard::Y},
    {"Z", sf::Keyboard::Z},
    {"Space", sf::Keyboard::Space},
    {"LControl", sf::Keyboard::LControl},
    {"RControl", sf::Keyboard::RControl},
    {"LShift", sf::Keyboard::LShift},
    {"RShift", sf::Keyboard::RShift},
    {"RAlt", sf::Keyboard::RAlt},
    {"LAlt", sf::Keyboard::LAlt},
    {"Tab", sf::Keyboard::Tab},
    {"Up", sf::Keyboard::Up},
    {"Down", sf::Keyboard::Down},
    {"Left", sf::Keyboard::Left},
    {"Right", sf::Keyboard::Right},
    {"NUM_0", sf::Keyboard::Num0},
    {"NUM_1", sf::Keyboard::Num1},
    {"NUM_2", sf::Keyboard::Num2},
    {"NUM_3", sf::Keyboard::Num3},
    {"NUM_4", sf::Keyboard::Num4},
    {"NUM_5", sf::Keyboard::Num5},
    {"NUM_6", sf::Keyboard::Num6},
    {"NUM_7", sf::Keyboard::Num7},
    {"NUM_8", sf::Keyboard::Num8},
    {"NUM_9", sf::Keyboard::Num9},
    {"NUMPAD_0", sf::Keyboard::Numpad0},
    {"NUMPAD_1", sf::Keyboard::Numpad1},
    {"NUMPAD_2", sf::Keyboard::Numpad2},
    {"NUMPAD_3", sf::Keyboard::Numpad3},
    {"NUMPAD_4", sf::Keyboard::Numpad4},
    {"NUMPAD_5", sf::Keyboard::Numpad5},
    {"NUMPAD_6", sf::Keyboard::Numpad6},
    {"NUMPAD_7", sf::Keyboard::Numpad7},
    {"NUMPAD_8", sf::Keyboard::Numpad8},
    {"NUMPAD_9", sf::Keyboard::Numpad9},
};

const std::vector<sf::Keyboard::Key> Keybinds::numbers = {
    sf::Keyboard::Num0, 
    sf::Keyboard::Num1,
    sf::Keyboard::Num2, 
    sf::Keyboard::Num3, 
    sf::Keyboard::Num4, 
    sf::Keyboard::Num5, 
    sf::Keyboard::Num6, 
    sf::Keyboard::Num7, 
    sf::Keyboard::Num8, 
    sf::Keyboard::Num9
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

    key = Keybinds::string_to_key.find(data["jump"]);
    if (key != Keybinds::string_to_key.end()) {
        Keybinds::jump = key->second;
    }
}

sf::Keyboard::Key Keybinds::move_left = sf::Keyboard::A;
sf::Keyboard::Key Keybinds::move_right = sf::Keyboard::D;
sf::Keyboard::Key Keybinds::jump = sf::Keyboard::Space;