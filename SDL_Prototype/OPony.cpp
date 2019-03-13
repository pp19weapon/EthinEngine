#include "OPony.h"

#include <iostream>
#include "Source/Projectile.h"



OPony::OPony(SDL_Renderer* renderer, Vector2D position, std::string name, Scene* scene)
	: GameObject("Assets/pony.png", renderer, position, name, scene)
{
	ChangeSourceRect(0, 0, 512, 512);
}


OPony::~OPony()
{
	GameObject::~GameObject();
}

void OPony::HandleEvents(SDL_Event* eventHandler)
{
	if (eventHandler->type == SDL_KEYDOWN && eventHandler->key.repeat == 0) {
		switch (eventHandler->key.keysym.sym)
		{
		case SDLK_w:
			mVelocity.setY(-MOVING_SPEED);
			printf("move\n");
			break;
		case SDLK_s:
			mVelocity.setY(MOVING_SPEED);
			break;
		case SDLK_a:
			mVelocity.setX(-MOVING_SPEED);
			break;
		case SDLK_d:
			mVelocity.setX(MOVING_SPEED);
			break;
		//Firing
		case SDLK_UP:
			GetOwningScene()->AddObjectToScene(new Projectile(GetRenderer(), GetPosition(), Vector2D(0, -1), 2.f, GetOwningScene()));
			break;
		case SDLK_DOWN:
			GetOwningScene()->AddObjectToScene(new Projectile(GetRenderer(), GetPosition(), Vector2D(0, 1), 2.f, GetOwningScene()));
			break;
		case SDLK_LEFT:
			GetOwningScene()->AddObjectToScene(new Projectile(GetRenderer(), GetPosition(), Vector2D(-1, 0), 2.f, GetOwningScene()));
			break;
		case SDLK_RIGHT:
			GetOwningScene()->AddObjectToScene(new Projectile(GetRenderer(), GetPosition(), Vector2D(1, 0), 2.f, GetOwningScene()));
			break;
		default:
			break;
		}
	}
	else if (eventHandler->type == SDL_KEYUP && eventHandler->key.repeat == 0) {
		switch (eventHandler->key.keysym.sym)
		{
		case SDLK_w:
			mVelocity.setY(0);
			break;
		case SDLK_s:
			mVelocity.setY(0);
			break;
		case SDLK_a:
			mVelocity.setX(0);
			break;
		case SDLK_d:
			mVelocity.setX(0);
			break;
		default:
			break;
		}
	}
}

void OPony::Update(double deltaTime)
{
	GameObject::Update(deltaTime);

	Move(mVelocity * (float)deltaTime);
	CollResult result = GetCollider()->TagCollision("zombie");
	if (result.success) {
		Delete();
	}
}

void OPony::Render()
{
	GameObject::Render();
}
