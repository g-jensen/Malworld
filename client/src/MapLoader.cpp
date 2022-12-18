#include "../headers/MapLoader.hpp"

std::vector<Object*> MapLoader::objects;

void MapLoader::loadMapFromFile(std::ifstream& file) {
    objects.clear();
    
    json data = json::parse(file);

    for (size_t i = 0; i < data["objects"].size(); i++) {
        objects.push_back(new Object(
            {data["objects"][i]["position"][0],data["objects"][i]["position"][1]},
            {data["objects"][i]["size"][0],data["objects"][i]["size"][1]}
        ));
    }
}