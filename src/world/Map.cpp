#include "world/Map.h"

Map::Map(int width, int height)
{
    this->width = width;
    this->height = height;

    tiles.resize(width * height);
}

int Map::GetWidth() const
{
    return width;
}

int Map::GetHeight() const
{
    return height;
}

Tile& Map::GetTile(int x, int y)
{
    return tiles[y * width + x];
}

void Map::SetTile(int x, int y, Tile tile)
{
    tiles[y * width + x] = tile;
}