#pragma once

#include <SFML/Window/Event.hpp>

#include "UIElement.hpp"

class UIInput: public UIElement {
public:
    virtual void process_event(sf::Event& event) = 0;
};