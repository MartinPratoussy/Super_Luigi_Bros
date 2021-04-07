#include "world.h"

void World::CreatePlayer(Renderer* renderer)
{
    this->player = new Player(renderer, 50, 50);
}

void World::RenderBackground(Renderer* renderer, Texture* backgroundTexture, SDL_Rect* destRect)
{
    SDL_RenderCopy(renderer->renderer, backgroundTexture->texture, NULL, destRect);
}

void World::MovePlayer(Player* player)
{
    const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
    // Vertical deplacement
    if (currentKeyStates[SDL_SCANCODE_UP]) {
        player->y--;
    }
    else if (currentKeyStates[SDL_SCANCODE_DOWN]) {
        player->y++;
    }
    // Horizontal deplacement
    else if (currentKeyStates[SDL_SCANCODE_LEFT]) {
        player->x--;
    }
    else if (currentKeyStates[SDL_SCANCODE_RIGHT]) {
        player->x++;
    }
    // Diagonal deplacement Up
    else if (currentKeyStates[SDL_SCANCODE_UP] && currentKeyStates[SDL_SCANCODE_LEFT]) {
        player->y--;
        player->x--;
    }
    else if (currentKeyStates[SDL_SCANCODE_UP] && currentKeyStates[SDL_SCANCODE_RIGHT]) {
        player->y--;
        player->x++;
    }
    // Diagonal deplacement Down
    else if (currentKeyStates[SDL_SCANCODE_DOWN] && currentKeyStates[SDL_SCANCODE_LEFT]) {
        player->y++;
        player->x--;
    }
    else if (currentKeyStates[SDL_SCANCODE_DOWN] && currentKeyStates[SDL_SCANCODE_RIGHT]) {
        player->y++;
        player->x++;
    }
    else {
        return;
    }
}


void World::StartWorld(Renderer* renderer, Window* window)
{
    IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);    
    Surface* ico = new Surface("Ressources/LouigiIcon.bmp");
    SDL_SetWindowIcon(window->window, ico->surface);

    // Declare elements of the game
    CreatePlayer(renderer);

    Surface* backgroundSurface = new Surface("Ressources/background.png");    
    Texture* backgroundTexture = new Texture(renderer, backgroundSurface);
    SDL_Rect* backgroundRect = new SDL_Rect();
    backgroundRect->w = backgroundSurface->surface->w;
    backgroundRect->h = window->windowSurface->h;

    // Events loop
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
        SDL_RenderClear(renderer->renderer);

        RenderBackground(renderer, backgroundTexture, backgroundRect);
        MovePlayer(player);

        /* Here comes the code */ 
        this->player->GetEntity(renderer);

        SDL_Delay(8);
        SDL_RenderPresent(renderer->renderer);
    }
    delete renderer;
    delete window;
    SDL_Quit();
}
