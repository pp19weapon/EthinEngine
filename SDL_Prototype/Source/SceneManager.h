#pragma once
#include <SDL.h>

class vector;
class Scene;
class MainScene;

class SceneManager
{
public:
	SceneManager(SDL_Renderer* renderer);
	~SceneManager();

	void Init();
	void OnBegin();
	void HandleEvents(SDL_Event* eventHandler);
	void Update(double deltaTime);
	void Render();

	//TODO Load scene -1 to exit game
	bool LoadScene(Scene* scene);
	bool LoadScene(int numberOfScene);

	void LoadNextScene();
	void LoadPreviusScene();

	Scene* GetCurrentScene() { return mCurrentScene; };

private:
	int const NUMBER_OF_SCENES = 2;
	int mCurrentSceneNumber = 0;

	SDL_Renderer* mRenderer = nullptr;
	Scene* mCurrentScene = nullptr;

	Scene* mSceneList[2];
};

