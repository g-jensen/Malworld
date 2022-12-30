#pragma once

#include <string>

#include "Entity.hpp"

class NPC : public Entity {
public:
    NPC(std::string name, sf::Vector2f position, sf::Vector2f size);
    
    void update();
    void load_animations();
    void update_animations();


private:
    std::string name;
};