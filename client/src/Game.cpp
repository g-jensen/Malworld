#include "../headers/Game.hpp"

Game::Game() {
    window = nullptr;
    Globals::dialogue_system = nullptr;
}

void Game::init() {

    UIGlobals::font.loadFromFile("resources/Ubuntu-Regular.ttf");
    Drawable::default_texture.loadFromFile("resources/zane.png");

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

    sf::Texture button_texture;
    button_texture.loadFromFile("resources/button.png");
    
    sf::Sprite sb;
    sb.setTexture(button_texture);

    UIButton b(window->mapPixelToCoords({0,0}),{100,100},"PRESS ME");
    b.set_sprite(sb);
    b.text.set_text(UIText::fitTextToSize(b.text.get_text(),{100,100}));
    b.on_click = &Game::test;

    Player* player = new Player({-200,-200},{35,50});

    NPC* npc = new NPC("duck",{100,52},{43,48});
    npc->do_collision = false;

    DialoguePromptNode* root = new DialoguePromptNode("Quack! I'm a duck!");
    root->options.push_back(new DialogueResponseNode("I can see that"));
    root->options.push_back(new DialogueResponseNode("Me too"));
    root->options.push_back(new DialogueResponseNode("I love Werthers"));
    root->options[1]->prompt = new DialoguePromptNode("No you're not!");
    root->options[1]->prompt->options.push_back(new DialogueResponseNode("Poop"));
    root->options[1]->prompt->options.push_back(new DialogueResponseNode("Let's Go!"));

    std::ifstream file("resources/maps/output.json");
    MapLoader::loadMapFromFile(file);

    int fps = 0;
    UIText fps_display("FPS: " + std::to_string(fps),window->mapPixelToCoords({10,100}));

    Globals::npc_prompt = UIText("",window->mapPixelToCoords({400,100}));
    Globals::npc_options = UIText("",window->mapPixelToCoords({400,150}));
    Globals::textbox = UIText("",window->mapPixelToCoords({0,0}));

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

            if (event.type == sf::Event::KeyPressed) {
                if (Globals::dialogue_system != nullptr) {
                    for (size_t i = 1; i < Keybinds::numbers.size(); i++) {
                        if (sf::Keyboard::isKeyPressed(Keybinds::numbers[i])) {
                            Globals::textbox.set_string(Globals::dialogue_system->get_response(i-1));
                            Globals::dialogue_system->choose_response(i-1);
                            Globals::npc_prompt.set_string(Globals::dialogue_system->get_prompt());
                            Globals::npc_options.set_string(Globals::dialogue_system->get_options());
                            if (Globals::dialogue_system->get_options() == "") {
                                TimedEvent* e = new TimedEvent(sf::seconds(3),[](){Globals::textbox.set_string("");});
                            }
                            if (Globals::dialogue_system->get_prompt() == "") {
                                delete Globals::dialogue_system;
                                Globals::dialogue_system = nullptr;
                            }
                            break;
                        }
                    }
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                    delete Globals::dialogue_system;
                    Globals::dialogue_system = nullptr;
                    Globals::npc_prompt.set_string("");
                    Globals::npc_options.set_string("");
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

        if (player->hit_box.intersects(npc->hit_box)) {
            if (Globals::dialogue_system == nullptr) {
                Globals::dialogue_system = new DialogueSystem(root);
                Globals::npc_prompt.set_string(Globals::dialogue_system->get_prompt());
                Globals::npc_options.set_string(Globals::dialogue_system->get_options());
            }
        }
        Globals::textbox.set_relative_position(player->position - sf::Vector2f{0, Globals::textbox.get_text().getLocalBounds().height + 20});

        for (Entity* e : Entity::entities) {
            if (e != nullptr) {
                e->update();
            }
        }

        window->clear(sf::Color::Black);

        // window->draw(...);
        for (Drawable* d: Drawable::drawables) {
            d->draw(window);
        }
        fps_display.draw(window);
        Globals::npc_prompt.draw(window);
        Globals::npc_options.draw(window);
        Globals::textbox.draw(window);
        b.draw(window);

        window->display();

        fps = 1 / Time::delta_time.getElapsedTime().asSeconds();
        fps_display.set_string("FPS: " + std::to_string(fps));

        //Time::cumulative_time += Time::delta_time.getElapsedTime().asSeconds();
        Time::delta_time.restart();
        TimedEvent::update_events();
    }

    delete player;
    delete npc;
    delete Globals::dialogue_system;
    
    root->free_node(); 

    for (auto o: MapLoader::objects) {
        delete o;
    }
    for (auto e: TimedEvent::timed_events) {
        delete e;
    }
}

void Game::cleanup() {
    for (auto a: Animation::animations) {
        a->free_sprite_vector();
    }
    delete window;
}