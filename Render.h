#include <SDL2/SDL.h>
#include <Consts.h>

void renderPaddles(SDL_Surface *Surface, Paddle LeftPaddle, Paddle RightPaddle)
{
    SDL_FillRect(Surface, &(SDL_Rect){LeftPaddle.x, LeftPaddle.y, PADDLE_WIDTH, PADDLE_HEIGHT}, WHITE);
    SDL_FillRect(Surface, &(SDL_Rect){RightPaddle.x, RightPaddle.y, PADDLE_WIDTH, PADDLE_HEIGHT}, WHITE);
}

void renderCircle(SDL_Surface *Surface, Circle Circle)
{
    for (int i = 0; i < 365; i++)
    {
        double angleInRads = i * (3.1414 / 180);
        for (int r = 0; r < Circle.Radius; r++)
        {
            SDL_FillRect(Surface, &(SDL_Rect){Circle.Coords.x + r * SDL_cos(angleInRads), Circle.Coords.y + Circle.Radius * SDL_sin(angleInRads) - Circle.Radius / 2, 1, 1}, WHITE);
        }
    }
}

void renderNumber(SDL_Surface *Surface, vec2 Coords, int Number){
    for (int i = 0; i < sizeof(NUMBERS[Number]) / sizeof(NUMBERS[Number][0]); i++) {
        for (int j = 0; j < sizeof(NUMBERS[Number][i]) / sizeof(NUMBERS[Number][i][0]); j++){
            if ( !NUMBERS[Number][i][j]) continue;
            SDL_FillRect(Surface, &(SDL_Rect){Coords.x + (j * TEXT_PIXEL_WIDTH), Coords.y + (i * TEXT_PIXEL_HEIGHT), TEXT_PIXEL_WIDTH, TEXT_PIXEL_HEIGHT}, WHITE);
        }
    }
}