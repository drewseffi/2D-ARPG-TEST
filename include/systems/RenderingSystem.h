#pragma once

#include "ecs/World.h"

#include "core/raylib.h"

class RenderingSystem
{
public:
    void Update(World& world);
};