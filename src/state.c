#include "state.h"

Vec3 globalPosition = {
    0, 0, 1
};
Rotation globalRotation = {
    0, 0, 0
}; 

Vec3 cameraPosition;
Rotation cameraRotation;

Array objects;

State state;