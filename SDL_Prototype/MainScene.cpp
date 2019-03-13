#include "MainScene.h"
#include "Source/TextureManager.h"
#include "OPony.h"
#include "OZombie.h"
#include <iostream>


MainScene::MainScene(SDL_Renderer* renderer, SceneManager* sceneManager, int numberOfZombies)
	: Scene::Scene("Main Scene", renderer, sceneManager)
	, mTestMap(Map(renderer))
	, mNumberOfZombiesToSpawn(numberOfZombies)
{
	//SetSceneName("MainScene");
}


MainScene::~MainScene()
{	
	Scene::~Scene();
	delete mPony;
	mPony = nullptr;
	
	std::cout << "Scene destroyed!\n";
}

void MainScene::OnBegin()
{
	Scene::OnBegin();

	mTestMap.Fill(1);
	mPony = new OPony(mRenderer, Vector2D(768, 608), "pony", this);
	AddObjectToScene(mPony);
	for (int zombieCount = 0; zombieCount < mNumberOfZombiesToSpawn; zombieCount++) {
		mZombieEnemies.push_back(new OZombie(mRenderer, Vector2D(), std::string("zombie" + std::to_string(zombieCount)), this));
		AddObjectToScene(mZombieEnemies[zombieCount]);
	}
}

void MainScene::HandleEvents(SDL_Event* eventHandler)
{
	Scene::HandleEvents(eventHandler);
}



void MainScene::Update(double deltaTime)
{
	Scene::Update(deltaTime);


}

void MainScene::Render()
{
	mTestMap.DrawMap();
	Scene::Render();

}
