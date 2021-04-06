#include "window.h"

Window::Window()
{
    SDL_Init(SDL_INIT_EVERYTHING);

    this->window = SDL_CreateWindow("Super Luigi Bros.", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 400, SDL_WINDOW_SHOWN);
    SDL_Surface* ico = SDL_LoadBMP("Ressources/Louigi.bmp");
    SDL_SetWindowIcon(this->window, ico);
}
