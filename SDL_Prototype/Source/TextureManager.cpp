#include "TextureManager.h"
#include <SDL_image.h>
#include <iostream>


SDL_Texture* TextureManager::LoadTexture(const char* fileName, SDL_Renderer* renderer)
{
	SDL_Surface* tempSurface = IMG_Load(fileName);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, tempSurface);
	SDL_FreeSurface(tempSurface);

	if (texture == NULL) {
		std::cout << "  WARNING: Could not load texture at " << fileName << "!\n";
	}

	return texture;
}

void TextureManager::SetAlpha(SDL_Texture * texture, Uint8 alpha)
{
	SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_BLEND);
	SDL_SetTextureAlphaMod(texture, alpha);
}

void TextureManager::Draw(SDL_Texture * texture, Rectangle src, Rectangle dest, SDL_Renderer * renderer, double angle = 0)
{
	SDL_RenderCopyEx(renderer, texture, &src.convertToSDLRect(), &dest.convertToSDLRect(), angle, nullptr, SDL_FLIP_NONE);
}
