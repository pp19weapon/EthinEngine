#pragma once
#include "Source/GameObject.h"
class OPony :
	public GameObject
{
public:
	OPony(SDL_Renderer* renderer, Vector2D position, std::string name, Scene* scene);
	~OPony();

	void HandleEvents(SDL_Event* eventHandler) override;
	void Update(double deltaTime) override;
	void Render() override;

private:
	Vector2D mVelocity;
	
	float const MOVING_SPEED = 0.5f;

};

