#include "world/MapGenerator.h"
#include "core/raylib.h"

Map MapGenerator::Generate(int width, int height)
{
    Map map(width, height);
    GenerateRooms(map);

    return map;
}

void MapGenerator::GenerateRooms(Map& map)
{
    Texture2D floorTexture = LoadTexture("assets/textures/floor.png");
    Texture2D wallTexture = LoadTexture("assets/textures/wall.png");

    for (int i = 0; i < map.GetWidth(); i++)
    {
        for (int j = 0; j < map.GetHeight(); j++)
        {
            map.SetTile(i, j, {TileType::Floor, true, floorTexture, 2.0f});
        }
    }

    int posX = GetRandomValue(0, map.GetWidth());
    int posY = GetRandomValue(0, map.GetHeight());

    map.SetTile(posX, posY, {TileType::Wall, false, wallTexture, 2.0f});
}

void MapGenerator::GenerateCorridors(Map& map)
{

}