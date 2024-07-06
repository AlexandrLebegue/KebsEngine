#pragma once
#include <string>
#include <vector>

#include "layer.hpp"
class Tilemap {
public:
    int tileSize;
    int mapWidth;
    int mapHeight;
    std::vector<Layer> layers;

    Tilemap(int tileSize, int mapWidth, int mapHeight) : tileSize(tileSize), mapWidth(mapWidth), mapHeight(mapHeight) {}

    void loadTilemap(char * filepath);

};