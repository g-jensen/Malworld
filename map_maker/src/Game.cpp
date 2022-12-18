#include "../headers/Game.hpp"

sf::RenderWindow* Game::window = nullptr;
sf::Event Game::event;
int Game::max_framerate;
EditMode Game::edit_mode;
sf::RectangleShape* Game::selected_rect = nullptr;
std::vector<sf::RectangleShape*> Game::rects;

void Game::init() {

    UIGlobals::font.loadFromFile("resources/native/Ubuntu-Regular.ttf");

    window = new sf::RenderWindow(sf::VideoMode(800, 600), "Malworld | Map Maker");
    sf::View v = window->getView();
    v.setCenter({0,0});
    window->setView(v);

    event = sf::Event();

    max_framerate = 60;
}

void Game::set_selected_rect(sf::RectangleShape* rect) {
    if (selected_rect != nullptr) {
        selected_rect->setOutlineThickness(0);
    }
    selected_rect = rect;
    if (selected_rect != nullptr) {
        selected_rect->setOutlineColor(sf::Color::Green);
        selected_rect->setOutlineThickness(3);
    }
}

std::string Game::serialize_game(std::vector<sf::RectangleShape*> rects) {
    std::string output = "{\n    \"objects\": [\n";
    
    for (size_t i = 0; i < rects.size(); i++) {
        sf::RectangleShape* r = rects[i];
        if (r != nullptr) {
            output += "        {\n";
            output += "            \"position\": [" + std::to_string((int)r->getPosition().x) + "," + std::to_string((int)r->getPosition().y) + "],\n";
            output += "            \"size\": [" + std::to_string((int)r->getSize().x) + "," + std::to_string((int)r->getSize().y) + "],\n";
            output += "            \"texture_id\": 0\n";
            output += "        }";
            if (i != rects.size()-1) {
                output += ",";
            }
            output += "\n";
        }
    }

    output += "    ]\n}";
    return output;
}

