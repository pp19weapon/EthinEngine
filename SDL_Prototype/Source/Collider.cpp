#include "Collider.h"
#include "GameObject.h"
#include "Scene.h"


Collider::Collider(GameObject* owner)
	: mOwner(owner)
	, collisionBox(owner->GetRectangle())
{
}


Collider::~Collider()
{
}

bool Collider::AABBCollision(GameObject * other)
{
	if (collisionBox.hasIntersection(other->GetCollider()->collisionBox)) {
		if (mOwner->isCollisionActive && other->isCollisionActive) {
			return true;
		}
	}
	return false;
}

CollResult Collider::TagCollision(std::string tag)
{
	std::vector<GameObject*> objects = mOwner->GetOwningScene()->GetSceneGameObjects();
	for (std::vector<GameObject*>::iterator object = objects.begin(); object != objects.end(); ++object) {
		if (mOwner->GetRectangle().hasIntersection((*object)->GetRectangle())) {
			if ((*object)->isCollisionActive) {
				if ((*object)->GetCollider()->tag == tag) {
					CollResult newResult;
					newResult.success = true;
					newResult.objPos = (*object)->GetPosition();
					newResult.hitObj = *object;
					return newResult;
				}
			}
		}
	}
	CollResult fail;
	fail.success = false;
	return fail;
}
