#include <SDL2/SDL.h>
#include <Consts.h>

void passRectToRender(SDL_Renderer* Renderer, SDL_Rect* Rect, SDL_Color Col){
    SDL_SetRenderDrawColor(Renderer, Col.r, Col.g, Col.b, Col.a);
    SDL_RenderFillRect(Renderer, Rect);
}

void renderPaddles(SDL_Renderer* Renderer, Player Players[2])
{
    
    for (int i = 0; i < 2; i++){
        Paddle paddle = Players[i].Paddle;
        SDL_SetRenderDrawColor(Renderer, paddle.Color.r, paddle.Color.g, paddle.Color.b, paddle.Color.a);
        SDL_RenderFillRect(Renderer, &(SDL_Rect){paddle.Coords.x, paddle.Coords.y, PADDLE_WIDTH, PADDLE_HEIGHT});
        // SDL_FillRect(Surface, &(SDL_Rect){paddle.Coords.x, paddle.Coords.y, PADDLE_WIDTH, PADDLE_HEIGHT}, paddle.Color);
    };
}

void renderCircle(SDL_Renderer* Renderer, Circle Circle)
{
    for (int i = 0; i < 365; i++)
    {
        double angleInRads = i * (3.1414 / 180);
        for (int r = 0; r < Circle.Radius; r++)
        {
            SDL_Rect Rect = (SDL_Rect){Circle.Coords.x + r * SDL_cos(angleInRads), Circle.Coords.y + Circle.Radius * SDL_sin(angleInRads) - Circle.Radius / 2, 1, 1};
            passRectToRender(Renderer, &Rect, WHITE);
        }
    }
}

void renderNumber(SDL_Renderer *Renderer, vec2 Coords, int Number){
    for (int i = 0; i < sizeof(NUMBERS[Number]) / sizeof(NUMBERS[Number][0]); i++) {
        for (int j = 0; j < sizeof(NUMBERS[Number][i]) / sizeof(NUMBERS[Number][i][0]); j++){
            if ( !NUMBERS[Number][i][j]) continue;
            SDL_Rect Rect = (SDL_Rect){Coords.x + (j * TEXT_PIXEL_WIDTH), Coords.y + (i * TEXT_PIXEL_HEIGHT), TEXT_PIXEL_WIDTH, TEXT_PIXEL_HEIGHT};
            passRectToRender(Renderer, &Rect, WHITE);
        }
    }
}

void renderScores(SDL_Renderer* Renderer, Player Players[2]){
    for (int i = 0; i<2; i++){
        renderNumber(Renderer, Players[i].Score.Coords, Players[i].Score.score);
    };
}