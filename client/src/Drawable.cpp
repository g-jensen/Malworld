#include "../headers/Drawable.hpp"

std::vector<Drawable*> Drawable::drawables;

Drawable::Drawable() {
    drawables.push_back(this);
}