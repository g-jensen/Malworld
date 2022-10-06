#pragma once

#include <SFML/System/Clock.hpp>

class Time {
public:
    static float cumulative_time;
    static sf::Clock delta_time;
};