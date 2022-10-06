#pragma once

#include <math.h>

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

#include "Collidable.hpp"

class Object: public Collidable {
public:
    Object(sf::Vector2f position, sf::Vector2f size);
    void init_sprite(sf::Texture& texture);
    sf::Sprite get_sprite();
private:
    sf::Sprite sprite;
};