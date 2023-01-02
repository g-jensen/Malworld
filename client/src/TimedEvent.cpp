#include "../headers/TimedEvent.hpp"

std::vector<TimedEvent*> TimedEvent::timed_events;

TimedEvent::TimedEvent(sf::Time delay, void (*event)(void)) {
    this->event = event;
    this->delay = delay;
    this->start_time = Time::cumulative_time.getElapsedTime();
    timed_events.push_back(this);
}

void TimedEvent::update_events() {
    for (auto& e : timed_events) {
        if (e == nullptr) { continue; }
        if (Time::cumulative_time.getElapsedTime() - e->start_time >= e->delay) {
            e->event();
            delete e;
            e = nullptr;
        }
    }
}