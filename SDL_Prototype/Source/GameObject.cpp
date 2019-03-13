#include "GameObject.h"

GameObject::GameObject(const char* textureSheet = "NULL", SDL_Renderer* renderer = nullptr, Vector2D position = Vector2D(0, 0), std::string name = "new gameobject", Scene* scene = nullptr)
	: mRenderer(renderer)
	, mObjectTexture(TextureManager::LoadTexture(textureSheet, renderer))
	, mPosition(position)
	, mSourceRect(0, 0, 32, 32)
	, mDestinationRect(mPosition.getX(), mPosition.getY(), 32, 32)
	, mName(name)
	, mOwningScene(scene)
	, mDefaultCollider(this)
{
}

GameObject::~GameObject()
{
	SDL_DestroyTexture(mObjectTexture);
}

void GameObject::HandleEvents(SDL_Event* eventHandler)
{
}

void GameObject::Update(double deltaTime)
{
}

void GameObject::Render()
{
	TextureManager::Draw(mObjectTexture, mSourceRect, mDestinationRect, mRenderer, mRotation);
}

void GameObject::SetPosition(Vector2D newPositon)
{
	mPosition = newPositon;

	mDestinationRect.setX(newPositon.getX());
	mDestinationRect.setY(newPositon.getY());
}

void GameObject::SetScale(float scale)
{
	mDestinationRect.setW(mDestinationRect.getW() * scale);
	mDestinationRect.setH(mDestinationRect.getH() * scale);
}

void GameObject::SetScale(Vector2D scale)
{
	mDestinationRect.setW(mDestinationRect.getW() * scale.getX());
	mDestinationRect.setH(mDestinationRect.getH() * scale.getY());
}

bool GameObject::MoveTo(Vector2D pos, float speed)
{
	Vector2D velocity = Vector2D(0, 0);
	if ( pos.getX() > GetPosition().getX()) {
		velocity.setX(1);
	}
	else {
		velocity.setX(-1);
	}

	if (pos.getY() > GetPosition().getY()) {
		velocity.setY(1);
	}
	else {
		velocity.setY(-1);
	}

	if (!((GetPosition() - pos) == Vector2D(10, 10)))
	{
		SetPosition(GetPosition() + velocity * speed);
		return false;
	}
	else {
		return true;
	}
}

void GameObject::ChangeSourceRect(Rectangle rect)
{
	mSourceRect = rect;
}

void GameObject::ChangeSourceRect(int x, int y, int w, int h)
{
	mSourceRect = Rectangle(x, y, w, h);
}
