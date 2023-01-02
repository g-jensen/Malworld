#pragma once

#include <SFML/System/Clock.hpp>

class Time {
public:
    static sf::Clock cumulative_time;
    static sf::Clock delta_time;
};