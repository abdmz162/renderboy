#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include "drawing.h"

Vec3 screen(Vec3 alpha) {
    // translates the 3d's camera coordinates into the 2d raylib coordinates
    Vec3 p_r={((alpha.x+1)/2*WIDTH),
            ((- alpha.y+1)/2*HEIGHT)
    };
    return p_r;
}

Vec3 project(Vec3 alpha) {
    if (alpha.z <= NEAR) {
        return (Vec3){NAN, NAN, alpha.z}; // invalid projection
    }
    return (Vec3){alpha.x/alpha.z,alpha.y/alpha.z,alpha.z};
}

int valid(Vec3 p) {
    return !isnan(p.x) && !isnan(p.y);
}


void draw_point(Vec3 beta) {
    int s=10; 
    DrawRectangle(beta.x-s/2, beta.y-s/2, s, s, RAYWHITE);//sutracting s/2 to render the rectangle in the centre
}

Vec3 translate(Vec3 p,float dx, float dy, float dz) {
    return (Vec3){p.x+dx,p.y+dy,p.z+dz};
}

Vec3 rotate_xz(float x,float y, float z, float psi) {
    return (Vec3){x*cos(psi)-z*sin(psi),y,x*sin(psi)+z*cos(psi)};
}

Vec3 rotate_xz_point_based(Vec3 p, float psi) { // yaw
    return (Vec3){p.x*cos(psi)-p.z*sin(psi),p.y,p.x*sin(psi)+p.z*cos(psi)};
}

Vec3 rotate_yz_point_based(Vec3 p, float theta) { // pitch
    return (Vec3){p.x,p.y*cos(theta)-p.z*sin(theta),p.y*sin(theta)+p.z*cos(theta)};
}

Vec3 rotate_xy_point_based(Vec3 p, float phi) { //roll
    return (Vec3){p.x*cos(phi)-p.y*sin(phi), p.x*sin(phi)+p.y*cos(phi) ,p.z};
}

void drawEdge(Vec3 p1, Vec3 p2, Color color) {
    if (valid(p1) && valid(p2))
        DrawLine((int)(screen((p1)).x),
        (int)(screen((p1)).y),
        (int)(screen((p2)).x),
        (int)(screen((p2)).y),
        color
        );
}

void frame(const Vec3 cameraPosition, const Rotation cameraRotation) {

    float dx = cameraPosition.x;
    float dy = cameraPosition.y;
    float dz = cameraPosition.z;
    float dyaw = cameraRotation.yaw;
    float dpitch = cameraRotation.pitch;
    float droll = cameraRotation.roll;

    ClearBackground(BLACK);

    Vec3 points[] = {
        {0.5,0.5,0.5},
        {-0.5,0.5,0.5},
        {0.5,-0.5,0.5},
        {-0.5,-0.5,0.5},
        {0.5,0.5,-0.5},
        {-0.5,0.5,-0.5},
        {0.5,-0.5,-0.5},
        {-0.5,-0.5,-0.5},
    };

    int numberOfPoints = sizeof(points) / sizeof(Vec3);
    Vec3 *projectedPoints = calloc(numberOfPoints, sizeof(Vec3));

    for (int i = 0; i < numberOfPoints; i++) {
        projectedPoints[i] = project(rotate_xy_point_based(rotate_yz_point_based(rotate_xz_point_based(translate(points[i],dx,dy,dz), dyaw),dpitch),droll));
    }

    Edge edges[] = {
        {0, 1, GREEN},
        {0, 2, GREEN},
        {2, 3, GREEN},
        {1, 3, GREEN},
        {4, 5, BLUE},
        {4, 6, BLUE},
        {5, 7, BLUE},
        {6, 7, BLUE},
        {0, 4, RED},
        {1, 5, RED},
        {2, 6, RAYWHITE},
        {3, 7, RAYWHITE},
    };

    for (int i = 0; i < (sizeof(edges) / sizeof(Edge)); i++) {
        Edge edge = edges[i];
        Vec3 p1 = projectedPoints[edge.v1];
        Vec3 p2 = projectedPoints[edge.v2];
        drawEdge(p1, p2, edge.color);
    }
}


float radToDeg(float rad) {
    return rad * (180 / PI);
}

void add_ui(const Vec3 cameraPosition, const Rotation cameraRotation) {

    char str[100];
    DrawFPS(100, 100);


    Color positionColor = RED;
    float fontSize = 20;
    int offsetX = 30, offsetY = 20;
    int floatPrecision = 2;
    // X postition
    snprintf(str, sizeof(str), "X: %.*f", floatPrecision, cameraPosition.x);
    DrawText(str, offsetX + 0, offsetY, fontSize, positionColor);

    // Y postition
    snprintf(str, sizeof(str), "Y: %.*f", floatPrecision, cameraPosition.y);
    DrawText(str, offsetX + 120, offsetY, fontSize, positionColor);

    // Z postition
    snprintf(str, sizeof(str), "Z: %.*f", floatPrecision, cameraPosition.z);
    DrawText(str, offsetX + 240, offsetY, fontSize, positionColor);

    // Yaw Angle
    snprintf(str, sizeof(str), "Yaw: %.*f", floatPrecision, radToDeg(cameraRotation.yaw));
    DrawText(str, offsetX + 340, offsetY, fontSize, positionColor);

    // Pitch Angle
    snprintf(str, sizeof(str), "Pitch: %.*f", floatPrecision, radToDeg(cameraRotation.pitch));
    DrawText(str, offsetX + 480, offsetY, fontSize, positionColor);

    // Roll Angle
    snprintf(str, sizeof(str), "Roll: %.*f", floatPrecision, radToDeg(cameraRotation.roll));
    DrawText(str, offsetX + 620, offsetY, fontSize, positionColor);
}