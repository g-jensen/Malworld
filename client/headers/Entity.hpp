#pragma once

#include <SFML/System/Vector2.hpp>

#include "Collidable.hpp"
#include "Math.hpp"
#include "Globals.hpp"
#include "Animation.hpp"

class Entity: public Collidable {
public:
    static std::vector<Entity*> entities;
    Entity();

    virtual void update() = 0;
    virtual void load_animations() = 0;
    virtual void update_animations() = 0;

    // returns distance from nearest ground. -1 if no ground is found.
    float distance_from_ground();
    // returns distance of nearest wall in direction of velocity. -1 if no ground is found.
    float distance_from_wall();
    bool is_grounded();
    
    void update_transform();
    sf::Vector2f velocity;
    sf::Vector2f acceleration;
    sf::Vector2f size;
    Animation idle;
protected:
    bool grounded;
};