#include "Map.h"
#include <SDL.h>
#include "TextureManager.h"
#include <iostream>


//Default map
int level1[10][15] = { 
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

Map::Map(SDL_Renderer* renderer)
	: mDirt(TextureManager::LoadTexture("Assets/dirt.png", renderer))
	, mGrass(TextureManager::LoadTexture("Assets/grass.png", renderer))
	, mWater(TextureManager::LoadTexture("Assets/water.png", renderer))
	, mRenderer(renderer)
{
	mSource = Rectangle(0, 0, 320 ,320);
	mDest = Rectangle(0, 0, 64, 64);
	LoadMap(level1);
}


Map::~Map()
{
	SDL_DestroyTexture(mDirt);
	SDL_DestroyTexture(mGrass);
	SDL_DestroyTexture(mWater);
	std::cout << "Map deleted!\n";
}

void Map::LoadMap(int map[10][15])
{
	for (int row = 0; row < 10; row++) {
		for (int column = 0; column < 15; column++) {
			mMap[row][column] = map[row][column];
		}
	}
}

void Map::DrawMap()
{
	int type = 0;

	for (int row = 0; row < 10; row++) {
		for (int column = 0; column < 15; column++) {
			type = mMap[row][column];

			mDest.setX (column * 64);
			mDest.setY (row * 64);

			switch (type)
			{
			case 0:
				TextureManager::Draw(mDirt, mSource, mDest, mRenderer, 0);
				break;
			case 1:
				TextureManager::Draw(mGrass, mSource, mDest, mRenderer, 0);
				break;
			case 2:
				TextureManager::Draw(mWater, mSource, mDest, mRenderer, 0);
				break;
			default:
				break;
			}
		}
	}
}

void Map::Fill(int textureIndex)
{
	for (int row = 0; row < 10; row++) {
		for (int column = 0; column < 15; column++) {
			mMap[row][column] = textureIndex;
		}
	}
}
