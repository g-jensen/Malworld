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

void UIText::set_string(std::string string) {
    this->text_string = string;
    this->text.setString(text_string);
}

std::string UIText::get_string() {
    return this->text_string;
}

void UIText::set_text(sf::Text text) {
    this->text = text;
}

sf::Text UIText::get_text() {
    return this->text;
}

sf::Text UIText::fitTextToSize(sf::Text text, sf::Vector2f size) {
    float scalar = 1;
    sf::FloatRect fr = text.getGlobalBounds();
    if (abs(size.x - fr.width) < abs(size.y - fr.height)) {
        scalar = size.x / fr.width;
    } else {
        scalar = size.y / fr.height;
    }
    text.scale(scalar,scalar);
    return text;
}