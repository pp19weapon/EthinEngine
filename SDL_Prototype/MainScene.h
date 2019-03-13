#pragma once
#include "Source/Scene.h"
#include "Source/Map.h"
#include "Source/Projectile.h"

class OPony;
class OZombie;

class MainScene :
	public Scene
{
public:
	MainScene(SDL_Renderer* renderer, SceneManager* sceneManager, int numberOfZombies);
	~MainScene() override;

	void OnBegin() override;
	void HandleEvents(SDL_Event* eventHandler) override;
	void Update(double deltaTime) override;
	void Render() override;

private:
	Map mTestMap = NULL;
	OPony* mPony = nullptr;

	int mNumberOfZombiesToSpawn = 0;
	
	std::vector<OZombie*> mZombieEnemies;
	
};

