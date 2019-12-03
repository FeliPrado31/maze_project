#include "main.h"

int pool_even()
{
    SDL_Event event;
    SDL_KeyboardEvent key;

    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            return (1);
        case SDL_KEYDOWN:
            key = event.key;
            /* if ESCAPE is pressed*/
            if (key.keysym.scancode == 0x29)
                return (1);
            break;
        }
    }
    return (0);
}

void draw_stuff(SDL_Instance instance)
{
    SDL_SetRenderDrawColor(instance.renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderDrawLine(instance.renderer, 10, 10, 100, 100);
}

int init_instance(SDL_Instance *instance)
{
    SDL_Window *window;
    SDL_Renderer *renderer;

    /*Initialie SDL*/
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        fprintf(stderr, "Unable to initialize SDL: %s\n", SDL_GetError());
        return (1);
    }
    /*Create a new Window instance*/
    window = SDL_CreateWindow("EquipoAlfaBuenaMaravillaOndaDinamitaEscuadronLobo", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 500, 500, 0);
    if (window == NULL)
    {
        fprintf(stderr, "SDL_CreateWindow Error: %s\n", SDL_GetError());
        SDL_Quit();
        return (1);
    }
    /* create a new rendere instance*/
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == NULL)
    {
        SDL_DestroyWindow(window);
        fprintf(stderr, "SLD_CreateRenderer Error: %s\n", SDL_GetError());
        SDL_Quit();
        return (1);
    }
    return (0);
}
