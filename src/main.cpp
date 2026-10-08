#include "core/raylib.h"
#include "ecs/World.h"

#include "systems/InputSystem.h"
#include "systems/MovementSystem.h"
#include "systems/RenderingSystem.h"

#include "world/Map.h"
#include "world/Tile.h"
#include "world/MapGenerator.h"

#include "rendering/CameraComponent.h"

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

    MapGenerator mapGenerator;

    CameraComponent camera;

    // --- Generate map ---
    Map map = mapGenerator.Generate(4, 4);

    while (!WindowShouldClose())
    {
        float deltaTime = GetFrameTime();

        // --- Update game systems ---
        inputSystem.Update(world, player);
        movementSystem.Update(world, deltaTime);
        Vector2 playerPosition = world.GetTransform(player).position;

        // --- Rendering ---
        camera.Follow(playerPosition);
        renderingSystem.Update(world, camera, map);
    }

    CloseAudioDevice();
    CloseWindow();

    return 0;
}