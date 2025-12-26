#pragma once

#include "raylib.h"
#include "consts.h"
#include "types/types.h"

Vec3 screen(Vec3 alpha);

Vec3 project(Vec3 alpha);

int valid(Vec3 p);

void draw_point(Vec3 beta);

Vec3 translate(Vec3 p,float dx, float dy, float dz);

Vec3 rotate_xz(float x,float y, float z, float theta);

Vec3 rotate_xz_point_based(Vec3 p, float theta);

Vec3 rotate_yz_point_based(Vec3 p, float phi);

void frame(Vec3 cameraPosition, Rotation cameraRotation);

void add_ui(Vec3 cameraPosition, Rotation cameraRotation);