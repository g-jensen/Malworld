#include "../headers/Game.hpp"

#include <iostream>
#include <SFML/Graphics/RectangleShape.hpp>

Game::Game() {
    window = nullptr;
}

void Game::init() {
    window = new sf::RenderWindow(sf::VideoMode(800, 600), "Malworld");
    sf::View v = window->getView();
    v.setCenter({0,0});
    window->setView(v);

    event = sf::Event();

    max_framerate = 60;
}

void Game::run() {

    sf::Texture texture;
    texture.loadFromFile("zane.png");

    Player* player = new Player({-200,-150},{50,50});
    player->velocity = {1,0};
    player->init_sprite(texture);

    Object* floor = new Object({-300,100},{450,50});
    floor->init_sprite(texture);

    Time::delta_time.restart();
    while (window->isOpen()) {
        window->setFramerateLimit(max_framerate);

        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window->close();
            }
        }

        player->update();

        for (Collidable* c : Collidable::collidables) {
            if (c != player && player->hit_box.intersects(c->hit_box)) {
                player->on_intersect(c);
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            player->velocity.x = -5;
            player->acceleration.x = 0.1;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            player->velocity.x = 5;
            player->acceleration.x = -0.1;
        }

        window->clear(sf::Color::Black);

        // window.draw(...);
        for (Drawable* d: Drawable::drawables) {
            d->draw(window);
        }

        window->display();

        Time::cumulative_time += Time::delta_time.getElapsedTime().asSeconds();
        Time::delta_time.restart();
    }

    delete player;
    delete floor;
}

void Game::cleanup() {
    delete window;
}