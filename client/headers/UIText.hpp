#pragma once

#include <SFML/Graphics/Text.hpp>

#include "UIGlobals.hpp"
#include "UIElement.hpp"

class UIText: public UIElement {
public:
    UIText();
    UIText(std::string text_string, sf::Vector2f position);
    void draw(sf::RenderWindow* window);
private:
    sf::Text text;
    std::string text_string;
    sf::Font* font;
    float font_size;
};