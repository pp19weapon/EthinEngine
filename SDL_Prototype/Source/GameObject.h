#pragma once
#include "SDL.h"
#include "Rectangle.h"
#include "Collider.h"
#include "Scene.h"
#include "TextureManager.h"
#include <iostream>

class Scene;

class GameObject
{
public:
	GameObject(const char* textureSheet, SDL_Renderer* renderer, Vector2D position, std::string name, Scene* scene);
	~GameObject();

	virtual void HandleEvents(SDL_Event* eventHandler);
	virtual void Update(double deltaTime);
	virtual void Render();

	Vector2D GetPosition() { return Vector2D(mDestinationRect.getX(), mDestinationRect.getY()); }
	void SetPosition(Vector2D newPosition);
	void SetScale(float scale);
	void SetScale(Vector2D scale);
	void SetRotation(double rot) { mRotation = rot; }

	//Return true when reached target
	//NOT RECOMMENDED!! ONLY USE IN UPDATE()
	bool MoveTo(Vector2D pos, float speed);

	void ChangeSourceRect(Rectangle rect);
	void ChangeSourceRect(int x, int y, int w, int h);

	SDL_Renderer* GetRenderer() { return mRenderer; }
	Rectangle GetRectangle() { return mDestinationRect; }
	std::string GetName() { return mName; }
	Scene* GetOwningScene() { return mOwningScene;}
	Collider* GetCollider() { return &mDefaultCollider; }
	SDL_Texture* GetTexture() { return mObjectTexture; }

	void Move(Vector2D velocity) { SetPosition(GetPosition() + velocity); }

	// Determines if the object should update
	bool canUpdate = true;
	// Determines it the object should be rendered
	bool isRendering = true;

	bool isCollisionActive = true;

	void SetActive(bool shouldBeActive) { canUpdate = shouldBeActive; isRendering = shouldBeActive; }
	void Delete() { pendingDelete = true; };
	bool pendingDelete = false;

private:
	Vector2D mPosition;
	double mRotation = 0;

	std::string mName;
	SDL_Texture* mObjectTexture;
	Rectangle mSourceRect;
	Rectangle mDestinationRect;
	SDL_Renderer* mRenderer;
	Scene* mOwningScene;
	Collider mDefaultCollider;
};

