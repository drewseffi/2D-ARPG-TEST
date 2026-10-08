#pragma once

#include "world/Map.h"

class MapGenerator
{
    public:
        Map Generate(int width, int height);

    private:
        void GenerateRooms(Map& map);
        void GenerateCorridors(Map& map);
};