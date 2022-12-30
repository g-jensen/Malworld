#include "../headers/NPC.hpp"

NPC::NPC(std::string name, sf::Vector2f position, sf::Vector2f size) {
    this->name = name;
    this->position = position;
    this->size = size;
    setup_hitbox(position,size);
    load_animations();
}

void NPC::update() {
    update_animations();
}

void NPC::load_animations() {
    idle = Animation(this,64);
    idle.load_from_file("resources/duck/idle.png");
}

void NPC::update_animations() {
    idle.play(1);
}