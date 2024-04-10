#pragma once
#include "SDL.h"
#include "Object.h"
#include <vector>

class Game
{

public:
	Game();
	~Game();

	void Init(SDL_Renderer* graphics);

	void Update();
	void Draw(SDL_Renderer* graphics);

	void HandleMouseEvents(SDL_Event events);

	static const int SCREEN_WIDTH;
	static const int SCREEN_HEIGHT;
private:

	Sprite* m_Background;

	std::vector<Object*> m_Objects;

};

