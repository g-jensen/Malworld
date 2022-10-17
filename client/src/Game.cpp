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

void Game::test() {
    std::cout << "popop" << std::endl;
}

void Game::run() {
    sf::Texture texture;
    texture.loadFromFile("resources/zane.png");

    sf::Texture button_texture;
    button_texture.loadFromFile("resources/button.png");
    // std::vector<Object*> test;
    // for (int i = 0; i < 10000; i++) {
    //     test.push_back(new Object({0,0},{450,50}));
    // }
    
    sf::Sprite sb;
    sb.setTexture(button_texture);

    UIButton b(window->mapPixelToCoords({0,0}),{100,100},"PRESS ME");
    b.set_sprite(sb);
    b.text.set_relative_position({0,25});
    b.on_click = &Game::test;

    Player* player = new Player({-200,-200},{35,50});

    Object* floor = new Object({-300,100},{450,50});
    floor->init_sprite(texture);

    Object* floor2 = new Object({-600,50},{450,50});
    floor2->init_sprite(texture);

    Object* floor3 = new Object({-300,-100},{450,50});
    floor3->init_sprite(texture);

    Object* floor4 = new Object({130,50},{450,50});
    floor4->init_sprite(texture);

    sf::Font font;
    font.loadFromFile("resources/Ubuntu-Regular.ttf");
    sf::Text fps_display;
    fps_display.setFont(font);
    fps_display.setPosition({250,-200});
    int fps = 0;

    // Load keybinds
    std::ifstream f("config/keybinds.json");
    json data = json::parse(f);
    Keybinds::load_keybinds(data); 

    Time::delta_time.restart();
    while (window->isOpen()) {
        window->setFramerateLimit(max_framerate);

        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window->close();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
                player->position.y -= 100;
            }
            
            if (event.type == sf::Event::MouseButtonPressed) {
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    UIButton::register_button_presses(window);
                }
            }

        }

        if (sf::Keyboard::isKeyPressed(Keybinds::move_left)){
            player->velocity.x = -5;
        }
        if (sf::Keyboard::isKeyPressed(Keybinds::move_right)) {
            player->velocity.x = 5;
        }
        if (sf::Keyboard::isKeyPressed(Keybinds::jump) && player->is_grounded()) {
            player->velocity.y = -7.5;
        }
        
        for (Collidable* c : Collidable::collidables) {
            if (c != player && player->hit_box.intersects(c->hit_box)) {
                player->on_intersect(c);
            }
        }

        player->update();

        window->clear(sf::Color::Black);

        // window->draw(...);
        for (Drawable* d: Drawable::drawables) {
            d->draw(window);
        }
        window->draw(fps_display);
        b.draw(window);

        window->display();

        fps = 1 / Time::delta_time.getElapsedTime().asSeconds();
        fps_display.setString("FPS: " + std::to_string(fps));

        Time::cumulative_time += Time::delta_time.getElapsedTime().asSeconds();
        Time::delta_time.restart();
    }

    delete player;
    delete floor;
    delete floor2;
    delete floor3;
    delete floor4;
    // for (auto g: test) {
    //     delete g;
    // }
}

void Game::cleanup() {
    for (auto a: Animation::animations) {
        a->free_sprite_vector();
    }
    delete window;
}