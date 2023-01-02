#include "../headers/DialogueSystem.hpp"

void DialogueSystem::set_prompt(DialoguePromptNode* prompt) {
    this->current_prompt = prompt;
}

std::string DialogueSystem::get_prompt() {
    return current_prompt != nullptr ? current_prompt->value : "";
}

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

std::string DialogueSystem::get_options() {
    std::string output;
    for (auto o: options) {
        output += "> " + o + "\n";
    }
    return output;
}

void DialogueSystem::choose_response(size_t index) {
    if (current_prompt == nullptr) { return; }
    if (index >= current_prompt->options.size()) { return; }
    current_response = current_prompt->options[index];
    if (current_response == nullptr) { return; }
    current_prompt = current_response->prompt;
    fill_options();
}

std::string DialogueSystem::get_response(size_t index) {
    if (
        current_prompt == nullptr || 
        index >= current_prompt->options.size() || 
        current_prompt->options[index] == nullptr
    ) { return ""; }
    return current_prompt->options[index]->value;
}

void DialogueSystem::print_system() {
    std::cout << get_prompt() << std::endl << get_options() << std::endl;
}