#include <stdio.h>

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
    float dx = cameraPosition.x, dy = cameraPosition.y, dz = cameraPosition.z, angle = cameraRotation;
    
    // Fowards/Backwards movement
    if (IsKeyDown(KEY_S)){
        dz += 1*frametime;
        setCameraPositionZ(dz);
    } else if (IsKeyDown(KEY_W)){
        dz -= 1*frametime;
        setCameraPositionZ(dz);
    }

    // Left/Right movement
    if (IsKeyDown(KEY_A)){
        dx += 1*frametime;
        setCameraPositionX(dx);
    } else if (IsKeyDown(KEY_D)){
        dx = cameraPosition.x - 1*frametime;
        setCameraPositionX(dx);
    }
    
    // Up/Down movement
    if (IsKeyDown(KEY_SPACE)){
        dy = cameraPosition.y - 1*frametime;
        setCameraPositionY(dy);

    } else if (IsKeyDown(KEY_LEFT_SHIFT)){
        dy = cameraPosition.y + 1*frametime;
        setCameraPositionY(dy);

    } 
    
    // Left/Right rotation
    if (IsKeyDown(KEY_RIGHT)){
        angle = cameraRotation +  2*frametime/4;
        setCameraRotation(angle);

    } else if (IsKeyDown(KEY_LEFT)){
        angle = cameraRotation - 2*frametime/4;
        setCameraRotation(angle);
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