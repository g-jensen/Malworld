#include "../headers/Animation.hpp"

std::vector<Animation*> Animation::animations;

Animation::Animation(Drawable* drawable, size_t sprite_size) {
    this->drawable = drawable;
    this->sprite_size = sprite_size;
}

void Animation::update() {
    drawable->set_sprite(*sprite_vector[frame_index % sprite_vector.size()]);
}

void Animation::play(size_t animation_length) {
    this->animation_length = animation_length;
    this->frame_index = 0;
    update();
    m_is_playing = true;
}

void Animation::stop() {
    frame_index = 0;
    m_is_playing = false;
}

bool Animation::load_from_file(std::string path){
    texture.loadFromFile(path);
    sf::Vector2u size = texture.getSize();

    for (int i = 0; i < size.y / sprite_size; i++) {
        for (int k = 0; k < size.x / sprite_size; k++) {
            sf::Sprite* s = new sf::Sprite();
            s->setTexture(texture);
            s->setTextureRect({{k*sprite_size,i*sprite_size},{sprite_size,sprite_size}});
            s->setPosition({(float)(k*sprite_size),(float)(i*sprite_size)});
            sprite_vector.push_back(s);
        }
    }
};

bool Animation::is_playing() {
    return m_is_playing;
}

void Animation::iterate() {
    iteration_count++;
    if (!m_is_playing) {return;}
    if (do_repeat) {
        frame_index++;
        frame_index %= sprite_vector.size();
    }
    if (frame_index <= sprite_vector.size()) {
        if (iteration_count % (int)(animation_length / sprite_vector.size()) == 0) {
            frame_index++;
            update();
        }
    } else {
        stop();
    }
}

void Animation::free_sprite_vector() {
    for (auto p: sprite_vector) {
        delete p;
    }
}