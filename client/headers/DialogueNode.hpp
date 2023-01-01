#pragma once

#include <vector>
#include <string>

class DialogueNode {
public:
    virtual void free_node() = 0;
    std::string value;
};

class DialoguePromptNode;
class DialogueResponseNode;