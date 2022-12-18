#pragma once

#include <vector>
#include <fstream>
#include <iostream>

#include "Object.hpp"

#include "../../nlohmann-json/single_include/nlohmann/json.hpp"
using json = nlohmann::json;

class MapLoader {
public:
    static std::vector<Object*> objects;
    static void loadMapFromFile(std::ifstream& file);
};