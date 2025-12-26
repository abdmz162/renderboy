#pragma once

#include "object.h"

typedef struct {
    Object* objects;
    CameraCustom* cameras;
    int currentCamera; // Index
} State;