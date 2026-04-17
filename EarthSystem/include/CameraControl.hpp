#pragma once
#ifndef CAMERA_CONTROL_HPP
#define CAMERA_CONTROL_HPP

#include <raylib.h>

Camera3D camera;

struct Viewer
{
    Viewer()
    {
        camera.position = (Vector3) { 30.0f, 20.0f, 30.0f};     // Start from a distance that is exact fine to see Earth 
        camera.target = (Vector3) {0.0f, 0.0f, 0.0f};           // Focus at the centre
        camera.up = (Vector3) {0.0f, 1.0f, 0.0f};               // Upper direction of Y axis
        camera.fovy = 60.0f;                                    // FOV, exactly! 
        camera.projection = CAMERA_PERSPECTIVE;
    }
};

void Update()
{
    UpdateCamera(&camera, CAMERA_FREE);
}

void Begin()
{
    BeginMode3D(camera);
}

void End()
{
    EndMode3D();
}

#endif
