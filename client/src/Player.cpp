#include "../headers/Player.hpp"


Player::Player(sf::Vector2f position, sf::Vector2f size) {
    this->position = position;
    this->do_collision = true;
    this->size = size;
    this->grounded = false;
    setup_hitbox(position,size);
    load_animations();
}

void Player::load_animations() {
    walk_left = Animation(this,64);
    walk_left.load_from_file("resources/player/walk_left.png");
    walk_left.do_repeat = true;

    walk_right = Animation(this,64);
    walk_right.load_from_file("resources/player/walk_right.png");
    walk_right.do_repeat = true;

    idle = Animation(this,64);
    idle.load_from_file("resources/player/idle.png");
}

void Player::update_animations() {
    walk_left.iterate();
    walk_right.iterate();
    if (velocity.x > 0 && !walk_right.is_playing()) {
        walk_left.stop();
        walk_right.play(32);
    }
    if (velocity.x < 0 && !walk_left.is_playing()) {
        walk_right.stop();
        walk_left.play(32);
    }
    if (Math::approximately_equal_to(velocity.x,0,1)) {
        walk_left.stop();
        walk_right.stop();
        idle.play(1);
    }
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

    // handle animations
    update_animations();
}

void Player::on_intersect(Collidable* c) {
    
}
