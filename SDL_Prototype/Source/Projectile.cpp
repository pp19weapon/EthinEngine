#include "Projectile.h"


Projectile::Projectile(SDL_Renderer* renderer, Vector2D spawnPos, Vector2D velocity, float speed, Scene* scene)
	: GameObject("Assets/projectile.png", renderer, spawnPos, "new projectile", scene)
	, mRenderer(renderer)
	, mVelocity(velocity)
	, mSpeed(speed)
{
	ChangeSourceRect(Rectangle(0, 0, 64, 64));
	isCollisionActive = true;
	GetCollider()->tag = "projectile";
	if (velocity == Vector2D(-1, 0)) {
		SetRotation(180);
	}
	else if (velocity == Vector2D(0, -1)) {
		SetRotation(270);
	}
	else if (velocity == Vector2D(0, 1)) {
		SetRotation(90);
	}
	
}


Projectile::~Projectile()
{
	GameObject::~GameObject();
	std::cout << "Projectile destroyed!\n";
}

void Projectile::Update(double deltaTime)
{
	GameObject::Update(deltaTime);

	Move(mVelocity * mSpeed * (float)deltaTime);
	ResetOutsideOfPlayzone();
	CollResult result = GetCollider()->TagCollision("zombie");
	if (result.success) {
		result.hitObj->Delete();
		Delete();
	}
}

void Projectile::Render()
{
	GameObject::Render();

}

void Projectile::ResetOutsideOfPlayzone()
{
	int w, h;
	SDL_GetRendererOutputSize(GetRenderer(), &w, &h);
	Rectangle screen = Rectangle(0, 0, w, h);

	if (!(GetRectangle().hasIntersection(screen))) {
		Delete();
	}
}
