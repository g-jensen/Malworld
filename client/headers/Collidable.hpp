#pragma once

#include <SFML/Graphics/Rect.hpp>

#include "Transform.hpp"

class Collidable: public Transform {
public:
    bool do_collision;
    void setup_hitbox(sf::Vector2f position, sf::Vector2f size);
    bool is_colliding(Collidable* c);
protected:
    sf::FloatRect hit_box;
};