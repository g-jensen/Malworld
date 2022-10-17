#include "../headers/UIBackground.hpp"

UIBackground::UIBackground(){
    ;
}

UIBackground::UIBackground(sf::Vector2f relative_position, sf::Vector2f size) {
    set_relative_position(relative_position);
    this->size = size;
}

void UIBackground::set_sprite(sf::Sprite& sprite) {
    this->sprite = sprite;
    this->sprite.setScale({size.x / this->sprite.getTextureRect().width , size.y / this->sprite.getTextureRect().height});
}

sf::Sprite UIBackground::get_sprite() {
    return sprite;
}

void UIBackground::draw(sf::RenderWindow* window) {
    if (hidden) { return; }
    sprite.setPosition(get_real_position());
    if (sprite.getTexture() != nullptr) {
        window->draw(sprite);
    }
    draw_children(window);
}