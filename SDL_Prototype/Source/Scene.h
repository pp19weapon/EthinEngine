#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <vector>
#include "GameObject.h"
#include "SceneManager.h"

class Scene
{
public:
	Scene(std::string name, SDL_Renderer* renderer, SceneManager* sceneManager);
	virtual ~Scene();

	virtual void OnBegin();
	virtual void HandleEvents(SDL_Event* eventHandler);
	virtual void Update(double deltaTime);
	virtual void Render();


	void SetSceneName(const char* newName) { mSceneName = newName; }
	const char* GetSceneName() { return mSceneName.c_str(); };
	std::vector<GameObject*> GetSceneGameObjects() { return mSceneGameObject; }
	void AddObjectToScene(GameObject* newGameObject);

	SDL_Renderer* mRenderer;
	SceneManager* mSceneManager;
private:
	void DeletePendingObjects();
	void AddPendingObjects();

	std::string mSceneName = "Unnamed Scene";
	std::vector<GameObject*> mSceneGameObject;
	std::vector<GameObject*> mPendingAddingObjects;
};

