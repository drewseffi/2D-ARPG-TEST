#pragma once

#include <unordered_map>
#include <vector>

#include "Entity.h"
#include "components/TransformComponent.h"
#include "components/VelocityComponent.h"
#include "components/SpriteComponent.h"

class World
{
    public:
        Entity CreateEntity();

        const std::vector<Entity>& GetEntities() const;

        void AddTransform(Entity entity, TransformComponent transform);
        void AddVelocity(Entity entity, VelocityComponent velocity);
        void AddSprite(Entity entity, SpriteComponent sprite);

        TransformComponent& GetTransform(Entity entity);
        VelocityComponent& GetVelocity(Entity entity);
        SpriteComponent& GetSprite(Entity entity);

        bool HasTransform(Entity entity);
        bool HasVelocity(Entity entity);
        bool HasSprite(Entity entity);

    private:
        Entity nextEntity = 0;
        std::vector<Entity> entities;

        std::unordered_map<Entity, TransformComponent> transforms;
        std::unordered_map<Entity, VelocityComponent> velocities;
        std::unordered_map<Entity, SpriteComponent> sprites;
};