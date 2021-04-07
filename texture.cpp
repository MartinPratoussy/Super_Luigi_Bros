#include "texture.h"

Texture::Texture(Renderer* renderer, Surface* surface)
{
	this->texture = SDL_CreateTextureFromSurface(renderer->renderer, surface->surface);
    if (this->texture == NULL) {
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Error creating texture\n");
        return;
    }
}
