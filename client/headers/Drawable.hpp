#pragma once

#include <vector>

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class Drawable {
public:
    Drawable();
    virtual void draw(sf::RenderWindow* window) {
        if (sprite.getTexture() != nullptr)
            window->draw(sprite);
    }
    static std::vector<Drawable*> drawables;
protected:
    sf::Sprite sprite;
};