#include "SceneManager.h"
#include <iostream>
#include <vector>
#include "Scene.h"
#include "../MainScene.h"
#include "../TitleScene.h"



SceneManager::SceneManager(SDL_Renderer* renderer)
	: mRenderer(renderer)
	, mSceneList()
{
}


SceneManager::~SceneManager()
{
}

void SceneManager::Init()
{
	mSceneList[0] = new TitleScene(mRenderer, this);
	mSceneList[1] = new MainScene(mRenderer, this, 5);
	LoadScene(mCurrentSceneNumber);
}

void SceneManager::OnBegin()
{
	if (mCurrentScene != nullptr)
	mCurrentScene->OnBegin();
}

void SceneManager::HandleEvents(SDL_Event* eventHandler)
{
	if (mCurrentScene != nullptr)
	mCurrentScene->HandleEvents(eventHandler);
}

void SceneManager::Update(double deltaTime)
{
	if (mCurrentScene != nullptr)
	mCurrentScene->Update(deltaTime);
}

void SceneManager::Render()
{
	if (mCurrentScene != nullptr)
	mCurrentScene->Render();
}

bool SceneManager::LoadScene(Scene * scene)
{
	if (mCurrentScene != nullptr) {
		mCurrentScene->~Scene();
		delete mCurrentScene;
		mCurrentScene = nullptr;
	}
	mCurrentScene = scene;
	if (mCurrentScene == nullptr) {
		std::cout << "Scene(" << mCurrentScene->GetSceneName() << ") failed to load!\n";
		return false;
	}
	else {
		OnBegin();
		std::cout << mCurrentScene->GetSceneName() << "(" << mCurrentSceneNumber << ") was loaded.\n";
		return true;
	}
}

bool SceneManager::LoadScene(int numberOfScene)
{
	if (mCurrentScene != nullptr) {
		mCurrentScene->~Scene();
		delete mCurrentScene;
		mCurrentScene = nullptr;
	}
	if (numberOfScene >= 0 && numberOfScene < NUMBER_OF_SCENES) {
		mCurrentScene = mSceneList[numberOfScene];

		if (mCurrentScene == nullptr) {
			std::cout << "Scene(" << mCurrentScene->GetSceneName() << ") failed to load!\n";
			return false;
		}
		else {
			OnBegin();
			std::cout << mCurrentScene->GetSceneName() << "(" << mCurrentSceneNumber << ") was loaded.\n";
			return true;
		}
	}
	else {
		std::cout << "Failed to load scene! Scene with number " << numberOfScene << " is not registered.\n";
		_CrtDumpMemoryLeaks();
		return false;
	}
}

void SceneManager::LoadNextScene()
{
	if (LoadScene(mCurrentSceneNumber + 1)) {
		mCurrentSceneNumber++;
	}
}

void SceneManager::LoadPreviusScene()
{
	if (LoadScene(mCurrentSceneNumber - 1)) {
		mCurrentSceneNumber--;
	}
}
