#pragma once

#include <unordered_map>
#include <vector>
#include <fstream>

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

#include "Drawable.hpp"

class Animation {
public:
    Animation(Drawable* drawable, size_t sprite_size);
    void play(size_t animation_length);
    void stop();
    bool do_repeat;
    void iterate();
    void update();
    bool is_playing();
    bool load_from_file(std::string path);
    void free_sprite_vector();

    static std::vector<Animation*> animations;
private:
    Drawable* drawable;
    sf::Texture texture;
    bool m_is_playing;
    size_t frame_index;
    size_t iteration_count;
    int sprite_size;
    size_t animation_length;
    std::vector<sf::Sprite*> sprite_vector;
};

