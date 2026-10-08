#include "systems/RenderingSystem.h"
#include "core/raylib.h"

void RenderingSystem::Update(World& world)
{
    BeginDrawing();
    ClearBackground(BLUE);

    for (Entity ent : world.GetEntities())
    {
        if (world.HasSprite(ent))
        {
            DrawTextureEx(world.GetSprite(ent).texture, world.GetTransform(ent).position, 0.0f, world.GetSprite(ent).scale, WHITE);
        }
    }

    EndDrawing();
}