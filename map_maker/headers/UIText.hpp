#pragma once

#include <SFML/Graphics/Text.hpp>

#include <iostream>

#include "UIGlobals.hpp"
#include "UIElement.hpp"

class UIText: public UIElement {
public:
    UIText();
    UIText(std::string text_string, sf::Vector2f position);
    
    void set_string(std::string string);
    std::string get_string();

    void set_text(sf::Text text);
    sf::Text get_text();
    
    void draw(sf::RenderWindow* window);

    // does not change aspect ratio
    static sf::Text fitTextToSize(sf::Text text, sf::Vector2f size);
private:
    sf::Text text;
    std::string text_string;
    sf::Font* font;
    float font_size;
};