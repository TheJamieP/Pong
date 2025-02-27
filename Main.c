#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdbool.h>
#include <Movement.h>
#include <Consts.h>
#include <Events.h>
#include <Render.h>
/*
TODO: Refactor rendering to allow passing an array of paddles, balls and such.
TODO: Implement a scoring system.
TODO: Fucking dreading this: text to display "Game Over" screen. Might be worth implementing a system to draw based on a font file. 
*/

void main()
{
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *Window = SDL_CreateWindow("Pong", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);
    SDL_Renderer * Renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED);
    SDL_Surface *Screen = SDL_GetWindowSurface(Window);

    SDL_Event Event;
    SDL_Rect __ERASE_RECT__ = (SDL_Rect){0, 0, WIDTH, HEIGHT};

    Ball Ball = {{WIDTH/2, HEIGHT/2, 16}, {5,5}};
    

    Player Players[2] = {
        {
            (ScoreCard){0, (vec2){WIDTH / 2 - 100, 50}},
            (Paddle){(vec2){0, (HEIGHT / 2) - PADDLE_HEIGHT / 2}, (Motion){false,false}, BLUE}
        },
        {
            (ScoreCard){0, (vec2){WIDTH / 2 + 100, 50}},
            (Paddle){(vec2){WIDTH - PADDLE_WIDTH, (HEIGHT / 2) - PADDLE_HEIGHT / 2}, (Motion){false,false},RED}
        }

    };
    while (handleEvents(Event, &Players[0].Paddle, &Players[1].Paddle))
    {
        
        checkBallBoundaryCollisions(&Ball);
        checkBallPaddleCollisions(&Ball, Players);

        handlePaddleMotion(Players);
        handleBallMotion(&Ball);
        
        SDL_SetRenderDrawColor(Renderer, 0, 0, 0, 255);

        SDL_RenderClear(Renderer);
    
        
        renderScores(Renderer, Players);
        renderPaddles(Renderer, Players);
        renderCircle(Renderer, Ball.Body);

        SDL_RenderPresent(Renderer);
        SDL_Delay(10);
    }

    SDL_DestroyRenderer(Renderer);
    SDL_DestroyWindow(Window);
}
