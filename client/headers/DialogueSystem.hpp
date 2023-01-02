#pragma once

#include <vector>
#include <string>
#include <iostream>

#include "DialoguePromptNode.hpp"
#include "DialogueResponseNode.hpp"

class DialogueSystem {
public:
    DialogueSystem(DialoguePromptNode* prompt);
    void set_prompt(DialoguePromptNode* prompt);
    std::string get_prompt();
    std::string get_options();
    void choose_response(size_t index);
    std::string get_response(size_t index);
    void print_system();
private:
    void fill_options();
    DialoguePromptNode* current_prompt;
    DialogueResponseNode* current_response;
    std::vector<std::string> options;
};