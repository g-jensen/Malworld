#pragma once

#define MAX_ENT_SPEED 128
#define MIN_Y_POS -1024

#include <SFML/System/Time.hpp>

#include "DialogueSystem.hpp"
#include "UIText.hpp"
#include "TimedEvent.hpp"

// #define EXTERN_GLOBALS \
//     extern DialogueSystem* dialogue_system;\
//     extern UIText npc_prompt;\
//     extern UIText npc_options;\
//     extern UIText player_text;\
//     extern sf::Time npc_talk_delay;\
//     extern TimedEvent* clear_player_text;\

#ifndef _MW_GLOBALS_

// Dialogue System Singleton
DialogueSystem* dialogue_system = nullptr;

// Text that shows the dialogue prompt from an NPC
UIText npc_prompt;

// Text that shows the possible dialogue options for a specific prompt
UIText npc_options;

// Text that shows what the player is saying
UIText player_text;

// Delay to be able to talk to an NPC after finishing dialogue with an NPC
sf::Time npc_talk_delay;

// 
TimedEvent* clear_player_text = nullptr;

#define _MW_GLOBALS_
#endif