#pragma once
#include "Source/Scene.h"
#include <SDL_mixer.h>
class TitleScene :
	public Scene
{
public:
	TitleScene(SDL_Renderer* renderer, SceneManager* sceneManager);

	void OnBegin() override;
	void Update(double deltaTime) override;
	void Render() override;

	Uint32 DisplayLogo();

	~TitleScene();

private:
	SDL_Texture* mTitleTexture;
	Mix_Music* mMusic = nullptr;
	Uint32 mStartTime;
};

