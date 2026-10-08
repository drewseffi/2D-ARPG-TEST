#include "systems/InputSystem.h"

#include <iostream>

void InputSystem::Update(World& world, Entity player)
{
    auto& intent = world.GetVelocity(player);

    intent.value = {0.0f, 0.0f};

    if (IsKeyDown(KEY_W))
    {
        intent.value.y -= 100.0f;
        std::cout << "W";
    }

    if (IsKeyDown(KEY_S))
    {
        intent.value.y += 100.0f;
        std::cout << "S";
    }

    if (IsKeyDown(KEY_A))
    {
        intent.value.x -= 100.0f;
        std::cout << "A";
    }

    if (IsKeyDown(KEY_D))
    {
        intent.value.x += 100.0f;
        std::cout << "D";
    }
}