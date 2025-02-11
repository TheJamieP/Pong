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

void clearScreen(SDL_Surface *s){
    SDL_FillRect(s, &(SDL_Rect){0, 0, WIDTH, HEIGHT}, BLACK);
}

int main()
{
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *Window = SDL_CreateWindow("Pong", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);
    SDL_Surface *Surface = SDL_GetWindowSurface(Window);

    SDL_Event Event;
    SDL_Rect __ERASE_RECT__ = (SDL_Rect){0, 0, WIDTH, HEIGHT};

    /*
    
    Paddle leftPaddle = {0, (HEIGHT / 2) - PADDLE_HEIGHT / 2};
    Paddle rightPaddle = {WIDTH - PADDLE_WIDTH, (HEIGHT / 2) - PADDLE_HEIGHT / 2};
    */
    Ball Ball = {{WIDTH/2, HEIGHT/2, 25}, {5,5}};
    

    Player Players[2] = {
        {
            (ScoreCard){0, (vec2){50, (WIDTH / 2) - 50}},
            (Paddle){(vec2){0, (HEIGHT / 2) - PADDLE_HEIGHT / 2}}
        },
        {
            (ScoreCard){0, (vec2){50, (WIDTH / 2) + 50}},
            (Paddle){(vec2){WIDTH - PADDLE_WIDTH, (HEIGHT / 2) - PADDLE_HEIGHT / 2}}
        }

    };
    while (true)
    {
        if (!handleEvents(Event, &Players[0].Paddle, &Players[1].Paddle)) break;
        
    
        checkBallBoundaryCollisions(&Ball);
        checkBallPaddleCollisions(&Ball, &Players[0].Paddle);
        checkBallPaddleCollisions(&Ball, &Players[1].Paddle);

        handlePaddleMotion(&Players[0].Paddle);
        handlePaddleMotion(&Players[1].Paddle);

        handleBallMotion(&Ball);
        
        clearScreen(Surface);
        
        renderPaddles(Surface, Players[0].Paddle, Players[1].Paddle);
        renderCircle(Surface, Ball.Body);
        renderNumber(Surface, (vec2){300, 300}, 3);
        
        SDL_UpdateWindowSurface(Window);
        SDL_Delay(10);
    }
    return 0;
}
