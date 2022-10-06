#include "../headers/Object.hpp"

Object::Object(sf::Vector2f position, sf::Vector2f size) {
    this->position = position;
    setup_hitbox(position,size);
}

void Object::init_sprite(sf::Texture& texture) {
    sprite.setTexture(texture);
    sprite.setPosition(position);
    sprite.setScale({hit_box.width / texture.getSize().x, hit_box.height / texture.getSize().y});
}

sf::Sprite Object::get_sprite() {
    return sprite;
}