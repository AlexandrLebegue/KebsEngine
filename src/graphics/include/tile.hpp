#pragma once

#include <string>
#include <vector>
#include "sprite.hpp"
class Tile {
public:
    std::string id;
    int x, y;

    Tile(const std::string& id, int x, int y) : id(id), x(x), y(y) {}
};