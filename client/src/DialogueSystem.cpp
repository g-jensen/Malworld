#include "../headers/DialogueSystem.hpp"

void DialogueSystem::set_prompt(DialoguePromptNode* prompt) {
    this->current_prompt = prompt;
}

std::string DialogueSystem::get_prompt() {
    return current_prompt != nullptr ? current_prompt->value : "";
}

// fix me
void DialogueSystem::fill_options() {
    options.clear();
    if (current_prompt == nullptr) { return; }
    for (auto o: current_prompt->options) {
        if (o == nullptr) { continue; }
        options.push_back(o->value);
    }
}

DialogueSystem::DialogueSystem(DialoguePromptNode* prompt) {
    set_prompt(prompt);
    if (prompt == nullptr) { return; }
    fill_options();
}

std::vector<std::string> DialogueSystem::get_options() {
    return options;
}

void DialogueSystem::choose_response(size_t index) {
    if (current_prompt == nullptr) { return; }
    current_response = current_prompt->options[index];
    if (current_response == nullptr) { return; }
    current_prompt = current_response->prompt;
    fill_options();
}

void DialogueSystem::print_system() {
    std::cout << get_prompt() << std::endl;
    for (auto o: get_options()) {
        std::cout << "> " << o << std::endl;
    }
}