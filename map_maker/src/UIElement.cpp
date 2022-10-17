#include "../headers/UIElement.hpp"

void UIElement::set_relative_position(sf::Vector2f pos) {
    relative_position = pos;
}

sf::Vector2f UIElement::get_relative_position() {
    return relative_position;
}

sf::Vector2f UIElement::get_real_position() {
    if (parent != nullptr) {
        return parent->get_real_position() + relative_position;
    } else {
        return relative_position;
    }
}

void UIElement::draw_children(sf::RenderWindow* window) {
    for (auto e: children) {
        if (e != nullptr) {
            e->draw(window);
        }
    }
}