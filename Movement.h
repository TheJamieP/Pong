#include <Consts.h>

void handlePaddleMotion(Player Players[2])
{
    for (int i = 0; i < 2; i++){
        double vel = 0;
        Paddle* PaddlePtr = &Players[i].Paddle;

        if (PaddlePtr->motion.up)
            vel -= 10;
        if (PaddlePtr->motion.down)
            vel += 10;

        if (PaddlePtr->Coords.y <= 0 && vel < 0)
            continue;
        if (PaddlePtr->Coords.y + PADDLE_HEIGHT >= HEIGHT && vel > 0)
            continue;

        PaddlePtr->Coords.y += vel;
    }
}

void handleBallMotion(Ball *ballPtr)
{
    ballPtr->Body.Coords.x += ballPtr->Velocity.x;
    ballPtr->Body.Coords.y += ballPtr->Velocity.y;
}