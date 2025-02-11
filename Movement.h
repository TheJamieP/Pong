#include <Consts.h>

void handlePaddleMotion(Paddle *PaddlePtr)
{
    double vel = 0;
    if (PaddlePtr->motion.up)
        vel -= 10;
    if (PaddlePtr->motion.down)
        vel += 10;

    if (PaddlePtr->Coords.y <= 0 && vel < 0)
        return;
    if (PaddlePtr->Coords.y + PADDLE_HEIGHT >= HEIGHT && vel > 0)
        return;

    PaddlePtr->Coords.y += vel;
}

void handleBallMotion(Ball *ballPtr)
{
    ballPtr->Body.Coords.x += ballPtr->Velocity.x;
    ballPtr->Body.Coords.y += ballPtr->Velocity.y;
}