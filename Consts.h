#include <stdbool.h>

#ifndef WIDTH

#define WIDTH 800
#define HEIGHT 800
#define PADDLE_WIDTH 25
#define PADDLE_HEIGHT 150

#define WHITE 0xFFFFFFFF
#define BLACK 0x00000000
#define RED 0xFFFF0000

typedef struct {
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

typedef struct {
    int x;
    int y;
} vec2;

#endif