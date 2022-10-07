#include "../headers/Collidable.hpp"

std::vector<Collidable*> Collidable::collidables;

Collidable::Collidable() {
    collidables.push_back(this);
}

void Collidable::setup_hitbox(sf::Vector2f position, sf::Vector2f size) {
    hit_box.left = position.x;
    hit_box.top = position.y;
    hit_box.width = size.x;
    hit_box.height = size.y;
}

bool Collidable::is_colliding(Collidable* c) {
    return c->hit_box.intersects(this->hit_box);
}

Collidable* Collidable::point_is_colliding(sf::Vector2f p) {
    for (Collidable* c: collidables) {
        if (c->hit_box.contains(p)) {
            return c;
        }
    }
    return nullptr;
}

float Collidable::raycast_collision(sf::Vector2f origin, sf::Vector2f direction, size_t max_depth) {
    size_t i = 0;
    sf::Vector2f v = origin;
    while (i < max_depth) {
        if (point_is_colliding(v) != nullptr) {
            return Math::distance(origin,v);
        }
        v += direction;
        i++;
    }
    return -1;
}