#include "texture.h"

Texture::Texture(Renderer* renderer, Surface* surface)
{
	this->texture = SDL_CreateTextureFromSurface(renderer->renderer, surface->surface);
    if (this->texture == NULL) {
        std::cout << "Error creating texture";
        return;
    }
}
