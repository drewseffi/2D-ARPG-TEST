#pragma once

#include "core/raylib.h"

enum class TileType
{
    Floor,
    Wall
};

struct Tile
{
    TileType type;
    bool walkable;

    Texture2D texture;
    float scale;
};