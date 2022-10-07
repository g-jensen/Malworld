#include "../headers/Player.hpp"


Player::Player(sf::Vector2f position, sf::Vector2f size) {
    this->position = position;
    this->do_collision = true;
    this->size = size;
    setup_hitbox(position,size);
}

void Player::init_sprite(sf::Texture& texture) {
    sprite.setTexture(texture);
    sprite.setPosition(position);
    sprite.setScale({size.x / texture.getSize().x , size.y / texture.getSize().y});
}

bool Player::is_grounded() {
    sf::Vector2f origin = position + sf::Vector2f{size.x,size.y};
    sf::Vector2f direction = {0,1};
    if (Collidable::raycast_collision({origin},{direction},5) < 0 && Collidable::raycast_collision({origin - sf::Vector2f{size.x,0}},{direction},5) < 0) {
        return false;
    }
    return Collidable::raycast_collision({origin},{direction},5) < 1 || Collidable::raycast_collision({origin - sf::Vector2f{size.x,0}},{direction},5) < 1;
}

void Player::update() {
    update_transform();
    sprite.setPosition(position);
    setup_hitbox(position,size);

    if (is_grounded()) {
        velocity.y = 0;
        acceleration.y = 0;
    } else {
        acceleration.y = 2;
    }
}

void Player::on_intersect(Collidable* c) {
    float y_indent = this->hit_box.top+hit_box.height - c->hit_box.top;
    if (y_indent > 0) {
        position.y -= y_indent;
    }
}