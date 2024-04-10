#pragma once
#include <SDL.h>
#include "Sprite.h"

class NyanCat
{
public:
	NyanCat();
	virtual ~NyanCat();

	void Init(SDL_Renderer* graphics);
	void Draw(SDL_Renderer* graphics);
	void Update();

private:

	Sprite* m_Sprite;
};