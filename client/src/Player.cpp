#include "../headers/Player.hpp"

Player::Player(sf::Vector2f position) {
    this->position = position;
    this->do_collision = true;
}

void Player::update() {
    update_transform();
    sprite.setPosition(position);
}