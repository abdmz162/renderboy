#pragma once

#include "types/types.h"

// Reset Camera position and rotation to global defaults
void resetPosition();

// Set default position to reset to
void setGlobalPosition(Vec3 position);

void setGlobalPositionX(float x);

void setGlobalPositionY(float y);

void setGlobalPositionZ(float z);

void setCameraPosition(Vec3 position);

void setCameraPositionX(float x);

void setCameraPositionY(float y);

void setCameraPositionZ(float z);

// Set default rotation to reset to
void setGlobalRotation(Rotation rotation);

void setCameraRotation(Rotation rotation);