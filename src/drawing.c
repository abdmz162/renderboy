#include <stdio.h>
#include <math.h>

#include "drawing.h"

Vec3 screen(Vec3 alpha){
    // translates the 3d's camera coordinates into the 2d raylib coordinates
    Vec3 p_r={((alpha.x+1)/2*WIDTH),
            ((- alpha.y+1)/2*HEIGHT)
    };
    return p_r;
}

Vec3 project(Vec3 alpha){
    return (Vec3){alpha.x/alpha.z,alpha.y/alpha.z,alpha.z};
}

void draw_point(Vec3 beta){
    int s=10; 
    DrawRectangle(beta.x-s/2, beta.y-s/2, s, s, RAYWHITE);//sutracting s/2 to render the rectangle in the centre
}

Vec3 translate(Vec3 p,float dx, float dy, float dz){
    return (Vec3){p.x+dx,p.y+dy,p.z+dz};
}

Vec3 rotate_xz(float x,float y, float z, float theta){
    return (Vec3){x*cos(theta)-z*sin(theta),y,x*sin(theta)+z*cos(theta)};
}

Vec3 rotate_xz_point_based(Vec3 p, float theta){
    return (Vec3){p.x*cos(theta)-p.z*sin(theta),p.y,p.x*sin(theta)+p.z*cos(theta)};
}

void frame(const Vec3 cameraPosition, const Rotation cameraRotation) {

    float dx = cameraPosition.x;
    float dy = cameraPosition.y;
    float dz = cameraPosition.z;
    Rotation dtheta = cameraRotation;

    ClearBackground(BLACK);
    Vec3 projected_p1=project((rotate_xz_point_based(translate((Vec3){0.25,0.25,0.25},dx,dy,dz),dtheta)));
    // draw_point(rotate_xz_point_based(screen(projected_p1),dtheta));
    Vec3 projected_p2=project(rotate_xz_point_based(translate((Vec3){-0.25,0.25,0.25},dx,dy,dz),dtheta));
    // draw_point(rotate_xz_point_based(screen(projected_p2),dtheta));
    Vec3 projected_p3=project((rotate_xz_point_based(translate((Vec3){0.25,-0.25,0.25},dx,dy,dz),dtheta)));
    // draw_point(rotate_xz_point_based(screen(projected_p3),dtheta));
    Vec3 projected_p4=project((rotate_xz_point_based(translate((Vec3){-0.25,-0.25,0.25},dx,dy,dz),dtheta)));
    // draw_point(rotate_xz_point_based(screen(projected_p4),dtheta));
    Vec3 projected_p5=project(rotate_xz_point_based(translate((Vec3){0.25,0.25,-0.25},dx,dy,dz),dtheta));
    // draw_point(rotate_xz_point_based(screen(projected_p5),dtheta));
    Vec3 projected_p6=project(rotate_xz_point_based(translate((Vec3){-0.25,0.25,-0.25},dx,dy,dz),dtheta));
    // draw_point(rotate_xz_point_based(screen(projected_p6),dtheta));
    Vec3 projected_p7=project(rotate_xz_point_based(translate((Vec3){0.25,-0.25,-0.25},dx,dy,dz),dtheta));
    //draw_point(rotate_xz_point_based(screen(projected_p7),dtheta));
    Vec3 projected_p8=project(rotate_xz_point_based(translate((Vec3){-0.25,-0.25,-0.25},dx,dy,dz),dtheta));
    //draw_point(rotate_xz_point_based(screen(projected_p8),dtheta));

    //drawing lines:
    DrawLine((int)(screen((projected_p1)).x),
    (int)(screen((projected_p1)).y),
    (int)(screen((projected_p2)).x),
    (int)(screen((projected_p2)).y),
    GREEN
    );
    DrawLine((int)(screen((projected_p1)).x),
    (int)(screen((projected_p1)).y),
    (int)(screen((projected_p3)).x),
    (int)(screen((projected_p3)).y),
    GREEN
    );
    DrawLine((int)(screen((projected_p3)).x),
    (int)(screen((projected_p3)).y),
    (int)(screen((projected_p4)).x),
    (int)(screen((projected_p4)).y),
    GREEN
    );
    DrawLine((int)(screen((projected_p2)).x),
    (int)(screen((projected_p2)).y),
    (int)(screen((projected_p4)).x),
    (int)(screen((projected_p4)).y),
    GREEN
    );
    DrawLine((int)(screen((projected_p5)).x),
    (int)(screen((projected_p5)).y),
    (int)(screen((projected_p6)).x),
    (int)(screen((projected_p6)).y),
    RAYWHITE
    );
    DrawLine((int)(screen((projected_p5)).x),
    (int)(screen((projected_p5)).y),
    (int)(screen((projected_p7)).x),
    (int)(screen((projected_p7)).y),
    RAYWHITE
    );
    DrawLine((int)(screen((projected_p7)).x),
    (int)(screen((projected_p7)).y),
    (int)(screen((projected_p8)).x),
    (int)(screen((projected_p8)).y),
    RAYWHITE
    );
    DrawLine((int)(screen((projected_p6)).x),
    (int)(screen((projected_p6)).y),
    (int)(screen((projected_p8)).x),
    (int)(screen((projected_p8)).y),
    RAYWHITE
    );
    DrawLine((int)(screen((projected_p1)).x),
    (int)(screen((projected_p1)).y),
    (int)(screen((projected_p5)).x),
    (int)(screen((projected_p5)).y),
    RAYWHITE
    );DrawLine((int)(screen((projected_p2)).x),
    (int)(screen((projected_p2)).y),
    (int)(screen((projected_p6)).x),
    (int)(screen((projected_p6)).y),
    RAYWHITE
    );DrawLine((int)(screen((projected_p3)).x),
    (int)(screen((projected_p3)).y),
    (int)(screen((projected_p7)).x),
    (int)(screen((projected_p7)).y),
    RAYWHITE
    );DrawLine((int)(screen((projected_p4)).x),
    (int)(screen((projected_p4)).y),
    (int)(screen((projected_p8)).x),
    (int)(screen((projected_p8)).y),
    RAYWHITE
    );
}

void add_ui(const Vec3 cameraPosition, const Rotation cameraRotation) {

    char str[100];
    DrawFPS(100, 100);


    Color positionColor = RED;
    float fontSize = 20;
    int offsetX = 100, offsetY = 20;
    // X postition
    snprintf(str, sizeof(str), "X: %.3f", cameraPosition.x);
    DrawText(str, offsetX + 0, offsetY, fontSize, positionColor);

    // Y postition
    snprintf(str, sizeof(str), "Y: %.3f", cameraPosition.y);
    DrawText(str, offsetX + 130, offsetY, fontSize, positionColor);

    // Z postition
    snprintf(str, sizeof(str), "Z: %.3f", cameraPosition.z);
    DrawText(str, offsetX + 260, offsetY, fontSize, positionColor);

    // Angle
    snprintf(str, sizeof(str), "Theta: %.3f", cameraRotation);
    DrawText(str, offsetX + 390, offsetY, fontSize, positionColor);
}