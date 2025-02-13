#include <SDL2/SDL.h>
#include <Consts.h>

bool handleEvents(SDL_Event e, Paddle* leftPaddlePtr, Paddle* rightPaddlePtr){
    while (SDL_PollEvent(&e))
        {
            switch (e.type)
            {
            case SDL_QUIT:
                return false;
                /* code */
                break;

            case SDL_KEYDOWN:
                switch (e.key.keysym.sym)
                {
                case SDLK_w:

                    leftPaddlePtr->motion.up = true;
                    break;

                case SDLK_s:
                    leftPaddlePtr->motion.down = true;
                    break;

                case SDLK_UP:
                    rightPaddlePtr->motion.up = true;
                    break;

                case SDLK_DOWN:
                    rightPaddlePtr->motion.down = true;
                    break;
                }
                break;

            case SDL_KEYUP:
                switch (e.key.keysym.sym)
                {
                case SDLK_w:

                    leftPaddlePtr->motion.up = false;
                    break;

                case SDLK_s:
                    leftPaddlePtr->motion.down = false;
                    break;

                case SDLK_UP:
                    rightPaddlePtr->motion.up = false;
                    break;

                case SDLK_DOWN:
                    rightPaddlePtr->motion.down = false;
                    break;
                }
                break;
            }
        }
    return true;
}


void resetBallPosition(Ball *ballptr){
    ballptr->Body.Coords.x = WIDTH / 2;
    ballptr->Body.Coords.y = HEIGHT / 2;
}

void checkBallBoundaryCollisions(Ball *ballPtr){
    vec2 *ballCoordsPtr = &ballPtr->Body.Coords;
    if (ballCoordsPtr->x > WIDTH)
    {
        ballPtr->Velocity.x = -1 * abs(ballPtr->Velocity.x);
        resetBallPosition(ballPtr);
    }
    
        else if (ballCoordsPtr->x < 0)
    {
        ballPtr->Velocity.x = abs(ballPtr->Velocity.x);
        resetBallPosition(ballPtr);
    }

    if (ballCoordsPtr->y  - ballPtr->Body.Radius< 0)
        ballPtr->Velocity.y = abs(ballPtr->Velocity.y);
    else if (ballCoordsPtr->y + ballPtr->Body.Radius > HEIGHT)
        ballPtr->Velocity.y = -1 * abs(ballPtr->Velocity.y);
}

void checkBallPaddleCollisions(Ball *ballPtr, Player Players[2])
{
    for (int i = 0; i < 2; i++){
        Paddle* paddlePtr = &(Players[i].Paddle);
        int radius = ballPtr->Body.Radius;
        int ballTopY = ballPtr->Body.Coords.y - radius;
        int ballBottomY = ballPtr->Body.Coords.y + radius;
        if (paddlePtr->Coords.x > WIDTH / 2){
            if (!((ballPtr->Body.Coords.x + radius >= paddlePtr->Coords.x) && ((ballBottomY <= paddlePtr->Coords.y + PADDLE_HEIGHT) && (ballTopY >= paddlePtr->Coords.y)))) continue;
            ballPtr->Velocity.x = -1 * abs(ballPtr->Velocity.x);
            continue;
        }
        if (!((ballPtr->Body.Coords.x - radius <= paddlePtr->Coords.x + PADDLE_WIDTH) && ((ballBottomY <= paddlePtr->Coords.y + PADDLE_HEIGHT) && (ballTopY >= paddlePtr->Coords.y)))) continue;
        ballPtr->Velocity.x = abs(ballPtr->Velocity.x);
    };
}
