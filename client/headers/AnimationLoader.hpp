#pragma once

#include <unordered_map>
#include <vector>
#include <fstream>

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

class AnimationLoader{
public:

    std::unordered_map<std::string, sf::Vector2f> animation_sheet;
    // utilizes string name from map to load subset rect to sprite
    bool load(sf::Sprite* sprite, std::string sprite_name);

};

