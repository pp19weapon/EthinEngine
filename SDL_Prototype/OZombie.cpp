#include "OZombie.h"
#include <cstdlib>
#include <ctime>



OZombie::OZombie(SDL_Renderer* renderer, Vector2D position, std::string name = "new zombie", Scene* scene = nullptr)
	: GameObject("Assets/zombie_tilesheet.jpg", renderer, position, name, scene)
{
	ChangeSourceRect(0, 0, 32, 32);
	SetPosition(Vector2D(GetRandomNumber(0, 600), GetRandomNumber(0, 600)));
	isCollisionActive = true;
	GetCollider()->tag = "zombie";
}


OZombie::~OZombie()
{
	GameObject::~GameObject();
}

void OZombie::HandleEvents(SDL_Event * eventHandler)
{
	GameObject::HandleEvents(eventHandler);
}


void OZombie::Update(double deltaTime)
{
	GameObject::Update(deltaTime);

	MoveToNewRandomPosition(deltaTime);
	if (ResetOutsideOfPlayzone()) {
		MoveToNewRandomPosition(deltaTime);
	}

}

void OZombie::MoveToNewRandomPosition(double deltaTime)
{
	currentTime = SDL_GetTicks();
	if (currentTime > lastTime + GetRandomNumber(1000, 6000)) {
		mVel = Vector2D(GetRandomNumber(-1, 1), GetRandomNumber(-1, 1));
		mVel = mVel * SPEED * (float)deltaTime;
		lastTime = currentTime;
	}
	Move(mVel);
}

bool OZombie::ResetOutsideOfPlayzone()
{
	int w, h;
	SDL_GetRendererOutputSize(GetRenderer(), &w, &h);
	Rectangle screen = Rectangle(0, 0, w, h);

	if (!(GetRectangle().hasIntersection(screen))) {
		SetPosition(Vector2D(GetRandomNumber(0, w), GetRandomNumber(0, h)));
		return true;
	}
	return false;
}

void OZombie::Render()
{
	GameObject::Render();
}
