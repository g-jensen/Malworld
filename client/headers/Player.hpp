#pragma once

#include <SFML/Graphics/Sprite.hpp>

#include "Entity.hpp"
#include "Math.hpp"

class Player: public Entity {
public:
    Player(sf::Vector2f position);
    void update();
    sf::Sprite sprite;
};