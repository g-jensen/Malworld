#include "../headers/Game.hpp"

#include <iostream>

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
    player->velocity = {1,15};
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

        player->velocity.y = floor->is_colliding(player) ? 0 : 15;

        window->clear(sf::Color::Black);

        // window.draw(...);
        window->draw(player->sprite);
        window->draw(floor->get_sprite());

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