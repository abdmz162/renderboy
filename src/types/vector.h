#pragma once

typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

typedef struct Vec2 {
    float x;
    float y;
} Vec2;

typedef struct Rotation {
    float roll; // phi
    float pitch; // theta
    float yaw; // psi
} Rotation; // Switch to quaternion later