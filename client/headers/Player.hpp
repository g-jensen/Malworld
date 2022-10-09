#pragma once

#include <iostream>

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

#include "Entity.hpp"
#include "Math.hpp"
#include "Keybinds.hpp"


class Player: public Entity {
public:
    Player(sf::Vector2f position, sf::Vector2f size);
    void init_sprite(sf::Texture& texture);
    void update();
    sf::Vector2f get_size();
    float distance_from_ground();
    bool is_grounded();
    void on_intersect(Collidable* c);
private:
    sf::Vector2f size;
};