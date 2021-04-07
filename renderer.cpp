#include "renderer.h"

Renderer::Renderer(Window* window)
{
    this->renderer = SDL_CreateRenderer(window->window, -1, SDL_RENDERER_ACCELERATED);

    SDL_RendererInfo infoRenderer;
    SDL_GetRendererInfo(this->renderer, &infoRenderer);
    if (infoRenderer.flags & SDL_RENDERER_ACCELERATED) SDL_Log("GPU rendering enabled...");
    if (infoRenderer.flags & SDL_RENDERER_SOFTWARE) SDL_Log("CPU rendering enabled...");
    if (infoRenderer.flags & SDL_RENDERER_TARGETTEXTURE) SDL_Log("Rendering is allowed on textures...");
}

Renderer::~Renderer()
{
    SDL_DestroyRenderer(this->renderer);
}
