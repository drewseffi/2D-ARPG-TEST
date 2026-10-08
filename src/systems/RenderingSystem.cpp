#include "rendering/CameraComponent.h"
#include "systems/RenderingSystem.h"
#include "core/raylib.h"

void RenderingSystem::Update(World& world, CameraComponent camera, Map& map)
{
    BeginDrawing();
    ClearBackground(BLUE);
    BeginMode2D(camera.GetCamera());

    // --- Draw map ---
    for (int y = 0; y < map.GetHeight(); y++)
    {
        for (int x = 0; x < map.GetWidth(); x++)
        {
            Tile& tile = map.GetTile(x, y);

            Vector2 position =
            {
                x * 64.0f,
                y * 64.0f
            };

            DrawTextureEx(
                tile.texture,
                position,
                0.0f,
                tile.scale,
                WHITE
            );
        }
    }

    // --- Draw entities ---
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