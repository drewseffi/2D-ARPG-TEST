#include "rendering/CameraComponent.h"
#include "systems/RenderingSystem.h"
#include "core/raylib.h"

void RenderingSystem::Update(World& world, CameraComponent camera)
{
    BeginDrawing();
    ClearBackground(BLUE);
    BeginMode2D(camera.GetCamera());

    for (Entity ent : world.GetEntities())
    {
        if (world.HasSprite(ent))
        {
            DrawTextureEx(world.GetSprite(ent).texture, world.GetTransform(ent).position, 0.0f, world.GetSprite(ent).scale, WHITE);
        }
    }

    EndMode2D();
    EndDrawing();
}