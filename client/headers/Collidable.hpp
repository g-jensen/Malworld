#pragma once

#include <SFML/Graphics/Rect.hpp>

#include "Transform.hpp"
#include "Drawable.hpp"
#include "Math.hpp"

class Collidable: public Transform, public Drawable {
public:
    static std::vector<Collidable*> collidables;
    // returns distance of first collision from origin. -1 if none after max_depth
    static float raycast_collision(sf::Vector2f origin, sf::Vector2f direction, size_t max_depth);
    Collidable();
    bool do_collision;
    void setup_hitbox(sf::Vector2f position, sf::Vector2f size);
    bool is_colliding(Collidable* c);
protected:
    sf::FloatRect hit_box;
private:
    // returns pointer to the Collidable or nullptr if nothing
    static Collidable* point_is_colliding(sf::Vector2f p);
};