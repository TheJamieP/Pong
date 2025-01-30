#include <stdbool.h>

#ifndef WIDTH

#define WIDTH 800
#define HEIGHT 800
#define PADDLE_WIDTH 25
#define PADDLE_HEIGHT 150

#define WHITE 0xFFFFFFFF
#define BLACK 0x00000000
#define RED 0xFFFF0000

typedef struct
{
    bool up;
    bool down;
} Motion;

typedef struct
{
    int x;
    int y;
    Motion motion;
} Paddle;

typedef struct
{
    int x;
    int y;
    double radius;
} Circle;

typedef struct
{
    int x;
    int y;
} vec2;

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