#pragma once

#include <SFML/System/Vector2.hpp>

class Transform {
public:
    void update_transform();
    sf::Vector2f position;
    float rotation;
protected:
};