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

float Player::distance_from_wall() {
    float smallest_distance = -1;
    for (Collidable* c : Collidable::collidables) {
        float player_x = velocity.x > 0 ? hit_box.left+hit_box.width : hit_box.left;
        float wall_x = velocity.x > 0 ? c->hit_box.left: c->hit_box.left+c->hit_box.width;
        if (this == c ||
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

bool Player::is_grounded() {
    return grounded;
}

void Player::update() {
    
    // handle vertical collision;
    float ground_dist = distance_from_ground();
    if (ground_dist >= 0) {
        if (Math::approximately_equal_to(ground_dist,0,velocity.y+1)) {
            acceleration.y = 0;
            velocity.y = 0;
            position.y += ground_dist;
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

    // handle horizontal collision
    float wall_dist = distance_from_wall();
    if (wall_dist != -1 && Math::approximately_equal_to(wall_dist,0,abs(velocity.x))) {
        acceleration.x = 0;
        if (velocity.x > 0) {
            position.x += wall_dist;
        } else {
            position.x -= wall_dist;
        }
        velocity.x = 0; 
    }

    update_transform();
    sprite.setPosition(position);
    setup_hitbox(position,size);
}

void Player::on_intersect(Collidable* c) {
    
}
