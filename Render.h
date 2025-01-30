#include <SDL2/SDL.h>
#include <Consts.h>

void renderPaddles(SDL_Surface *S, Paddle LeftPaddle, Paddle RightPaddle)
{
    SDL_FillRect(S, &(SDL_Rect){LeftPaddle.x, LeftPaddle.y, PADDLE_WIDTH, PADDLE_HEIGHT}, WHITE);
    SDL_FillRect(S, &(SDL_Rect){RightPaddle.x, RightPaddle.y, PADDLE_WIDTH, PADDLE_HEIGHT}, WHITE);
}

void renderCircle(SDL_Surface *S, Circle C)
{
    return;
    for (int i = 0; i < 365; i++)
    {
        double angleInRads = i * (3.1414 / 180);
        for (int r = 0; r < C.radius; r++)
        {
            SDL_FillRect(S, &(SDL_Rect){C.x + r * SDL_cos(angleInRads), C.y + C.radius * SDL_sin(angleInRads) - C.radius / 2, 1, 1}, WHITE);
        }
    }
}

void renderNumber(SDL_Surface *S, int Number){
    int Numbers[8][4][4] = {
        {
            {0, 1, 1, 0},
            {1, 0, 0, 1},
            {1, 0, 0, 1},
            {0, 1, 1, 0}
        },
        {
            {0, 1, 1, 0,},
            {0, 1, 1, 0,},
            {0, 1, 1, 0,},
            {0, 1, 1, 0},
        },
        {
            {1, 1, 1, 0,},
            {0, 0, 0, 1,},
            {0, 0, 1, 0,},
            {1, 1, 1, 1}
        }
    };

    int PIXEL_WIDTH = 10;
    int PIXEL_HEIGHT = 10;

    vec2 c = {200, 300};

    /*
        Pixels should be drawn at {210, 300} {220, 300}, {200, 310}, {230, 310}
    
    
    */

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++){
            if (*Numbers[i][j] < 1) SDL_FillRect(S, &(SDL_Rect){c.x + (i * PIXEL_WIDTH), c.y + (i* PIXEL_HEIGHT), PIXEL_WIDTH, PIXEL_HEIGHT}, RED);
            else {
                printf("Drawing pixel in square: {%d, %d}\n",c.x + (i * PIXEL_WIDTH), c.y + (i* PIXEL_HEIGHT) );
                SDL_FillRect(S, &(SDL_Rect){c.x + (i * PIXEL_WIDTH), c.y + (i* PIXEL_HEIGHT), PIXEL_WIDTH, PIXEL_HEIGHT}, WHITE);

            }
        }
    }


}