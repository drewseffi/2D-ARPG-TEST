#pragma once

#include "ecs/World.h"

class InputSystem
{
    public:
        void Update(World& world, Entity player);
};