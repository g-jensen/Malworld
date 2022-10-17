#pragma once

#include <vector>

#include <SFML/Window/Mouse.hpp>

#include "UIBackground.hpp"
#include "UIText.hpp"

class UIButton: public UIBackground {
public:
    UIButton(sf::Vector2f relative_position, sf::Vector2f size, std::string text_string);
    void draw(sf::RenderWindow* window);
    UIText text;
    void (*on_click)(void);
    static std::vector<UIButton*> buttons;
    static void register_button_presses(sf::RenderWindow* window);
};