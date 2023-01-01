#include "../headers/DialogueResponseNode.hpp"

DialogueResponseNode::DialogueResponseNode(std::string value) {
    this->value = value;
    this->prompt = nullptr;
}

void DialogueResponseNode::free_node() {
    if (prompt != nullptr) {
        prompt->free_node();
    }
    delete this;
}