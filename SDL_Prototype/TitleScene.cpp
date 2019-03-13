#include "TitleScene.h"



TitleScene::TitleScene(SDL_Renderer* renderer, SceneManager* sceneManager)
	: Scene::Scene("Title Scene", renderer, sceneManager)
{
	mTitleTexture = TextureManager::LoadTexture("Assets/EngineTitle.png", mRenderer);
	mMusic = Mix_LoadMUS("Assets/title_music.wav");
}

void TitleScene::OnBegin()
{
	Mix_FadeInMusic(mMusic, -1, 2500);
	mStartTime = 0;
}

void TitleScene::Update(double deltaTime)
{
	Scene::Update(deltaTime);


	DisplayLogo();
}


Uint32 currentTime = SDL_GetTicks();
Uint32 lastTime = 0;
Uint32 TitleScene::DisplayLogo()
{
	static Uint8 alpha = 0;
	static bool wasShown = false;

	currentTime = SDL_GetTicks();
	if (alpha != 255 && !wasShown) {
		//SDL_Delay(50);
		if (currentTime > lastTime + 50) {
			TextureManager::SetAlpha(mTitleTexture, alpha);
			alpha += 5;
			lastTime = currentTime;
			//return 0;
		}
	}
	else if (alpha >= 255) {
		//SDL_Delay(1000);
		if (currentTime > lastTime + 1000) {
			wasShown = true;
			Mix_FadeOutMusic(2550);
			lastTime = currentTime;
			//return 0;
		}
	}

	if (alpha != 0 && wasShown) {
		//SDL_Delay(50);
		if (currentTime > lastTime + 50) {
			alpha -= 5;
			TextureManager::SetAlpha(mTitleTexture, alpha);
			lastTime = currentTime;
			//return 0;
		}
	}
	else if (alpha == 0 && wasShown) {
		mSceneManager->LoadNextScene();
	}

	return 0;
}

void TitleScene::Render()
{
	Scene::Render();
	TextureManager::Draw(mTitleTexture, Rectangle(0, 0, 800, 600), Rectangle(0, 0, 800, 640), mRenderer, 0);
}


TitleScene::~TitleScene()
{
	Scene::~Scene();
	SDL_DestroyTexture(mTitleTexture);
	Mix_FreeMusic(mMusic);
}
