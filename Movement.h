#include <Consts.h>

void handlePaddleMotion(Paddle *PaddlePtr)
{
    double vel = 0;
    if (PaddlePtr->motion.up) vel -= 10;
    if (PaddlePtr->motion.down) vel +=10;

    if (PaddlePtr->y <= 0 && vel < 0) return; 
    if (PaddlePtr->y + PADDLE_HEIGHT >= HEIGHT && vel > 0 ) return;

    PaddlePtr->y += vel;
}


void handleBallMotion(Ball *ballPtr) {
    vec2* Coords = &ballPtr->Body.Coords;
    vec2* Vel = &ballPtr->Velocity;

    if (Coords->x < 0) Vel->x = abs(Vel->x);
    if (Coords->x > WIDTH) Vel->x = -1 * abs(Vel->x);
    if (Coords->y < 0) Vel->y = abs(Vel->y);
    if (Coords->y > HEIGHT) Vel->y = -1 * abs(Vel->y);
    
    Coords->x += Vel->x;
    Coords->y += Vel->y;
}