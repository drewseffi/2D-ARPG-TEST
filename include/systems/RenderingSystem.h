#pragma once

#include "ecs/World.h"
#include "rendering/CameraComponent.h"
#include "world/Map.h"

#include "core/raylib.h"

class RenderingSystem
{
public:
    void Update(World& world, CameraComponent camera, Map& map);
};