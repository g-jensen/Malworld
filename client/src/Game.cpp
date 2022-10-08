#include "../headers/Game.hpp"

#include <iostream>

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>

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

    // std::vector<Object*> test;
    // for (int i = 0; i < 10000; i++) {
    //     test.push_back(new Object({0,0},{450,50}));
    // }

    Player* player = new Player({-200,-150},{50,50});
    player->velocity = {1,0};
    player->init_sprite(texture);

    Object* floor = new Object({-300,100},{450,50});
    floor->init_sprite(texture);

    sf::Font font;
    font.loadFromFile("Ubuntu-Regular.ttf");
    sf::Text fps_display;
    fps_display.setFont(font);
    fps_display.setPosition({300,-200});
    int fps = 0;

    // test keybinds
    std::ifstream f("test.json");
    json data = json::parse(f);
    Keybinds::load_keybinds(data);
    

    Time::delta_time.restart();
    while (window->isOpen()) {
        window->setFramerateLimit(max_framerate);

        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window->close();
            }
        }

        if (sf::Keyboard::isKeyPressed(Keybinds::move_left)){
            player->velocity.x = -5;
        }
        if (sf::Keyboard::isKeyPressed(Keybinds::move_right)) {
            player->velocity.x = 5;
        }
        
        player->update();

        for (Collidable* c : Collidable::collidables) {
            if (c != player && player->hit_box.intersects(c->hit_box)) {
                player->on_intersect(c);
            }
        }
        
        window->clear(sf::Color::Black);

        // window->draw(...);
        for (Drawable* d: Drawable::drawables) {
            d->draw(window);
        }
        window->draw(fps_display);

        window->display();

        fps = 1 / Time::delta_time.getElapsedTime().asSeconds();
        fps_display.setString(std::to_string(fps));

        Time::cumulative_time += Time::delta_time.getElapsedTime().asSeconds();
        Time::delta_time.restart();
    }

    delete player;
    delete floor;
    // for (auto g: test) {
    //     delete g;
    // }
}

void Game::cleanup() {
    delete window;
}