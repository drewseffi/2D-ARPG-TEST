#pragma once

#include "core/raylib.h"

class CameraComponent
{
    public:
        CameraComponent();

        void Follow(Vector2 target);

        Camera2D& GetCamera();

    private:
        Camera2D camera;
};