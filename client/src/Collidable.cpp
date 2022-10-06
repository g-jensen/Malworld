#include "../headers/Collidable.hpp"

void Collidable::setup_hitbox(sf::Vector2f position, sf::Vector2f size) {
    hit_box.left = position.x;
    hit_box.top = position.y;
    hit_box.width = size.x;
    hit_box.height = size.y;
}

bool Collidable::object_are_colliding(Collidable* c1, Collidable* c2) {
    return c1->hit_box.intersects(c2->hit_box);
}