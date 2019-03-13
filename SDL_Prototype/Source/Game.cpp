#include "Game.h"
#include "Map.h"
#include "GameObject.h"
#include <iostream>
#include "SceneManager.h"
#include "Scene.h"
#include "../MainScene.h"
#include <SDL_mixer.h>

Scene* ActiveScene;
MainScene* TestScene;

Game::Game()
	: mRenderer(nullptr)
	, mWindow(nullptr)
	, mSceneManager(nullptr)
{
}
Game::~Game()
{
	delete mRenderer;
	delete mWindow;
	delete mSceneManager;

}

void Game::Init(const char* Title, int Xpos, int Ypos, int Width, int Height, bool isFullscreen)
{
	int flags = 0;
	if (isFullscreen)
		flags = SDL_WINDOW_FULLSCREEN;

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "Subsystem initialized! ..." << std::endl;

		mWindow = SDL_CreateWindow(Title, Xpos, Ypos, Width, Height, flags);
		if (mWindow) {
			std::cout << "Window created!" << std::endl;
		}

		int renderFlags = SDL_RendererFlags::SDL_RENDERER_PRESENTVSYNC;
		mRenderer = SDL_CreateRenderer(mWindow, -1, renderFlags);
		if (mRenderer) {
			//Set render draw color
			SDL_SetRenderDrawColor(mRenderer, 255, 255, 255, 255);
			std::cout << "Renderer created!" << std::endl;
		}

		if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096) < 0) {
			printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
		}

		mRunning = true;
	}
	else {
		std::cout << "Failed to init SDL...." << std::endl;
		mRunning = false;
	}

	mSceneManager = new SceneManager(mRenderer);
	mSceneManager->Init();
}

void Game::HandleEvents()
{
	SDL_Event EventHandler;

	while (SDL_PollEvent(&EventHandler) != 0) {

		if (EventHandler.type == SDL_QUIT) {
			mRunning = false;
		}
		mSceneManager->HandleEvents(&EventHandler);
	}
	
}

void Game::Update(double deltaTime)
{
	mSceneManager->Update(deltaTime);
}

void Game::Render()
{
	SDL_RenderClear(mRenderer);

	mSceneManager->Render();

	SDL_RenderPresent(mRenderer);
}

void Game::Clear()
{
	std::cout << "Game shutting down... \n";
	SDL_DestroyWindow(mWindow);
	SDL_DestroyRenderer(mRenderer);
	SDL_Quit();
}
