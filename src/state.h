#pragma once
#include "types/types.h"

// Global defaults (can be used for spawning/resetting camera)
extern Vec3 globalPosition;
extern Rotation globalRotation; // Switch to quaternion or something later

// Camera state
extern Vec3 cameraPosition;
extern Rotation cameraRotation;

// Objects in space
extern Array objects; // will use later prbbly

// Entire state. Could be used later. Above things would be commented ig
extern State state;