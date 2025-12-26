#include "raylib.h"
#include <stdio.h>
#include <math.h>
#define WIDTH 800
#define HEIGHT 800
#define FPS 120
#define NEAR 0.1f

typedef struct {
    float x;
    float y;
    float z;
} point;//point in 3d space

point screen(point alpha){
    //translates the 3d's camera coordinates into the 2d raylib coordinates
    point p_r={((alpha.x+1)/2*WIDTH),
            ((- alpha.y+1)/2*HEIGHT)
    };
    //printf("x= %d,y= %d",p_r.x,p_r.y);
    return p_r;
}

point project(point alpha){
    if (alpha.z <= NEAR) {
        return (point){NAN, NAN, alpha.z}; // invalid projection
    }
    return (point){alpha.x/alpha.z,alpha.y/alpha.z,alpha.z};
}

int valid(point p){
    return !isnan(p.x) && !isnan(p.y);
}


void draw_point(point beta){
    int s=10; 
    DrawRectangle(beta.x-s/2, beta.y-s/2, s, s, RAYWHITE);//sutracting s/2 to render the rectangle in the centre
}

point translate(point p,float dx, float dy, float dz){
    return (point){p.x+dx,p.y+dy,p.z+dz};
}

point rotate_xz(float x,float y, float z, float theta){
    return (point){x*cos(theta)-z*sin(theta),y,x*sin(theta)+z*cos(theta)};
}

point rotate_xz_point_based(point p, float theta){//yaw
    return (point){p.x*cos(theta)-p.z*sin(theta),p.y,p.x*sin(theta)+p.z*cos(theta)};
}

point rotate_yz_point_based(point p, float phi){//pitch
    return (point){p.x,p.y*cos(phi)-p.z*sin(phi),p.y*sin(phi)+p.z*cos(phi)};
}


void frame(float dx, float dy, float dz, float dtheta,float dphi){
    
    ClearBackground(BLACK);
    point projected_p1=project(rotate_yz_point_based(rotate_xz_point_based(translate((point){0.5,0.5,0.5},dx,dy,dz), dtheta),dphi));//if i rotate then translate, it rotates the cube, but if i translate then rotate then my camera moves
    // draw_point(rotate_xz_point_based(screen(projected_p1) dtheta));
    point projected_p2=project(rotate_yz_point_based(rotate_xz_point_based(translate((point){-0.5,0.5,0.5},dx,dy,dz), dtheta),dphi));
    // draw_point(rotate_xz_point_based(screen(projected_p2) dtheta));
    point projected_p3=project(rotate_yz_point_based(rotate_xz_point_based(translate((point){0.5,-0.5,0.5},dx,dy,dz), dtheta),dphi));
    // draw_point(rotate_xz_point_based(screen(projected_p3) dtheta));
    point projected_p4=project(rotate_yz_point_based(rotate_xz_point_based(translate((point){-0.5,-0.5,0.5},dx,dy,dz), dtheta),dphi));
    // draw_point(rotate_xz_point_based(screen(projected_p4) dtheta));
    point projected_p5=project(rotate_yz_point_based(rotate_xz_point_based(translate((point){0.5,0.5,-0.5},dx,dy,dz), dtheta),dphi));
    // draw_point(rotate_xz_point_based(screen(projected_p5) dtheta));
    point projected_p6=project(rotate_yz_point_based(rotate_xz_point_based(translate((point){-0.5,0.5,-0.5},dx,dy,dz), dtheta),dphi));
    // draw_point(rotate_xz_point_based(screen(projected_p6) dtheta));
    point projected_p7=project(rotate_yz_point_based(rotate_xz_point_based(translate((point){0.5,-0.5,-0.5},dx,dy,dz), dtheta),dphi));
    //draw_point(rotate_xz_point_based(screen(projected_p7) dtheta));
    point projected_p8=project(rotate_yz_point_based(rotate_xz_point_based(translate((point){-0.5,-0.5,-0.5},dx,dy,dz), dtheta),dphi));
    //draw_point(rotate_xz_point_based(screen(projected_p8) dtheta));
    
    //drawing lines:
    if (valid(projected_p1) && valid(projected_p2))
        DrawLine((int)(screen((projected_p1)).x),
        (int)(screen((projected_p1)).y),
        (int)(screen((projected_p2)).x),
        (int)(screen((projected_p2)).y),
        GREEN
        );
    
    if (valid(projected_p1) && valid(projected_p3))
    DrawLine((int)(screen((projected_p1)).x),
    (int)(screen((projected_p1)).y),
    (int)(screen((projected_p3)).x),
    (int)(screen((projected_p3)).y),
    GREEN
    );

    if (valid(projected_p3) && valid(projected_p4))
    DrawLine((int)(screen((projected_p3)).x),
    (int)(screen((projected_p3)).y),
    (int)(screen((projected_p4)).x),
    (int)(screen((projected_p4)).y),
    GREEN
    );

    if (valid(projected_p2) && valid(projected_p4))
    DrawLine((int)(screen((projected_p2)).x),
    (int)(screen((projected_p2)).y),
    (int)(screen((projected_p4)).x),
    (int)(screen((projected_p4)).y),
    GREEN
    );

    if (valid(projected_p5) && valid(projected_p6))
    DrawLine((int)(screen((projected_p5)).x),
    (int)(screen((projected_p5)).y),
    (int)(screen((projected_p6)).x),
    (int)(screen((projected_p6)).y),
    BLUE
    );

    if (valid(projected_p5) && valid(projected_p7))
    DrawLine((int)(screen((projected_p5)).x),
    (int)(screen((projected_p5)).y),
    (int)(screen((projected_p7)).x),
    (int)(screen((projected_p7)).y),
    BLUE
    );

    if (valid(projected_p7) && valid(projected_p8))
    DrawLine((int)(screen((projected_p7)).x),
    (int)(screen((projected_p7)).y),
    (int)(screen((projected_p8)).x),
    (int)(screen((projected_p8)).y),
    BLUE
    );

    if (valid(projected_p6) && valid(projected_p8))
    DrawLine((int)(screen((projected_p6)).x),
    (int)(screen((projected_p6)).y),
    (int)(screen((projected_p8)).x),
    (int)(screen((projected_p8)).y),
    BLUE
    );

    if (valid(projected_p1) && valid(projected_p5))
    DrawLine((int)(screen((projected_p1)).x),
    (int)(screen((projected_p1)).y),
    (int)(screen((projected_p5)).x),
    (int)(screen((projected_p5)).y),
    RAYWHITE
    );
    
    if (valid(projected_p2) && valid(projected_p6))
    DrawLine((int)(screen((projected_p2)).x),
    (int)(screen((projected_p2)).y),
    (int)(screen((projected_p6)).x),
    (int)(screen((projected_p6)).y),
    RAYWHITE
    );
    
    if (valid(projected_p3) && valid(projected_p7))
    DrawLine((int)(screen((projected_p3)).x),
    (int)(screen((projected_p3)).y),
    (int)(screen((projected_p7)).x),
    (int)(screen((projected_p7)).y),
    RAYWHITE
    );
    
    if (valid(projected_p4) && valid(projected_p8))
    DrawLine((int)(screen((projected_p4)).x),
    (int)(screen((projected_p4)).y),
    (int)(screen((projected_p8)).x),
    (int)(screen((projected_p8)).y),
    RAYWHITE
    );
}


