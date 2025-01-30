#include <SDL2/SDL.h>
#include <Consts.h>

bool handleEvents(SDL_Event e, Paddle* leftPaddlePtr, Paddle* rightPaddlePtr){
    while (SDL_PollEvent(&e))
        {
            switch (e.type)
            {
            case SDL_QUIT:
                return false;
                /* code */
                break;

            case SDL_KEYDOWN:
                switch (e.key.keysym.sym)
                {
                case SDLK_w:

                    leftPaddlePtr->motion.up = true;
                    break;

                case SDLK_s:
                    leftPaddlePtr->motion.down = true;
                    break;

                case SDLK_UP:
                    rightPaddlePtr->motion.up = true;
                    break;

                case SDLK_DOWN:
                    rightPaddlePtr->motion.down = true;
                    break;
                }
                break;

            case SDL_KEYUP:
                switch (e.key.keysym.sym)
                {
                case SDLK_w:

                    leftPaddlePtr->motion.up = false;
                    break;

                case SDLK_s:
                    leftPaddlePtr->motion.down = false;
                    break;

                case SDLK_UP:
                    rightPaddlePtr->motion.up = false;
                    break;

                case SDLK_DOWN:
                    rightPaddlePtr->motion.down = false;
                    break;
                }
                break;
            }
        }
    return true;
}
