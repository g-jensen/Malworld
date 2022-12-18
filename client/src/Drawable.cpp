#include "../headers/Drawable.hpp"

std::vector<Drawable*> Drawable::drawables;
sf::Texture Drawable::default_texture;

Drawable::Drawable() {
    drawables.push_back(this);
}