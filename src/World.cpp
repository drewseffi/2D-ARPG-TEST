#include "ecs/World.h"
#include <iostream>

Entity World::CreateEntity()
{
    Entity entity = nextEntity++;
    entities.push_back(entity);
    std::cout << "Added entity: " << entity;
    return entity;
}

const std::vector<Entity>& World::GetEntities() const
{
    return entities;
}

void World::AddTransform(Entity entity, TransformComponent transform)
{
    transforms[entity] = transform;
}

void World::AddVelocity(Entity entity, VelocityComponent velocity)
{
    velocities[entity] = velocity;
}

void World::AddSprite(Entity entity, SpriteComponent sprite)
{
    sprites[entity] = sprite;
}

TransformComponent& World::GetTransform(Entity entity)
{
    return transforms.at(entity);
}

VelocityComponent& World::GetVelocity(Entity entity)
{
    return velocities.at(entity);
}

SpriteComponent& World::GetSprite(Entity entity)
{
    return sprites.at(entity);
}

bool World::HasTransform(Entity entity)
{
    return transforms.find(entity) != transforms.end();
}

bool World::HasVelocity(Entity entity)
{
    return velocities.find(entity) != velocities.end();
}

bool World::HasSprite(Entity entity)
{
    return sprites.find(entity) != sprites.end();
}