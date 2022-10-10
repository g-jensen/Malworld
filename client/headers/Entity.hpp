#pragma once

#include <SFML/System/Vector2.hpp>

#include "Collidable.hpp"
#include "Math.hpp"
#include "Globals.hpp"

class Entity: public Collidable {
public:
    virtual void update() = 0;
    void update_transform();
    sf::Vector2f velocity;
    sf::Vector2f acceleration;
};