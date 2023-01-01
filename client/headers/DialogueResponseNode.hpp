#pragma once

#include "DialogueNode.hpp"
#include "DialoguePromptNode.hpp"

class DialogueResponseNode: public DialogueNode {
public:
    DialogueResponseNode(std::string value);
    void free_node();
    DialoguePromptNode* prompt;
};