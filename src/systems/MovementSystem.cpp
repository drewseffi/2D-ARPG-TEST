#include "systems/MovementSystem.h"

#include <iostream>

void MovementSystem::Update(World& world, float deltaTime)
{
    for (Entity ent : world.GetEntities())
    {
        if (world.HasTransform(ent) && world.HasVelocity(ent))
        {
            auto& velocity = world.GetVelocity(ent);
            auto& transform = world.GetTransform(ent);

            transform.position.x += velocity.value.x * deltaTime;
            transform.position.y += velocity.value.y * deltaTime;

            std::cout << "Entity: " << ent << ", x: " << transform.position.x << ", y: " << transform.position.y << "\n";
        }
    }
}