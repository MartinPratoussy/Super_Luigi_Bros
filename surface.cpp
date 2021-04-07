#include "surface.h"

Surface::Surface(const char* path)
{
	SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Loading %s", path);
	this->surface = IMG_Load(path);
}
