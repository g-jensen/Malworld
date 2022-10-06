#include "../headers/Entity.hpp"

void Entity::update_transform() {
    velocity += acceleration;
    velocity = {
        Math::clamp(velocity.x,-MAX_ENT_SPEED,MAX_ENT_SPEED),
        Math::clamp(velocity.y,-MAX_ENT_SPEED,MAX_ENT_SPEED)
    };
    position += velocity;
}