int main() {
    SetTargetFPS(FPS);
    float dz=1;
    float dx=0;
    float dy=0;
    float yaw_angle=0;//camera angle
    float pitch_angle=0;
    float frametime;
    float speed;
    //yaw variables
    //moving forward or backward
    float fx;//forward x-component
    float fz;//forward y-component
    //strafing
    float rx;//right x-component
    float rz;//right y-component
    InitWindow(WIDTH, HEIGHT, "Local Raylib");
    while (!WindowShouldClose()) {
        BeginDrawing();
        frame( dx,dy,dz,yaw_angle,pitch_angle);
        EndDrawing();
        frametime = GetFrameTime();
        speed = 1.0f * frametime;

        fx = sin(yaw_angle);
        fz = cos(yaw_angle);
        rx = cos(yaw_angle);
        rz = -sin(yaw_angle);

        if (IsKeyDown(KEY_W)) {
            dx -= fx * speed;
            dz -= fz * speed;
        }
        if (IsKeyDown(KEY_S)) {
            dx += fx * speed;
            dz += fz * speed;
        }
        if (IsKeyDown(KEY_A)) {
            dx += rx * speed;
            dz += rz * speed;
        }
        if (IsKeyDown(KEY_D)) {
            dx -= rx * speed;
            dz -= rz * speed;
        }
        if(IsKeyDown(KEY_SPACE)){
            dy-=speed;
        }if(IsKeyDown(KEY_LEFT_SHIFT)){
            dy+=speed;
        }if(IsKeyDown(KEY_RIGHT)){
            yaw_angle+=2*PI*speed/4;
        }if(IsKeyDown(KEY_LEFT)){
            yaw_angle-=2*PI*speed/4;
        }if(IsKeyDown(KEY_UP)){
            pitch_angle+=2*PI*speed/4;
        }if(IsKeyDown(KEY_DOWN)){
            pitch_angle-=2*PI*speed/4;
        }
        
        //dz+=1*frametime;
        //angle+=2*PI*frametime/8 ;
    }
    CloseWindow();
    return 0;
}

