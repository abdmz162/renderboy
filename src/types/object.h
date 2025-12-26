#pragma once

#include "colors.h"
#include "vector.h"

typedef float Vertex;
typedef float Face;

typedef struct {
    Vec3 position;
    Rotation rotation;
    Vec3 scale; // could use later
} Transform3D; // Name from unity

typedef struct {
    // Vertices index
    int v1;
    int v2;
    ColorRGBA color;
} Edge;

typedef struct {
    Transform3D transform;
    Vertex* vertices;
    Edge* edges; // b/w 2 vertices
    Face* faces; // will use later ig or something
    struct Object* children; // Can be used for hierarchy frfrfrfrfrfrfrfr.
    // More fields such as color or other things
} Object; // 3d object

typedef struct {
    Transform3D transform; // For now only transform.
    // Isomorphic view maybe later.
} CameraCustom;