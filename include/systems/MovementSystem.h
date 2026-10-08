#pragma once

#include "ecs/World.h"

class MovementSystem
{
public:
    void Update(World& world, float deltaTime);
};