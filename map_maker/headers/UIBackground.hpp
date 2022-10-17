#pragma once

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

#include "UIElement.hpp"

class UIBackground: public UIElement {
public:
    UIBackground();
    UIBackground(sf::Vector2f relative_position, sf::Vector2f size);
    void set_sprite(sf::Sprite& sprite);
    sf::Sprite get_sprite();
    sf::Vector2f size;
    void draw(sf::RenderWindow* window);
protected:
    sf::Sprite sprite;
};