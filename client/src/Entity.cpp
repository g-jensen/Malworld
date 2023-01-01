#include "../headers/Entity.hpp"

std::vector<Entity*> Entity::entities;

Entity::Entity() {
    entities.push_back(this);
}

void Entity::update_transform() {
    velocity += acceleration;
    velocity = {
        Math::clamp(velocity.x,-MAX_ENT_SPEED,MAX_ENT_SPEED),
        Math::clamp(velocity.y,-MAX_ENT_SPEED,MAX_ENT_SPEED)
    };
    position += velocity;
}

float Entity::distance_from_ground() {
    float smallest_distance = -1;
    for (Collidable* c : Collidable::collidables) {
        if (this == c || 
            !c->do_collision ||
            hit_box.left+hit_box.width < c->hit_box.left ||
            c->hit_box.left+c->hit_box.width < hit_box.left
        ) {continue;}
        grounded = false;
        
        float dist = c->hit_box.top - (hit_box.top+hit_box.height);
        if (dist >= 0) {
            if (smallest_distance < 0) {
                smallest_distance = dist;
            } else if (dist < smallest_distance) {
                smallest_distance = dist;
            }
        }
    }
    return smallest_distance;
}

float Entity::distance_from_wall() {
    float smallest_distance = -1;
    for (Collidable* c : Collidable::collidables) {
        float player_x = velocity.x > 0 ? hit_box.left+hit_box.width : hit_box.left;
        float wall_x = velocity.x > 0 ? c->hit_box.left: c->hit_box.left+c->hit_box.width;
        if (this == c ||
            !c->do_collision ||
            hit_box.top+hit_box.height <= c->hit_box.top ||
            c->hit_box.top+c->hit_box.height <= hit_box.top
        ) {continue;}
        
        float dist = abs(wall_x - (player_x));
        if (smallest_distance < 0) {
            smallest_distance = dist;
        } else if (dist < smallest_distance) {
            smallest_distance = dist;
        }
    }
    return smallest_distance;
}

bool Entity::is_grounded() {
    return grounded;
}