#pragma once
#include "Source/GameObject.h"
#include <random>

class OZombie :
	public GameObject
{
public:
	OZombie(SDL_Renderer* renderer, Vector2D position, std::string name, Scene* scene);
	~OZombie();

	void HandleEvents(SDL_Event* eventHandler) override;
	void Update(double deltaTime) override;
	void Render() override;

	void MoveToNewRandomPosition(double deltaTime);
	bool ResetOutsideOfPlayzone();

	//TODO extract to new 'util' class
	int GetRandomNumber(int min, int max) {
		std::random_device rd;  //Will be used to obtain a seed for the random number engine
		std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
		std::uniform_int_distribution<> dis(min, max);

		//std::cout << "wow\n";
		return dis(gen);
	}

private:
	const float SPEED = 0.05f;
	Vector2D mVel = Vector2D(GetRandomNumber(-1, 1), GetRandomNumber(-1, 1));
	unsigned int lastTime = 0, currentTime;
};
