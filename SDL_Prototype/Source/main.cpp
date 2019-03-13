#include <SDL.h>
#include "Game.h"


//Screen dimension constants
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 640;
const char* TITLE = "Survival prototype v0.1";
const bool FULLSCREEN = false;
const int FPS_CAP = 200;

Game* RunningGame = nullptr;

int main(int argc, char* args[])
{
	RunningGame = new Game();
	RunningGame->Init(TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, FULLSCREEN);

	int frameDelay = 1000 / FPS_CAP;
	Uint32 frameStart;
	int frameTime;

	//Calc DeltaTime
	Uint64 now = SDL_GetPerformanceCounter();
	Uint64 last = 0;
	double deltaTime = 0;

	while (RunningGame->isRunning()) {

		frameStart = SDL_GetTicks();

		last = now;
		now = SDL_GetPerformanceCounter();
		deltaTime = (double)((now - last) * 1000 / (double)SDL_GetPerformanceFrequency());

		//Mainframe
		RunningGame->HandleEvents();
		RunningGame->Update(deltaTime);
		RunningGame->Render();

		//Limit FPS to FPS_CAP
		frameTime = SDL_GetTicks() - frameStart;
		if (frameDelay > frameTime) {
			SDL_Delay(frameDelay - frameTime);
		}
	}
	
	RunningGame->Clear();

	return 0;
}