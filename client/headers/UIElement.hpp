#pragma once

#include <vector>

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class UIElement {
public:
    UIElement* parent = nullptr;
    std::vector<UIElement*> children;
    
    sf::Vector2f get_relative_position();
    void set_relative_position(sf::Vector2f pos);

    sf::Vector2f get_real_position();
    
    virtual void draw(sf::RenderWindow* window) = 0;
    void draw_children(sf::RenderWindow* window);
private:
    sf::Vector2f relative_position;
    sf::Vector2f real_position;
};