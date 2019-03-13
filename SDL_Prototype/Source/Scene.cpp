#include "Scene.h"


Scene::Scene(std::string name = "Unnamed Scene", SDL_Renderer* renderer = nullptr, SceneManager* sceneManager = nullptr)
	: mRenderer(renderer)
	, mSceneName(name)
	, mSceneManager(sceneManager)
{
}


Scene::~Scene()
{
	//Delete all the game objects in the scene
	std::vector<GameObject*>::iterator object = mSceneGameObject.begin();
	for (; object != mSceneGameObject.end();) {
		delete *object;
		*object = nullptr;
		object = mSceneGameObject.erase(object);
	}
	DeletePendingObjects();
}

void Scene::OnBegin()
{
	
}

void Scene::HandleEvents(SDL_Event* eventHandler)
{
	for (std::vector<GameObject*>::iterator object = mSceneGameObject.begin(); object != mSceneGameObject.end(); ++object) {
		(*object)->HandleEvents(eventHandler);
	}
}


void Scene::Update(double deltaTime)
{
	AddPendingObjects();
	for (std::vector<GameObject*>::iterator object = mSceneGameObject.begin(); object != mSceneGameObject.end(); ++object) {
		if (((*object)->canUpdate) && ((*object) != nullptr)) {
			(*object)->Update(deltaTime);
		}
	}
}

void Scene::Render()
{
	for (std::vector<GameObject*>::iterator object = mSceneGameObject.begin(); object != mSceneGameObject.end(); ++object) {
		if ((*object)->isRendering && (*object != nullptr)) {
			(*object)->Render();
		}
	}
	DeletePendingObjects();
}

void Scene::AddObjectToScene(GameObject * newGameObject)
{
	mPendingAddingObjects.push_back(newGameObject);
	std::cout << newGameObject->GetName() << " pending addition to " << GetSceneName() << " scene.\n";
}

void Scene::DeletePendingObjects()
{
	for (std::vector<GameObject*>::iterator object = mSceneGameObject.begin(); object != mSceneGameObject.end(); ) {
		if ((*object)->pendingDelete) {
			delete *object;
			*object = nullptr;
			object = mSceneGameObject.erase(object);
		}
		else {
			++object;
		}
	}
}

void Scene::AddPendingObjects()
{
	for (std::vector<GameObject*>::iterator object = mPendingAddingObjects.begin(); object != mPendingAddingObjects.end(); ) {
		mSceneGameObject.push_back((*object));
		printf("%s was added to %s. \n", (*object)->GetName().c_str(), GetSceneName());
		object = mPendingAddingObjects.erase(object);
	}
}