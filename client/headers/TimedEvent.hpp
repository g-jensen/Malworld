#pragma once

#include <vector>
#include <iostream>

#include <SFML/System/Clock.hpp>

#include "Time.hpp"

class TimedEvent {
public:
    TimedEvent(sf::Time delay, void (*event)(void));
    sf::Time delay;
    sf::Time start_time;
    void (*event)(void) = nullptr;
    static void update_events();
    static std::vector<TimedEvent*> timed_events;
};