#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdbool.h>
#include <Movement.h>
#include <Consts.h>
#include <Render.h>
#include <Events.h>


int main()
{
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *Window = SDL_CreateWindow("Pong", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);
    SDL_Surface *Surface = SDL_GetWindowSurface(Window);

    SDL_Event Event;
    SDL_Rect __ERASE_RECT__ = (SDL_Rect){0, 0, WIDTH, HEIGHT};

    Paddle leftPaddle = {0, (HEIGHT / 2) - PADDLE_HEIGHT / 2};
    Paddle rightPaddle = {WIDTH - 25, (HEIGHT / 2) - PADDLE_HEIGHT / 2};
    Circle Ball = {WIDTH / 2, HEIGHT / 2, 25};

    while (true)
    {
        if (!handleEvents(Event, &leftPaddle, &rightPaddle)) break;
        handleMotion(&leftPaddle);
        handleMotion(&rightPaddle);
        SDL_FillRect(Surface, &__ERASE_RECT__, BLACK);
        renderPaddles(Surface, leftPaddle, rightPaddle);
        renderCircle(Surface, Ball);
        renderNumber(Surface, (vec2){300, 300}, 3);
        SDL_UpdateWindowSurface(Window);
        SDL_Delay(10);
    }
    return 0;
}
