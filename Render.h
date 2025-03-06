#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
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

void renderText(SDL_Renderer *Renderer, vec2 Coords, char* Text, int Size) {
    // Load font

    TTF_Font* Font = TTF_OpenFont("Ubuntu-R.ttf", Size);
    if (!Font) {
        printf("Failed to load font: %s\n", TTF_GetError());
        return;
    }
    SDL_Surface* textSurface = TTF_RenderText_Solid(Font, Text, WHITE);

    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(Renderer, textSurface);
    SDL_FreeSurface(textSurface);

    
    SDL_Rect destRect = {Coords.x, Coords.y, textSurface->w, textSurface->h};
    SDL_RenderCopy(Renderer, textTexture, NULL, &destRect);

    SDL_DestroyTexture(textTexture);
    TTF_CloseFont(Font);
}



void renderScores(SDL_Renderer* Renderer, SDL_Surface* Surface, Player Players[2]){
    for (int i = 0; i<2; i++){
        char c = Players[i].Score.score + '0';
        renderText(Renderer, Players[i].Score.Coords, &c, 72);
    };
}