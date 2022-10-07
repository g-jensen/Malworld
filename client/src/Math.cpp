#include "../headers/Math.hpp"

float Math::clamp(float value, float min, float max) {
    if (value < min) {return min;}
    if (value > max) {return max;}
    return value;
}

float Math::distance(sf::Vector2f v1, sf::Vector2f v2) {
    float dx = v1.x - v2.x;
    float dy = v1.y - v2.y;
    return sqrt((dx*dx) + (dy*dy));
}

bool Math::approximately_equal_to(float value, float target, float err) {
    return value > target-err && value < target+err;
}