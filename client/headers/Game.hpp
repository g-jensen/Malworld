#pragma once

#include <iostream>
#include <math.h>
#include <fstream>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>

#include "Globals.hpp"
#include "Player.hpp"
#include "Time.hpp"
#include "TimedEvent.hpp"
#include "Object.hpp"
#include "Keybinds.hpp"
#include "Animation.hpp"
#include "UIBackground.hpp"
#include "UIGlobals.hpp"
#include "UIButton.hpp"
#include "MapLoader.hpp"
#include "NPC.hpp"
#include "DialoguePromptNode.hpp"
#include "DialogueResponseNode.hpp"
#include "DialogueSystem.hpp"

class Game {
public:
    sf::RenderWindow* window;
    sf::Event event;
    int max_framerate;
    Game();
    static void test();
    void init();
    void run();
    void cleanup();
};