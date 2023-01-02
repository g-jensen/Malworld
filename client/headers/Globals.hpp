#pragma once

#define MAX_ENT_SPEED 128
#define MIN_Y_POS -1024

#include "DialogueSystem.hpp"
#include "UIText.hpp"

class Globals {
public:
    static DialogueSystem* dialogue_system;
    static UIText npc_prompt;
    static UIText npc_options;
    static UIText textbox;
};