#include <Consts.h>

void handlePaddleMotion(Paddle *PaddlePtr)
{
    double vel = 0;
    if (PaddlePtr->motion.up)
        vel -= 10;
    if (PaddlePtr->motion.down)
        vel += 10;

    if (PaddlePtr->y <= 0 && vel < 0)
        return;
    if (PaddlePtr->y + PADDLE_HEIGHT >= HEIGHT && vel > 0)
        return;

    PaddlePtr->y += vel;
}

void checkCollisions(Ball *ballPtr, Paddle *leftPaddlePtr, Paddle *rightPaddlePtr)
{
    vec2 *ballCoordsPtr = &ballPtr->Body.Coords;

    // Boundary checks

    if (ballCoordsPtr->x > WIDTH)
        ballPtr->Velocity.x = -1 * abs(ballPtr->Velocity.x);
    else if (ballCoordsPtr->x < 0)
        ballPtr->Velocity.x = abs(ballPtr->Velocity.x);

    if (ballCoordsPtr->y < 0)
        ballPtr->Velocity.y = abs(ballPtr->Velocity.y);
    else if (ballCoordsPtr->y > HEIGHT)
        ballPtr->Velocity.y = -1 * abs(ballPtr->Velocity.y);

    //TODO: please fucking refactor this at some point, its fucking awfully built but i just want to get this out the way.
    bool ballXCoordEqualsRightPaddle = ballCoordsPtr->x + ballPtr->Body.Radius == rightPaddlePtr->x;
    bool ballYCoordEqualsRightPaddle = (ballCoordsPtr->y + ballPtr->Body.Radius < rightPaddlePtr->y + PADDLE_HEIGHT && ballCoordsPtr->y - ballPtr->Body.Radius > rightPaddlePtr->y);
    if (ballXCoordEqualsRightPaddle && ballYCoordEqualsRightPaddle)
        ballPtr->Velocity.x = -1 * abs(ballPtr->Velocity.x);

    bool ballXCoordEqualsLeftPaddle = ballCoordsPtr->x - ballPtr->Body.Radius == leftPaddlePtr->x;
    bool ballYCoordEqualsLeftPaddle = (ballCoordsPtr->y + ballPtr->Body.Radius < leftPaddlePtr->y + PADDLE_HEIGHT && ballCoordsPtr->y - ballPtr->Body.Radius > leftPaddlePtr->y);

    if (ballXCoordEqualsLeftPaddle && ballYCoordEqualsLeftPaddle) ballPtr->Velocity.x = abs(ballPtr->Velocity.x);
}

void handleBallMotion(Ball *ballPtr)
{
    ballPtr->Body.Coords.x += ballPtr->Velocity.x;
    ballPtr->Body.Coords.y += ballPtr->Velocity.y;
}