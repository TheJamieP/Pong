#include <Consts.h>

void handleMotion(Paddle *PaddlePtr)
{
    double vel = 0;
    if (PaddlePtr->motion.up) vel -= 10;
    if (PaddlePtr->motion.down) vel +=10;

    if (PaddlePtr->y <= 0 && vel < 0) return; 
    if (PaddlePtr->y + PADDLE_HEIGHT >= HEIGHT && vel > 0 ) return;

    PaddlePtr->y += vel;
}
