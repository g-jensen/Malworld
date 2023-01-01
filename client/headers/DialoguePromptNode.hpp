#pragma once

#include <vector>

#include "DialogueNode.hpp"
#include "DialogueResponseNode.hpp"

class DialoguePromptNode: public DialogueNode {
public:
    DialoguePromptNode(std::string value);
    void free_node();
    std::vector<DialogueResponseNode*> options;
};