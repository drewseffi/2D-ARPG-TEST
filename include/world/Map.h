#pragma once

#include <vector>

#include "world/Tile.h"

class Map
{
    public:
        Map(int width, int height);

        int GetWidth() const;
        int GetHeight() const;

        Tile& GetTile(int x, int y);

        void SetTile(int x, int y, Tile tile);

    private:
        int width;
        int height;

        std::vector<Tile> tiles;
};