#include "../headers/UIButton.hpp"

std::vector<UIButton*> UIButton::buttons;

UIButton::UIButton(sf::Vector2f relative_position, sf::Vector2f size, std::string text_string) {
    set_relative_position(relative_position);
    this->size = size;
    text = UIText(text_string,{0,0});
    text.parent = this;
    children.push_back(&text);
    buttons.push_back(this);
}

void UIButton::draw(sf::RenderWindow* window) {
    if (hidden) { return; }
    sprite.setPosition(get_real_position());
    if (sprite.getTexture() != nullptr) {
        window->draw(sprite);
    }
    text.draw(window);
    draw_children(window);
}

void UIButton::register_button_presses(sf::RenderWindow* window) {
    for (auto button : UIButton::buttons) {
        if (button != nullptr) {
            if (button->get_sprite().getGlobalBounds().contains(window->mapPixelToCoords(sf::Mouse::getPosition(*window)))) {
                if (button->on_click != nullptr) {
                    button->on_click();
                }
            }
        }
    }
}