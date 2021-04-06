#include "world.h"

void World::StartWorld(Renderer* renderer, Window* window)
{
    SDL_Event events;
    bool isOpen = true;
    while (isOpen) {
        while (SDL_PollEvent(&events))
            switch (events.type)
            {
            case SDL_QUIT:
                isOpen = false;
                break;
            }

        /* Here comes the code */ 

    }
    SDL_DestroyRenderer(renderer->renderer);
    SDL_DestroyWindow(window->window);
    SDL_Quit();    
}
