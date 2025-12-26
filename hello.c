#include "raylib.h"
#include <stdio.h>
#include <math.h>
#define WIDTH 800
#define HEIGHT 800
#define FPS 120

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
    return (point){alpha.x/alpha.z,alpha.y/alpha.z,alpha.z};
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

point rotate_xz_point_based(point p, float theta){
    return (point){p.x*cos(theta)-p.z*sin(theta),p.y,p.x*sin(theta)+p.z*cos(theta)};
}

void frame(float dx, float dy, float dz, float dtheta){

    ClearBackground(BLACK);
    point projected_p1=project((rotate_xz_point_based(translate((point){0.25,0.25,0.25},dx,dy,dz),dtheta)));
    // draw_point(rotate_xz_point_based(screen(projected_p1),dtheta));
    point projected_p2=project(rotate_xz_point_based(translate((point){-0.25,0.25,0.25},dx,dy,dz),dtheta));
    // draw_point(rotate_xz_point_based(screen(projected_p2),dtheta));
    point projected_p3=project((rotate_xz_point_based(translate((point){0.25,-0.25,0.25},dx,dy,dz),dtheta)));
    // draw_point(rotate_xz_point_based(screen(projected_p3),dtheta));
    point projected_p4=project((rotate_xz_point_based(translate((point){-0.25,-0.25,0.25},dx,dy,dz),dtheta)));
    // draw_point(rotate_xz_point_based(screen(projected_p4),dtheta));
    point projected_p5=project(rotate_xz_point_based(translate((point){0.25,0.25,-0.25},dx,dy,dz),dtheta));
    // draw_point(rotate_xz_point_based(screen(projected_p5),dtheta));
    point projected_p6=project(rotate_xz_point_based(translate((point){-0.25,0.25,-0.25},dx,dy,dz),dtheta));
    // draw_point(rotate_xz_point_based(screen(projected_p6),dtheta));
    point projected_p7=project(rotate_xz_point_based(translate((point){0.25,-0.25,-0.25},dx,dy,dz),dtheta));
    //draw_point(rotate_xz_point_based(screen(projected_p7),dtheta));
    point projected_p8=project(rotate_xz_point_based(translate((point){-0.25,-0.25,-0.25},dx,dy,dz),dtheta));
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


int main() {
    SetTargetFPS(FPS);
    float dz=1;
    float dx=0;
    float dy=0;
    float angle=0;
    float frametime;
    InitWindow(WIDTH, HEIGHT, "Local Raylib");
    while (!WindowShouldClose()) {
        BeginDrawing();
        frame( dx,dy,dz,angle);
        EndDrawing();
        frametime = GetFrameTime();
        if(IsKeyDown(KEY_S)){
            dz+=1*frametime;
        }if(IsKeyDown(KEY_W)){
            dz-=1*frametime;
        }if(IsKeyDown(KEY_A)){
            dx+=1*frametime;
        }if(IsKeyDown(KEY_D)){
            dx-=1*frametime;
        }if(IsKeyDown(KEY_SPACE)){
            dy-=1*frametime;
        }if(IsKeyDown(KEY_LEFT_SHIFT)){
            dy+=1*frametime;
        }if(IsKeyDown(KEY_RIGHT)){
            angle+=2*frametime/4;
        }if(IsKeyDown(KEY_LEFT)){
            angle-=2*frametime/4;
        }
        
        //dz+=1*frametime;
        //angle+=2*PI*frametime/8 ;
    }
    CloseWindow();
    return 0;
}

