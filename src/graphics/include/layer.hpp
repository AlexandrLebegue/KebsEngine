#pragma once

#include <string>
#include <vector>

#include "tile.hpp"
class Layer {
public:
    std::string name;
    std::vector<Tile> tiles;
    bool collider;

    Layer(const std::string& name, bool collider) : name(name), collider(collider) {}
};