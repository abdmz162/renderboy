#include <stdio.h>
#include <math.h>

#include "raylib.h"
#include "drawing.h"
#include "movement.h"
#include "state.h"
#include "consts.h"


void configureWindow() {
    SetTargetFPS(FPS);
    resetPosition();
    InitWindow(WIDTH, HEIGHT, "Peak 3D Renderer");
}

void handleInput(float frametime) {


    float dx = cameraPosition.x, dy = cameraPosition.y, dz = cameraPosition.z;
    float yaw_angle = cameraRotation.yaw, pitch_angle = cameraRotation.pitch, roll_angle = cameraRotation.roll;

    // forward movement
    float fx, fy, fz;

    // strafing
    float rx; // right x-component
    float rz; // right y-component

    fx = sin(yaw_angle)*cos(pitch_angle);
    fy = sin(pitch_angle);
    fz = cos(yaw_angle)*cos(pitch_angle);
    rx = cos(yaw_angle);
    rz = -sin(yaw_angle);

    float speed = SPEED * frametime;
    
    // Fowards/Backwards movement
    if (IsKeyDown(KEY_W)){
        dx -= fx * speed;
        dy -= fy * speed;
        dz -= fz * speed;
    } else if (IsKeyDown(KEY_S)){
        dx += fx * speed;
        dy += fy * speed;
        dz += fz * speed;
    }

    

    // Left/Right movement
    if (IsKeyDown(KEY_A)){
        dx += rx * speed;
        dz += rz * speed;
        setCameraPositionX(dx);
    } else if (IsKeyDown(KEY_D)){
        dx -= rx * speed;
        dz -= rz * speed;
        setCameraPositionX(dx);
    }
    
    // Up/Down movement
    if (IsKeyDown(KEY_SPACE)){
        dy -= 1*speed;
        setCameraPositionY(dy);

    } else if (IsKeyDown(KEY_LEFT_SHIFT)){
        dy += 1*speed;
        setCameraPositionY(dy);

    }

    Vec3 newPos = {
        dx, dy, dz
    };
    setCameraPosition(newPos);
    
    // Left/Right rotation
    if (IsKeyDown(KEY_RIGHT)){
        yaw_angle +=  2*PI*speed/4;
        setCameraRotationYaw(yaw_angle);

    } else if (IsKeyDown(KEY_LEFT)){
        yaw_angle -= 2*PI*speed/4;
        setCameraRotationYaw(yaw_angle);
    }

    // Up/Down rotation
    if (IsKeyDown(KEY_UP)){
        pitch_angle +=  2*PI*speed/4;
        setCameraRotationPitch(pitch_angle);

    } else if (IsKeyDown(KEY_DOWN)){
        pitch_angle -= 2*PI*speed/4;
        setCameraRotationPitch(pitch_angle);
    }
}

void mainLoop() {
    float frametime;
    
    while (!WindowShouldClose()) {
        BeginDrawing();
            frame(cameraPosition, cameraRotation);
            add_ui(cameraPosition, cameraRotation);
        EndDrawing();
        
        frametime = GetFrameTime();
        handleInput(frametime);
    }

    CloseWindow();
}

int main() {

    configureWindow();
    mainLoop();

    return 0;
}