#pragma once
#include "GameObject.h"
#include <random>

class Projectile :
	public GameObject
{
public:
	Projectile(SDL_Renderer* renderer, Vector2D spawnPos, Vector2D velocity, float speed, Scene* scene);
	~Projectile();

	virtual void Update(double deltaTime) override;
	virtual void Render() override;

	void ResetOutsideOfPlayzone();

	int GetRandomNumber(int min, int max) {
		std::random_device rd;  //Will be used to obtain a seed for the random number engine
		std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
		std::uniform_int_distribution<> dis(min, max);

		//std::cout << "wow\n";
		return dis(gen);
	}

private:
	SDL_Renderer* mRenderer;
	Vector2D mVelocity;
	float mSpeed;
};

