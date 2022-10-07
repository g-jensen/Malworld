#pragma once

#include <math.h>

#include <SFML/System/Vector2.hpp>

class Math {
public:
    static float clamp(float value, float min, float max);
    static float distance(sf::Vector2f v1, sf::Vector2f v2);
};