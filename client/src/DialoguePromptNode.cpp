#include "../headers/DialoguePromptNode.hpp"

DialoguePromptNode::DialoguePromptNode(std::string value) {
    this->value = value;
}

void DialoguePromptNode::free_node() {
    for (auto n : options) {
        if (n != nullptr) {
            n->free_node();
        }
    }
    delete this;
}