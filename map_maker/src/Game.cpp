#include "../headers/Game.hpp"

Game::Game() {
    window = nullptr;
}

void Game::init() {

    UIGlobals::font.loadFromFile("resources/Ubuntu-Regular.ttf");

    window = new sf::RenderWindow(sf::VideoMode(800, 600), "Malworld");
    sf::View v = window->getView();
    v.setCenter({0,0});
    window->setView(v);

    event = sf::Event();

    max_framerate = 60;
}

void Game::run() {

    sf::Texture texture;
    texture.loadFromFile("resources/button.png");
    sf::Sprite sb(texture);

    UIButton b(window->mapPixelToCoords({0,0}),{100,100},"PRESS ME");
    b.set_sprite(sb);
    b.text.set_text(UIText::fitTextToSize(b.text.get_text(),{100,100}));

    while (window->isOpen()) {
        window->setFramerateLimit(max_framerate);

        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window->close();
            }
            
            if (event.type == sf::Event::MouseButtonPressed) {
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    UIButton::register_button_presses(window);
                }
            }

        }

        window->clear(sf::Color::Black);

        // window->draw(...);
        b.draw(window);

        window->display();
    }
}

void Game::cleanup() {
    delete window;
}