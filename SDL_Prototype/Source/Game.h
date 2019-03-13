#pragma once

#include "SDL.h"
#include "SDL_image.h"
#include <SDL_mixer.h>

class GameObject;
class Map;
class SceneManager;

class Game
{
public:
	Game();
	~Game();

	void Init(const char* Title, int Xpos, int Ypos, int Width, int Height, bool isFullscreen);
	void HandleEvents();
	void Update(double deltaTime);
	void Render();
	void Clear();

	bool isRunning() { return mRunning; }
	SDL_Renderer* getRenderer() { return mRenderer; }

private:
	bool mRunning;
	SDL_Window* mWindow;
	SDL_Renderer* mRenderer;

	SceneManager* mSceneManager;

};

