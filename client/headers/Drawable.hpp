#pragma once

#include <vector>

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>

#include "Transform.hpp"

class Drawable: public Transform {
public:
    Drawable();
    virtual void draw(sf::RenderWindow* window) {
        if (sprite.getTexture() != nullptr)
            window->draw(sprite);
    }
    virtual void set_sprite(sf::Sprite s) {
        sprite = s;
        sprite.setPosition(position);
    }
    static std::vector<Drawable*> drawables;
    static sf::Texture default_texture;
protected:
    sf::Sprite sprite;
};