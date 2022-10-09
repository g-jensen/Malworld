#include "../headers/Player.hpp"


Player::Player(sf::Vector2f position, sf::Vector2f size) {
    this->position = position;
    this->do_collision = true;
    this->size = size;
    this->grounded = false;
    setup_hitbox(position,size);
}

void Player::init_sprite(sf::Texture& texture) {
    sprite.setTexture(texture);
    sprite.setPosition(position);
    sprite.setScale({size.x / texture.getSize().x , size.y / texture.getSize().y});
}

float Player::distance_from_ground() {
    float smallest_distance = -1;
    for (Collidable* c : Collidable::collidables) {
        if (this == c ||
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

bool Player::is_grounded() {
    return grounded;
}

void Player::update() {
    
    // handle vertical collision;
    float dist = distance_from_ground();
    if (dist >= 0) {
        if (Math::approximately_equal_to(dist,0,velocity.y+1)) {
            acceleration.y = 0;
            velocity.y = 0;
            position.y += dist;
            grounded = true;
        } else {
            acceleration.y = 0.5;
        }
    } else {
        acceleration.y = 0;
        velocity.y = 0;
        grounded = true;
    }
    
    // handle horizontal movement
    if (Math::approximately_equal_to(velocity.x,0,4)) {
        velocity.x = 0;
        acceleration.x = 0;
    } else if (velocity.x < 0) {
        acceleration.x = 0.5;
    } else if (velocity.x > 0) {
        acceleration.x = -0.5;
    }

    update_transform();
    sprite.setPosition(position);
    setup_hitbox(position,size);
}

void Player::on_intersect(Collidable* c) {
    
}
