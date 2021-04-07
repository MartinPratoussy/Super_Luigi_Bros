#include "window.h"

Window::Window()
{
    SDL_Init(SDL_INIT_EVERYTHING);

    this->window = SDL_CreateWindow("Super Luigi Bros.", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 400, SDL_WINDOW_SHOWN);
    this->windowSurface = SDL_GetWindowSurface(this->window);
}

Window::~Window()
{
    SDL_FreeSurface(this->windowSurface);
    SDL_DestroyWindow(this->window);
    this->windowSurface = NULL;
}
