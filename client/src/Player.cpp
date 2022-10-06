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

void Player::update() {
    update_transform();
    sprite.setPosition(position);
    setup_hitbox(position,size);
}