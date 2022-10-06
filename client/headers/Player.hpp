#pragma once

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

#include "Entity.hpp"
#include "Math.hpp"

class Player: public Entity {
public:
    Player(sf::Vector2f position, sf::Vector2f size);
    void init_sprite(sf::Texture& texture);
    void update();
    sf::Sprite sprite;
    sf::Vector2f size;
};