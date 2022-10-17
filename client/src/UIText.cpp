#include "../headers/UIText.hpp"

UIText::UIText() {
    ;
}

UIText::UIText(std::string text_string, sf::Vector2f position) {
    this->set_relative_position(position);
    this->font = &UIGlobals::font;
    this->font_size = UIGlobals::font_size;
    this->text_string = text_string;
    this->text = sf::Text(text_string,*font,font_size);
}

void UIText::draw(sf::RenderWindow* window) {
    if (hidden) { return; }
    text.setPosition(get_real_position());
    if (text.getFont() != nullptr) {
        window->draw(text);
    }
    draw_children(window);
}