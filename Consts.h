#include <stdbool.h>

#ifndef WIDTH

#define WIDTH 800
#define HEIGHT 800
#define PADDLE_WIDTH 25
#define PADDLE_HEIGHT 150

#define WHITE (SDL_Color){255,255,255,255}
#define BLACK (SDL_Color){0,0,0,255}
#define RED (SDL_Color){255,0,0,255}
#define GREEN (SDL_Color){0,255,0,255}
#define BLUE (SDL_Color){0,0,255,0}

typedef struct
{
    double x;
    double y;
} vec2;

typedef struct
{
    bool up;
    bool down;
} Motion;

typedef struct
{
    vec2 Coords;
    Motion motion;
    SDL_Color Color;
} Paddle;

typedef struct
{
    vec2 Coords;
    double Radius;
} Circle;

typedef struct 
{
    Circle Body;
    vec2 Velocity;
} Ball;

typedef struct
{
    int score;
    vec2 Coords;
} ScoreCard;

typedef struct 
{
    ScoreCard Score;
    Paddle Paddle;
} Player;

const int NUMBERS[10][5][5] = {
    // 0
    {{0, 1, 1, 1, 0},
     {1, 0, 0, 0, 1},
     {1, 0, 0, 0, 1},
     {1, 0, 0, 0, 1},
     {0, 1, 1, 1, 0}},
    
    // 1
    {{1, 1, 1, 0, 0},
     {0, 0, 1, 0, 0},
     {0, 0, 1, 0, 0},
     {0, 0, 1, 0, 0},
     {1, 1, 1, 1, 1}},
    
    // 2
    {{0, 1, 1, 1, 1},
     {1, 0, 0, 0, 1},
     {1, 0, 0, 1, 0},
     {0, 0, 1, 0, 0},
     {1, 1, 1, 1, 1}},
    
    // 3
    {{1, 1, 1, 1, 1},
     {0, 0, 0, 0, 1},
     {0, 1, 1, 1, 1},
     {0, 0, 0, 0, 1},
     {1, 1, 1, 1, 1}},
    
    // 4
    {{1, 0, 0, 0, 1},
     {1, 0, 0, 0, 1},
     {1, 1, 1, 1, 1},
     {0, 0, 0, 0, 1},
     {0, 0, 0, 0, 1}},
    
    // 5
    {{1, 1, 1, 1, 1},
     {1, 0, 0, 0, 0},
     {1, 1, 1, 1, 1},
     {0, 0, 0, 0, 1},
     {1, 1, 1, 1, 0}},
    
    // 6
    {{1, 1, 1, 1, 1},
     {1, 0, 0, 0, 0},
     {1, 1, 1, 1, 1},
     {1, 0, 0, 0, 1},
     {1, 1, 1, 1, 1}},


    // 7
    {{1, 1, 1, 1, 1},
     {0, 0, 0, 1, 0},
     {0, 0, 1, 0, 0},
     {0, 0, 1, 0, 0},
     {0, 0, 1, 0, 0}},

    // 8
    {{0, 1, 1, 1, 0},
     {1, 0, 0, 0, 1},
     {0, 1, 1, 1, 0},
     {1, 0, 0, 0, 1},
     {0, 1, 1, 1, 0}},

    // 9
    {{0, 1, 1, 1, 0},
     {1, 0, 0, 0, 1},
     {0, 1, 1, 1, 1},
     {0, 0, 0, 0, 1},
     {0, 0, 0, 0, 1}}
};

#define TEXT_PIXEL_WIDTH 10
#define TEXT_PIXEL_HEIGHT 10

#endif