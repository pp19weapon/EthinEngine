#pragma once

#include <SDL.h>
#include "Rectangle.h"

class Map
{
public:
	Map(SDL_Renderer* renderer);
	~Map();

	void LoadMap(int map[10][15]);
	void DrawMap();

	void Fill(int textureIndex);

private:
	SDL_Renderer* mRenderer;

	Rectangle mSource = Rectangle(0, 0, 320, 320);
	Rectangle mDest = Rectangle(0, 0, 32, 32);
	SDL_Texture* mDirt;
	SDL_Texture* mGrass;
	SDL_Texture* mWater;

	int mMap[10][15];
};

