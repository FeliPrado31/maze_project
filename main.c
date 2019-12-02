/**
 * Don't forget to compile with: `sdl2-config --cflags`
 * Don't forget to link with: `sdl2-config --libs` -lSDL2_ttf
 */
#include "main.h"

int main(void)
{
    SDL_Instance instance;

    if (init_instance(&instance) != 0)
        return (1);
    
    while ("C is Awesome")
    {
        SDL_SetRenderDrawColor(instance.renderer, 0, 0, 0, 0);
        SDL_RenderClear(instance.renderer);
        draw_stuff(instance);
        SDL_RenderPresent(instance.renderer);
    }
    return (0);
}