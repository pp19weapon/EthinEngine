#pragma once

#include <SDL.h>
#include "Rectangle.h"

class TextureManager
{
public:
	static SDL_Texture* LoadTexture(const char* fileName, SDL_Renderer* renderer);
	static void SetAlpha(SDL_Texture* texture, Uint8 alpha);
	static void Draw(SDL_Texture* texture, Rectangle src, Rectangle dest, SDL_Renderer* renderer, double angle);
};

