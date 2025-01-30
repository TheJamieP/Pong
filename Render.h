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

void renderNumber(SDL_Surface *S, vec2 Coords, int Number){
    for (int i = 0; i < sizeof(NUMBERS[Number]) / sizeof(NUMBERS[Number][0]); i++) {
        for (int j = 0; j < sizeof(NUMBERS[Number][i]) / sizeof(NUMBERS[Number][i][0]); j++){
            if ( !NUMBERS[Number][i][j]) continue;
            SDL_FillRect(S, &(SDL_Rect){Coords.x + (j * TEXT_PIXEL_WIDTH), Coords.y + (i * TEXT_PIXEL_HEIGHT), TEXT_PIXEL_WIDTH, TEXT_PIXEL_HEIGHT}, WHITE);
        }
    }
}