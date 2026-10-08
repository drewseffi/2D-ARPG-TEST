#include "rendering/CameraComponent.h"

CameraComponent::CameraComponent()
{
    camera.offset = {GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f};
    camera.target = {GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f};
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;
}

void CameraComponent::Follow(Vector2 target)
{
    camera.target = target;
}

Camera2D& CameraComponent::GetCamera()
{
    return camera;
}