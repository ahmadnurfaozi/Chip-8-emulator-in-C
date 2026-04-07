#include <stdio.h>
#include "SDL2/SDL.h"
#include "chip8.h"

int main(int argc, char **argv){
    struct chip8 chip8;
    chip8_keyboard_down(&chip8.keyboard, 0x0f);
    chip8_keyboard_up(&chip8.keyboard, 0x0f);
    printf("%i\n", chip8_keyboard_is_down(&chip8.keyboard, 0x0f));

    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window *window = SDL_CreateWindow(
        EMULATOR_WINDOW_TITLE, 
        SDL_WINDOWPOS_UNDEFINED, 
        SDL_WINDOWPOS_UNDEFINED,
        CHIP8_WIDTH * CHIP8_WINDOW_MULTIPLIER, 
        CHIP8_HEIGHT * CHIP8_WINDOW_MULTIPLIER, 
        SDL_WINDOW_SHOWN
    );

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    while (1)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                goto out;
            }
            
        }
        
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_Rect r = {0, 0, 40, 40};
        SDL_RenderFillRect(renderer, &r);
        SDL_RenderPresent(renderer);
    }
    
    out:
        SDL_DestroyWindow(window);

    return 0;
}