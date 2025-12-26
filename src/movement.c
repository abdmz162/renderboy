#include "movement.h"
#include "state.h"

void resetPosition() {
    cameraPosition = globalPosition;
    cameraRotation = globalRotation;
}

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

void setGlobalRotation(Rotation rotation) {
    globalRotation = rotation;
}

void setCameraRotation(Rotation rotation) {
    cameraRotation = rotation;
}