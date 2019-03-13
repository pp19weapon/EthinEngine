#pragma once
#include <string>
#include "Rectangle.h"

class GameObject;

struct CollResult {
	bool success = false;
	GameObject* hitObj = nullptr;
	Vector2D objPos;
};

class Collider
{
public:
	Collider(GameObject* owner);
	~Collider();

	std::string tag = "default";
	Rectangle collisionBox;

private:
	GameObject* mOwner;

public:
	bool AABBCollision(GameObject* other);
	CollResult TagCollision(std::string tag);
};

