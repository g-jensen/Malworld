#pragma once

#include "UIInput.hpp"
#include "UIBackground.hpp"
#include "UIText.hpp"

template <typename T>
class UINumberInput: public UIInput {
public:
    UINumberInput(std::string label_text, T default_value, T max_value, T min_value);
    void process_event(sf::Event& event);
    void draw(sf::RenderWindow* window);
    UIBackground background;
    UIText label;
private:
    T value;
    T max_value;
    T min_value;
};