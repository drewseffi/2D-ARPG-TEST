#include "core/raylib.h"
#include "ecs/World.h"

#include "systems/InputSystem.h"
#include "systems/MovementSystem.h"
#include "systems/RenderingSystem.h"

int main()
{
    const int screenWidth = 800;
    const int screenHeight = 800;

    InitWindow(screenWidth, screenHeight, "2D-ARPG-TEST");
    InitAudioDevice();

    SetExitKey(KEY_NULL);
    SetTargetFPS(60);

    World world;

    Entity player = world.CreateEntity();
    Texture2D playerTexture = LoadTexture("assets/textures/player.png");

    world.AddTransform(player, TransformComponent{{400.0f, 400.0f}});
    world.AddVelocity(player, VelocityComponent{{0.0f, 0.0f}});
    world.AddSprite(player, SpriteComponent{playerTexture, 1.0f});

    InputSystem inputSystem;
    MovementSystem movementSystem;
    RenderingSystem renderingSystem;

    while (!WindowShouldClose())
    {
        float deltaTime = GetFrameTime();

        // --- Update game systems ---
        inputSystem.Update(world, player);
        movementSystem.Update(world, deltaTime);

        // --- Rendering ---
        renderingSystem.Update(world);
    }

    CloseAudioDevice();
    CloseWindow();

    return 0;
}