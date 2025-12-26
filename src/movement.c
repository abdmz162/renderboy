#include "movement.h"
#include "state.h"

void resetPosition() {
    cameraPosition = globalPosition;
    cameraRotation = globalRotation;
}

// Global Position
void setGlobalPosition(Vec3 position) {
    globalPosition = position;
}

void setGlobalPositionX(float x) {
    globalPosition.x = x;
}

void setGlobalPositionY(float y) {
    globalPosition.y = y;
}

void setGlobalPositionZ(float z) {
    globalPosition.z = z;
}


// Camera Position
void setCameraPosition(Vec3 position) {
    cameraPosition = position;
}

void setCameraPositionX(float x) {
    cameraPosition.x = x;
}

void setCameraPositionY(float y) {
    cameraPosition.y = y;
}

void setCameraPositionZ(float z) {
    cameraPosition.z = z;
}


// Global Rotation
void setGlobalRotation(Rotation rotation) {
    globalRotation = rotation;
}

void setGlobalRotationRoll(float roll) {
    globalRotation.roll = roll;
}

void setGlobalRotationPitch(float pitch) {
    globalRotation.pitch = pitch;
}

void setGlobalRotationYaw(float yaw) {
    globalRotation.yaw = yaw;
}

// Camera Rotation
void setCameraRotation(Rotation rotation) {
    cameraRotation = rotation;
}

void setCameraRotationRoll(float roll) {
    cameraRotation.roll = roll;
}

void setCameraRotationPitch(float pitch) {
    cameraRotation.pitch = pitch;
}

void setCameraRotationYaw(float yaw) {
    cameraRotation.yaw = yaw;
}