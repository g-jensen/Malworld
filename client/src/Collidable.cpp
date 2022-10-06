#include "../headers/Collidable.hpp"

void Collidable::setup_hitbox(sf::Vector2f position, sf::Vector2f size) {
    hit_box.left = position.x;
    hit_box.top = position.y;
    hit_box.width = size.x;
    hit_box.height = size.y;
}

bool Collidable::is_colliding(Collidable* c) {
    return c->hit_box.intersects(this->hit_box);
}