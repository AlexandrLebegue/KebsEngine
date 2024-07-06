#pragma once
#include <string>
#include <vector>

#include "tilemap.hpp"
#include <nlohmann/json.hpp>
#include <fstream>

void Tilemap::loadTilemap(char * filename)
{
    using json = nlohmann::json;

    std::ifstream file(filename);
    json jsonFile;
    file >> jsonFile;

    tileSize = jsonFile["tileSize"];
    mapWidth = jsonFile["mapWidth"];
    mapHeight= jsonFile["mapHeight"];

    for (const auto& layer : jsonFile["layers"]) {
        Layer newLayer(layer["name"], layer["collider"]);
        for (const auto& tile : layer["tiles"]) {
            newLayer.tiles.emplace_back(tile["id"], tile["x"], tile["y"]);
        }
        layers.push_back(newLayer);
    }

}