void Game::run() {

    sf::Texture texture;
    texture.loadFromFile("resources/native/button.png");
    sf::Sprite sb(texture);

    sf::Vector2f saved_window_pos = window->getView().getCenter();
    sf::Vector2i saved_mouse_pos = sf::Mouse::getPosition(*window);
    bool is_dragging = false;
    bool is_creating_box = false;
    bool is_selecting = false;

    sf::RectangleShape* current_rect = nullptr;

    UIText mouse_label(
        "(" + std::to_string((int)window->mapPixelToCoords(sf::Mouse::getPosition(*window)).x) + ", " + std::to_string((int)window->mapPixelToCoords(sf::Mouse::getPosition(*window)).y) + ")",
        window->mapPixelToCoords(sf::Mouse::getPosition(*window)) + sf::Vector2f{10,0}
    );

    edit_mode = EditMode::Transform;

    // move around boxes
    UIButton transform_button((sf::Vector2f)window->mapPixelToCoords({0,0}),{50,50},"Transform");
    transform_button.set_sprite(sb);
    transform_button.on_click = []() { edit_mode = EditMode::Transform; set_selected_rect(nullptr); };

    // make boxes
    UIButton box_button((sf::Vector2f)window->mapPixelToCoords({0,50}),{50,50},"Box");
    box_button.set_sprite(sb);
    box_button.on_click = []() { edit_mode = EditMode::Box; set_selected_rect(nullptr); };

    // delete stuff
    UIButton delete_button((sf::Vector2f)window->mapPixelToCoords({0,100}),{50,50},"Delete");
    delete_button.set_sprite(sb);
    delete_button.on_click = []() { edit_mode = EditMode::Delete; set_selected_rect(nullptr); };

    UIButton save_button((sf::Vector2f)window->mapPixelToCoords({0,150}),{50,50},"Save");
    save_button.set_sprite(sb);
    save_button.on_click = []() { 
        std::string s = serialize_game(rects); 
        std::ofstream out("output/output.json");
        out << s;
        out.close();
    };

    UIText selected_text("Selected:\n(x,y)=(0,0)\n(l,w)=(0,0)",(sf::Vector2f)window->mapPixelToCoords({0,200}));

    sf::RectangleShape x_axis({800,2});
    x_axis.setPosition({-400,0});
    sf::RectangleShape y_axis({2,600});
    y_axis.setPosition({0,-300});

    while (window->isOpen()) {
        window->setFramerateLimit(max_framerate);

        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window->close();
            }
            
            if (event.type == sf::Event::KeyPressed) {
                float move_sensitivity = 1.0f;
                if (event.key.code == sf::Keyboard::W) {
                    if (selected_rect != nullptr) {
                        selected_rect->move({0,-move_sensitivity});
                    }
                }
                if (event.key.code == sf::Keyboard::A) {
                    if (selected_rect != nullptr) {
                        selected_rect->move({-move_sensitivity,0});
                    }
                }
                if (event.key.code == sf::Keyboard::S) {
                    if (selected_rect != nullptr) {
                        selected_rect->move({0,move_sensitivity});
                    }
                }
                if (event.key.code == sf::Keyboard::D) {
                    if (selected_rect != nullptr) {
                        selected_rect->move({move_sensitivity,0});
                    }
                }

                float resize_sensitivity = 1.0f;
                if (event.key.code == sf::Keyboard::Up) {
                    if (selected_rect != nullptr && selected_rect->getSize().y > resize_sensitivity) {
                        selected_rect->setSize(selected_rect->getSize() + sf::Vector2f{0,-resize_sensitivity});
                    }
                }
                if (event.key.code == sf::Keyboard::Left && selected_rect->getSize().x > resize_sensitivity) {
                    if (selected_rect != nullptr) {
                        selected_rect->setSize(selected_rect->getSize() + sf::Vector2f{-resize_sensitivity,0});
                    }
                }
                if (event.key.code == sf::Keyboard::Down) {
                    if (selected_rect != nullptr) {
                        selected_rect->setSize(selected_rect->getSize() + sf::Vector2f{0,resize_sensitivity});
                    }
                }
                if (event.key.code == sf::Keyboard::Right) {
                    if (selected_rect != nullptr) {
                        selected_rect->setSize(selected_rect->getSize() + sf::Vector2f{resize_sensitivity,0});
                    }
                }
            }
            
            if (event.type == sf::Event::MouseButtonPressed) {
                saved_mouse_pos = sf::Mouse::getPosition(*window);
                saved_window_pos = window->getView().getCenter();
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    bool was_box_mode = (edit_mode == EditMode::Box);
                    UIButton::register_button_presses(window);
                    if (edit_mode == EditMode::Box) {
                        if (was_box_mode) {
                            is_creating_box = true;
                            current_rect = new sf::RectangleShape();
                            rects.push_back(current_rect);
                        }
                    }
                    if (edit_mode == EditMode::Transform) {
                        bool found = false;
                        for (int i = rects.size()-1; i >= 0; i--) {
                            auto r = rects[i];
                            if (r->getGlobalBounds().contains(window->mapPixelToCoords(sf::Mouse::getPosition(*window)))) {
                                set_selected_rect(r);
                                found = true;
                                break;
                            }
                        }
                        if (!found) {
                            is_dragging = true;
                            set_selected_rect(nullptr);
                        }
                    }
                    if (edit_mode == EditMode::Delete) {
                        bool found = false;
                        for (int i = rects.size()-1; i >= 0; i--) {
                            auto r = rects[i];
                            if (r->getGlobalBounds().contains(window->mapPixelToCoords(sf::Mouse::getPosition(*window)))) {
                                set_selected_rect(nullptr);
                                rects.erase(rects.begin()+i);
                                found = true;
                                break;
                            }
                        }
                        if (!found) {
                            is_dragging = true;
                            set_selected_rect(nullptr);
                        }
                    }
                }
            }
            if (event.type == sf::Event::MouseButtonReleased) {
                is_dragging = false;
                is_creating_box = false;
                is_selecting = false;
            }

            if (event.type == sf::Event::MouseMoved) {
                if (is_dragging) {
                    sf::View view = window->getView();
                    view.setCenter(saved_window_pos - (sf::Vector2f)(sf::Mouse::getPosition(*window) - saved_mouse_pos));
                    window->setView(view);

                    transform_button.set_relative_position((sf::Vector2f)window->mapPixelToCoords({0,0}));
                    box_button.set_relative_position((sf::Vector2f)window->mapPixelToCoords({0,50}));
                    delete_button.set_relative_position((sf::Vector2f)window->mapPixelToCoords({0,100}));
                    save_button.set_relative_position((sf::Vector2f)window->mapPixelToCoords({0,150}));
                    selected_text.set_relative_position((sf::Vector2f)window->mapPixelToCoords({0,200}));
                }

                if (is_creating_box) {
                    if (current_rect != nullptr) {
                        sf::Vector2f pos = window->mapPixelToCoords(saved_mouse_pos);
                        sf::Vector2f size = (sf::Vector2f)(sf::Mouse::getPosition(*window) - saved_mouse_pos);
                        
                        if (size.x < 0) { pos.x += size.x; size.x = -size.x; }
                        if (size.y < 0) { pos.y += size.y; size.y = -size.y; }
                        
                        current_rect->setPosition(pos);
                        current_rect->setSize(size);
                    }
                }

                mouse_label.set_relative_position(window->mapPixelToCoords(sf::Mouse::getPosition(*window)) + sf::Vector2f{10,0});
                mouse_label.set_string("(" + std::to_string((int)window->mapPixelToCoords(sf::Mouse::getPosition(*window)).x) + ", " + std::to_string((int)window->mapPixelToCoords(sf::Mouse::getPosition(*window)).y) + ")");
            }

            if (selected_rect != nullptr) {
                selected_text.set_string(
                    "Selected:\n(x,y)=(" + std::to_string((int)selected_rect->getPosition().x) + "," + std::to_string((int)selected_rect->getPosition().y) 
                    + ")\n(l,w)=(" + std::to_string((int)selected_rect->getSize().x) + "," + std::to_string((int)selected_rect->getSize().y) + ")"
                );
            } else {
                selected_text.set_string("Selected:\n(x,y)=(0,0)\n(l,w)=(0,0)");
            }

        }

        x_axis.setPosition({window->getView().getCenter().x-400,0});
        y_axis.setPosition({0,window->getView().getCenter().y-300});

        window->clear(sf::Color::Black);

        // window->draw(...);
        window->draw(x_axis);
        window->draw(y_axis);
        for (auto r: rects) {
            if (r != nullptr) {
                window->draw(*r);
            }
        }

        mouse_label.draw(window);
        transform_button.draw(window);
        box_button.draw(window);
        delete_button.draw(window);
        save_button.draw(window);
        selected_text.draw(window);

        window->display();
    }
    for (auto r: rects) {
        if (r != nullptr) {
            delete r;
        }
    }
}

void Game::cleanup() {
    delete window;
}