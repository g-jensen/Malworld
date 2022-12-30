#pragma once

#include <iostream>

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

#include "Entity.hpp"
#include "Math.hpp"
#include "Keybinds.hpp"
#include "Animation.hpp"

class Player: public Entity {
public:
    Player(sf::Vector2f position, sf::Vector2f size);
    void load_animations();
    void update_animations();
    void update();
    sf::Vector2f get_size();
    
    // called whenever the Player intersects with a collidable
    void on_intersect(Collidable* c);

private:
    Animation walk_left;
    Animation walk_right;
};